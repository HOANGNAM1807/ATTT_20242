#include "io_utils.h"
#include <fstream>

// Đọc toàn bộ nội dung file và trả về dưới dạng chuỗi
std::string read_file(const std::string& filename) {
    std::ifstream in(filename);
    return std::string((std::istreambuf_iterator<char>(in)),
                       std::istreambuf_iterator<char>());
}

// Ghi chuỗi nội dung vào file (ghi đè nếu file đã tồn tại)
void write_file(const std::string& filename, const std::string& content) {
    std::ofstream out(filename);
    out << content;
}
