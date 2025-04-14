#ifndef DES_H
#define DES_H

#include <string>

// Mã hóa chuỗi inputText bằng thuật toán DES với key cho trước
std::string des_encrypt(const std::string& inputText, const std::string& key);

// Giải mã chuỗi encryptedText bằng thuật toán DES với key cho trước
std::string des_decrypt(const std::string& encryptedText, const std::string& key);

#endif
