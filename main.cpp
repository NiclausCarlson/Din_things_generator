#include <iostream>
#include "utils/html_generator/elements.h"

int main() {
    using namespace html_generator;
    Body<Header, Paragraf, Header, Div<Header, Paragraf>> body{
            Header{"t", 1},
            Paragraf{"F"},
            Header{"ssf", 2},
            Div<Header, Paragraf>{std::nullopt,
                                  Header{"ssf", 2},
                                  Paragraf{"F"}}
    };
    std::cout << body.gen();
    return 0;
}
