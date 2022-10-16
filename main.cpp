#include <iostream>
#include "utils/html_generator/elements.h"

int main() {
    using namespace html_generator;
    Body<Table> body{
            Table{{{"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}},
                  {"A", "B", "C"},
                  {"D", "F", "G"}}
    };
    std::cout << body.gen();
    return 0;
}
