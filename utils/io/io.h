#include <string>

#include "../html_generator/elements.h"

namespace io {
    void write_to_file(const html_generator::Element* str,
                       const std::string &file_name = "result.html");
}
