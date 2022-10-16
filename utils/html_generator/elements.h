#pragma once

#include <sstream>
#include <optional>
#include <tuple>

namespace html_generator {
    struct Element {
        virtual std::string gen() const = 0;

        virtual ~Element() = default;
    };

    template<typename... T>
    struct Body : public Element {
        const std::tuple<T...> elements;

        explicit Body(T &&... elements) : elements(std::forward<T>(elements)...) {
        }

        std::string gen() const override {
            std::string result = "<!DOCTYPE html>\n"
                                 "<html>\n"
                                 "<body>\n";
            std::apply([&result](const auto &...elem) {
                ((result += elem.gen() + '\n'), ...);
            }, elements);
            result += "</body>\n"
                      "</html>";
            return result;
        }
    };


    template<typename ...T>
    struct Div : public Element {
        const std::optional<std::string> cls;
        const std::tuple<T...> elements;

        explicit Div(std::optional<std::string> &&cls, T &&... elements) : cls(std::move(cls)),
                                                                           elements(std::forward<T>(elements)...) {
        }

        std::string gen() const override {
            std::stringstream ss;
            ss << "<div";
            if (cls)ss << " class=" << *cls << ">\n";
            else ss << ">\n";
            std::apply([&ss](const auto &...elem) {
                ((ss << elem.gen() + '\n'), ...);
            }, elements);
            ss << "</div>";
            return ss.str();
        }
    };

    struct Paragraf : public Element {
        const std::string txt;

        explicit Paragraf(std::string &&txt);

        [[nodiscard]] std::string gen() const override;
    };

    struct Header : public Element {
        const std::string txt;
        const int32_t idx;

        Header(std::string &&txt, int32_t &&idx);

        [[nodiscard]] std::string gen() const override;
    };

}
