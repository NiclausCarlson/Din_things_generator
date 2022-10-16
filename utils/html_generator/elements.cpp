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
}
