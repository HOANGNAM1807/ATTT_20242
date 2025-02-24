#include <iostream>
#include <vector>

using namespace std;

// Hàm tạo bảng Playfair từ khóa
void generatePlayfairSquare(string key, char square[5][5]) {
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string keyString = "";
    bool used[26] = {false};

    // Chuẩn hóa khóa (loại bỏ ký tự trùng lặp và thay J -> I)
    for (char &ch : key) {
        if (ch == 'J') ch = 'I';
        if (!used[ch - 'A']) {
            keyString += ch;
            used[ch - 'A'] = true;
        }
    }

    // Thêm các ký tự còn lại trong bảng chữ cái
    for (char ch : alphabet) {
        if (!used[ch - 'A']) {
            keyString += ch;
            used[ch - 'A'] = true;
        }
    }

    // Tạo bảng 5x5
    int index = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            square[i][j] = keyString[index++];
}

// Hàm tìm vị trí của ký tự trong bảng Playfair
void findPosition(char letter, char square[5][5], int &row, int &col) {
    for (row = 0; row < 5; row++)
        for (col = 0; col < 5; col++)
            if (square[row][col] == letter)
                return;
}

// Hàm chuẩn bị văn bản (chia thành cặp chữ cái)
string prepareText(string text) {
    string preparedText = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch == 'J') ch = 'I';
        if (isalpha(ch)) preparedText += ch;
    }

    // Chia thành cặp chữ cái
    string pairs = "";
    for (int i = 0; i < preparedText.length(); i++) {
        char a = preparedText[i];
        char b = (i + 1 < preparedText.length() && preparedText[i] != preparedText[i + 1]) ? preparedText[i + 1] : 'X';
        pairs += a;
        pairs += b;
        if (b != 'X') i++;
    }

    if (pairs.length() % 2 != 0) pairs += 'X'; // Nếu còn dư một chữ cái, thêm 'X'
    return pairs;
}

// Hàm mã hóa Playfair
string encryptPlayfair(string text, char square[5][5]) {
    string preparedText = prepareText(text);
    string encryptedText = "";

    for (int i = 0; i < preparedText.length(); i += 2) {
        char a = preparedText[i];
        char b = preparedText[i + 1];

        int row1, col1, row2, col2;
        findPosition(a, square, row1, col1);
        findPosition(b, square, row2, col2);

        if (row1 == row2) { // Cùng hàng
            encryptedText += square[row1][(col1 + 1) % 5];
            encryptedText += square[row2][(col2 + 1) % 5];
        } else if (col1 == col2) { // Cùng cột
            encryptedText += square[(row1 + 1) % 5][col1];
            encryptedText += square[(row2 + 1) % 5][col2];
        } else { // Hình chữ nhật
            encryptedText += square[row1][col2];
            encryptedText += square[row2][col1];
        }
    }

    return encryptedText;
}

// Hàm chính để chạy chương trình
int main() {
    string key, text;
    char square[5][5];

    cout << "Nhap tu khoa: ";
    cin >> key;

    cout << "Nhap ban ro: ";
    cin >> text;

    generatePlayfairSquare(key, square);
    string encryptedText = encryptPlayfair(text, square);

    cout << "Ban ma: " << encryptedText << endl;
    return 0;
}
