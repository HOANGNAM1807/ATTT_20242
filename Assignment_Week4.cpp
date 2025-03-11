#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Thuật toán sắp xếp khóa (Key Scheduling Algorithm - KSA)
vector<int> ksa(const string &key) {
    vector<int> S(256);
    for (int i = 0; i < 256; i++) S[i] = i;

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key.length()]) % 256;
        swap(S[i], S[j]);
    }
    return S;
}

// Thuật toán sinh số giả ngẫu nhiên (Pseudo-Random Generation Algorithm - PRGA)
vector<int> prga(vector<int> &S, int length) {
    vector<int> keystream;
    int i = 0, j = 0;
    for (int k = 0; k < length; k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        keystream.push_back(S[(S[i] + S[j]) % 256]);
    }
    return keystream;
}

// Hàm mã hóa RC4
vector<int> rc4_encrypt(const string &plaintext, const string &key) {
    vector<int> S = ksa(key);             // Tạo mảng hoán vị từ khóa mật
    vector<int> keystream = prga(S, plaintext.length()); // Sinh dòng khóa

    vector<int> ciphertext;
    for (size_t i = 0; i < plaintext.length(); i++) {
        ciphertext.push_back(plaintext[i] ^ keystream[i]); // XOR từng ký tự
    }

    // In ra dòng khóa
    cout << "Dòng khóa (keystream): ";
    for (int ks : keystream) cout << ks << " ";
    cout << endl;

    // In ra bản mã dạng số nguyên
    cout << "Bản mã (decimal): ";
    for (int c : ciphertext) cout << c << " ";
    cout << endl;

    // In ra bản mã dạng hex
    cout << "Bản mã (hex): ";
    for (int c : ciphertext) cout << hex << setw(2) << setfill('0') << c << " ";
    cout << endl;

    return ciphertext;
}

int main() {
    string key = "my_secret_key";  // Khóa mật do người dùng định nghĩa
    string plaintext = "Hanoi University of Science and Technology"; // Văn bản cần mã hóa

    rc4_encrypt(plaintext, key);

    return 0;
}
