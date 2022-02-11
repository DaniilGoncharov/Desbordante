#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "CSVParser.h"
#include "Itemset.h"

class TransactionalData {
private:
    std::vector<std::string> itemUniverse;
    std::unordered_map<unsigned, Itemset> transactions; //пока что map, т.к. не знаем общее количество транзкзцйи
public:
    TransactionalData() = delete;
    TransactionalData(TransactionalData const&) = delete;
    TransactionalData& operator=(TransactionalData const&) = delete;

    TransactionalData(std::vector<std::string>&& itemUniverse, std::unordered_map<unsigned, Itemset>&& transactions)
        : itemUniverse(std::move(itemUniverse)), transactions(std::move(transactions)) {}

    std::vector<std::string> const& getItemUniverse() const noexcept { return itemUniverse; }
    std::unordered_map<unsigned, Itemset> const& getTransactions() const noexcept { return transactions; }

    size_t    getUniverseSize() const noexcept { return itemUniverse.size(); }
    size_t getNumTransactions() const noexcept { return transactions.size(); }

    static std::unique_ptr<TransactionalData> createFrom(CSVParser& fileInput);
};