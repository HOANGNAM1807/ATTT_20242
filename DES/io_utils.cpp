#include "io_utils.h"
#include <fstream>

std::string read_file(const std::string& filename) {
    std::ifstream in(filename);
    return std::string((std::istreambuf_iterator<char>(in)),
                       std::istreambuf_iterator<char>());
}

void write_file(const std::string& filename, const std::string& content) {
    std::ofstream out(filename);
    out << content;
}
