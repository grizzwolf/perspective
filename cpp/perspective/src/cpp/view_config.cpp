/******************************************************************************
 *
 * Copyright (c) 2019, the Perspective Authors.
 *
 * This file is part of the Perspective library, distributed under the terms of
 * the Apache License 2.0.  The full license can be found in the LICENSE file.
 *
 */

#include <perspective/view_config.h>

namespace perspective {

t_view_config::t_view_config(std::vector<std::string> row_pivots,
    std::vector<std::string> column_pivots, std::map<std::string, std::string> aggregates,
    std::vector<std::string> columns,
    std::vector<std::tuple<std::string, std::string, t_tscalar>> filter,
    std::vector<std::vector<std::string>> sort)
    : m_row_pivots(row_pivots)
    , m_column_pivots(column_pivots)
    , m_aggregates(aggregates)
    , m_columns(columns)
    , m_filter(filter)
    , m_sort(sort) {}

void
t_view_config::add_filter_term(std::tuple<std::string, std::string, t_tscalar> term) {
    m_filter.push_back(term);
}

} // end namespace perspective

namespace std {
std::ostream&
operator<<(std::ostream& os, const perspective::t_view_config& vc) {
    os << "t_view_config";
    return os;
}
} // end namespace std