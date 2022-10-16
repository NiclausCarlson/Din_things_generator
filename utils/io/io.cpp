#include "io.h"
#include <fstream>

namespace io {
    void write_to_file(const html_generator::Element *str,
                       const std::string &file_name) {
        std::ofstream fout;
        fout.open(file_name);
        fout << str->gen();
        fout.close();
    }
}
