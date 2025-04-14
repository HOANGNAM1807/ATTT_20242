#ifndef IO_UTILS_H
#define IO_UTILS_H

#include <string>

// Đọc toàn bộ nội dung từ file và trả về dưới dạng chuỗi
std::string read_file(const std::string& filename);

// Ghi chuỗi nội dung vào file
void write_file(const std::string& filename, const std::string& content);

#endif
