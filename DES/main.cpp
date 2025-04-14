#include <iostream>     
#include <fstream>      
#include "des.h"        
#include "io_utils.h"   

// Hàm main - điểm bắt đầu của chương trình
int main() {
    std::cout << "Program started!" << std::endl;

    // Các file sẽ sử dụng
    std::string inputFilename = "input.txt";
    std::string encryptedFilename = "encrypted.txt";
    std::string decryptedFilename = "decrypted.txt";

    // Đọc nội dung văn bản từ file input.txt
    std::string inputText = read_file(inputFilename); 
    if (inputText.empty()) {
        std::cout << "Failed to read input.txt or it's empty!" << std::endl;
        return 1; 
    }

    // Khóa dùng cho thuật toán DES (phải đúng 8 byte)
    std::string key = "secret_k"; // 8 ký tự = 8 byte

    // Mã hóa văn bản bằng DES
    std::string encryptedText = des_encrypt(inputText, key); 

    // Ghi kết quả mã hóa vào file encrypted.txt
    write_file(encryptedFilename, encryptedText); 

    // Giải mã văn bản đã mã hóa
    std::string decryptedText = des_decrypt(encryptedText, key);

    // Ghi kết quả giải mã vào file decrypted.txt
    write_file(decryptedFilename, decryptedText); 

    std::cout << "Done! Check encrypted.txt and decrypted.txt" << std::endl;
    return 0; 
}
