#include "Cryptography.h"
#include "Auxiliary.h"
#include <locale>

int main() {
    // TODO stworzyæ aplikacjê, która szyfruje i rozszyfrowuje ró¿ne wiadomoœci
    // ma mieæ opcjê wyboru alfabetu;
    // ma mieæ opcjê wyboru szyfru i miejsca na odpowiednie klucze
    // ma mieæ opcjê na wpisanie wiadomoœci i przyciski od (de)szyfrowania wiadomoœci
    
    std::locale::global(std::locale("en_US.UTF-8"));
    std::wstring alphabet = readAlphabetFromFile("polish_alphabet.txt");
    std::map<wchar_t, int> alphabet_map = getAlphabetMapFromAlphabet(alphabet);
    std::wcout << alphabet << "\n";
    std::wstring message = L"coœ - oh";
    int key = 11;
    std::wstring coded_message = Ceaser_cipher(alphabet, alphabet_map, message, key);
    std::wcout << "message: " << message << "\n";
    std::wcout << "ceasar message: " << coded_message << "\n";
    std::wcout << "de-ceasar(ed) message: " << Ceaser_decipher(alphabet, alphabet_map, coded_message, key) << "\n";
    int key_1 = 1, key_2 = 1;
    std::wstring aff_message = affine_cipher(alphabet, alphabet_map, message, key_1, key_2);
    std::wcout << "affine message: " << aff_message << '\n';
    std::wcout << "de-affine(d) message: " << affine_decipher(alphabet, alphabet_map, aff_message, key_1, key_2);
}