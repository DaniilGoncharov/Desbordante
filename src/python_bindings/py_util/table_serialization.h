#pragma once

#include <memory>

#include <pybind11/pybind11.h>

#include "model/table/column.h"
#include "model/table/column_combination.h"
#include "model/table/relational_schema.h"
#include "model/table/vertical.h"

namespace py = pybind11;

namespace table_serialization {

py::tuple SerializeRelationalSchema(RelationalSchema const* schema);

std::shared_ptr<RelationalSchema const> DeserializeRelationalSchema(py::tuple t);

py::tuple SerializeVertical(Vertical const& v);

Vertical DeserializeVertical(py::tuple t, RelationalSchema const* schema);

py::tuple SerializeColumn(Column const& c);

Column DeserializeColumn(py::tuple t, RelationalSchema const* schema);
}  // namespace table_serialization
