#ifndef IO_UTILS_H
#define IO_UTILS_H

#include <string>

std::string read_file(const std::string& filename);
void write_file(const std::string& filename, const std::string& content);

#endif
