#include <iostream>
#include <fstream>
#include "des.h"
#include "io_utils.h"

int main() {
    std::cout << "Program started!" << std::endl;

    std::string inputFilename = "input.txt";
    std::string encryptedFilename = "encrypted.txt";
    std::string decryptedFilename = "decrypted.txt";

    // Sửa tên hàm cho đúng
    std::string inputText = read_file(inputFilename); // sửa từ readFile thành read_file
    if (inputText.empty()) {
        std::cout << "Failed to read input.txt or it's empty!" << std::endl;
        return 1;
    }

    std::string key = "secret_k"; // 8 bytes

    std::string encryptedText = des_encrypt(inputText, key); // sửa từ desEncrypt thành des_encrypt
    write_file(encryptedFilename, encryptedText); // sửa từ writeFile thành write_file

    std::string decryptedText = des_decrypt(encryptedText, key); // sửa từ desDecrypt thành des_decrypt
    write_file(decryptedFilename, decryptedText); // sửa từ writeFile thành write_file

    std::cout << "Done! Check encrypted.txt and decrypted.txt" << std::endl;
    return 0;
}
