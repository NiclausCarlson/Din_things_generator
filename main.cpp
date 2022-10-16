#include <iostream>
#include "utils/html_generator/elements.h"
#include "utils/io/io.h"

int main() {
    using namespace html_generator;
    Body<Table> body{
            Table{{{"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}},
                  {"A", "B", "C"},
                  {"D", "F", "G"}}
    };
    io::write_to_file(&body);
    return 0;
}
