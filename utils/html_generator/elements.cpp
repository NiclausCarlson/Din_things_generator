#include "elements.h"

namespace html_generator {
    std::string html_generator::Header::gen() const {
        std::stringstream ss;
        ss << "<h" << std::to_string(idx) << "> ";
        ss << txt;
        ss << " </h" << std::to_string(idx) << ">";
        return ss.str();
    }

    Header::Header(std::string &&txt, int32_t &&idx) : txt(std::move(txt)), idx(idx) {
    }

    std::string Paragraf::gen() const {
        return "<p> " + txt + " </p>";
    }

    Paragraf::Paragraf(std::string &&txt) : txt(std::move(txt)) {
    }

    Table::Table(const Table::TableType &table, const TowTyper &row_headers,
                 const TowTyper &column_headers) : table(table), row_headers(row_headers),
                                                   column_headers(column_headers) {
    }

    Table::Table(Table::TableType &&table, TowTyper &&row_headers,
                 TowTyper &&column_headers) : table(std::move(table)), row_headers(std::move(row_headers)),
                                              column_headers(std::move(column_headers)) {
    }

    std::string Table::gen() const {
        auto raw_header = row_headers.cbegin();
        auto column_header = column_headers.cbegin();

        std::stringstream result;
        result << "<table>\n";
        if (!row_headers.empty()) {
            result << "<tr>\n";
            result << "<th></th>\n";
            while (raw_header != row_headers.cend()) {
                result << "<th>" << *(raw_header)++ << "</th>\n";
            }
            result << "</tr>\n";
        }
        for (const auto &raw: table) {
            result << "<tr>\n";
            if (column_header != column_headers.end()) {
                result << "<td>" << *(column_header)++ << "</td>";
            }
            for (const auto &column: raw) {
                result << "<td>" << column << "</td>";
            }
            result << "</tr>\n";
        }
        result << "</table>\n";
        return result.str();
    }
}
