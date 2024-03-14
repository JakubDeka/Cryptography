#include "Cryptography.h"
#include <iostream>
//#include <iostream>

// wiadomoœæ -> ci¹g int -> kodowy ci¹g int -> kodowa wiadomoœæ

std::wstring Ceaser_cipher(const std::wstring& alphabet, std::map<wchar_t, int> alphabet_map, const std::wstring& message, int key) {
    int alphabet_length = alphabet.length();
    std::wstring coded_message;
    for (wchar_t letter : message) {
        int a = alphabet_map[letter];
        if (!a) {
            coded_message.push_back(letter);
            continue;
        }
        int value = a + 2 * key;
        while (value < 0) value += alphabet_length ;
        int modulo_result = value % alphabet_length;
        coded_message.push_back(alphabet[modulo_result - 1]);
    }
    return coded_message;
}

std::wstring Ceaser_decipher(const std::wstring& alphabet, std::map<wchar_t, int> alphabet_map, const std::wstring& message, int key) {
    return Ceaser_cipher(alphabet, alphabet_map, message, -key);
}

std::wstring affine_cipher(const std::wstring& alphabet, std::map<wchar_t, int> alphabet_map, const std::wstring& message, int key_1, int key_2) {
    int alphabet_length = alphabet.length();
    if (!key_1) { std::cout << "key_1 has to be not zero!\n"; return message; }
    if (GCD(key_1, alphabet_length) != 1) {
        std::cout << "Cannot cipher the message with this key! GCD of key_1 and alphabet length has to equal 1!\n";
        return message;
    }
    std::wstring coded_message;
    for (wchar_t letter : message) {
        int a = alphabet_map[letter];
        if (!a) {
            coded_message.push_back(letter);
            continue;
        }
        int value = a * key_1 + 2 * key_2;
        while (value < 0) value += alphabet_length;
        int modulo_result = value % alphabet_length;
        coded_message.push_back(alphabet[modulo_result - 1]);
    }
    return coded_message;
}

std::wstring affine_decipher(const std::wstring& alphabet, std::map<wchar_t, int> alphabet_map, const std::wstring& message, int key_1, int key_2) {
    int alphabet_length = alphabet.length();
    if (!key_1) { std::cout << "key_1 has to be not zero!\n"; return message; }
    if (GCD(key_1, alphabet_length) != 1) {
        std::cout << "Cannot cipher the message with this key! GCD of key_1 and alphabet length has to equal 1!\n";
        return message;
    }
    double key_1_inverse = 1 / double(key_1);
    std::wstring coded_message;
    for (wchar_t letter : message) {
        int a = alphabet_map[letter];
        if (!a) {
            coded_message.push_back(letter);
            continue;
        }
        int value = a - 2 * key_2;
        while (value % key_1 != 0) {
            value += alphabet_length;
        }
        while (value < 0) value += alphabet_length;
        int modulo_result = value / key_1;
        coded_message.push_back(alphabet[modulo_result - 1]);
    }
    return coded_message;
}