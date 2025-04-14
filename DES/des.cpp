#include "des.h"

std::string des_encrypt(const std::string& plaintext, const std::string& key) {
    std::string result = plaintext;
    for (size_t i = 0; i < plaintext.size(); ++i) {
        result[i] ^= key[i % key.size()];
    }
    return result;
}

std::string des_decrypt(const std::string& ciphertext, const std::string& key) {
    std::string result = ciphertext;
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        result[i] ^= key[i % key.size()];
    }
    return result;
}
