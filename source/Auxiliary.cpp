#include "Auxiliary.h"

std::vector<int> message_to_numbers(const std::map<wchar_t, int>& alphabet_map, const std::wstring& message) {
    std::vector<int> numbers;
    for (wchar_t character : message) {
        numbers.push_back(alphabet_map.at(character));
    }
    return numbers;
}

std::wstring numbers_to_message(const std::wstring& alphabet, const std::vector<int>& numbers) {
    std::wstring message;
    for (int number : numbers) {
        if (!number) continue;
        message.push_back(alphabet[number - 1]);
    }
    return message;
}

void saveAlphabetToFile(std::string file_name) {
    std::map<char, int> alphabetMap;
    int counter = 0;
    // Populate the map
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        alphabetMap[ch] = counter;
        counter += 2;
    }
    counter = 1;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        alphabetMap[ch] = counter;
        counter += 2;
    }

    // Save the map to a file
    std::ofstream outFile(file_name);
    if (outFile.is_open()) {
        for (const auto& entry : alphabetMap) {
            outFile << entry.first << " " << entry.second << std::endl;
        }
        outFile.close();
        std::cout << "Map saved to file successfully." << std::endl;
    }
    else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

std::wstring readAlphabetFromFile(std::string file_name) {
    std::wstring alphabet;
    std::wifstream inputFile(file_name);
    inputFile.imbue(std::locale());
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return alphabet;
    }

    wchar_t character;
    while (inputFile >> character) {
        alphabet.push_back(character);
    }

    inputFile.close();
    return alphabet;
}

std::map<wchar_t, int> getAlphabetMapFromAlphabet(std::wstring alphabet) {
    int position = 1;
    std::map<wchar_t, int> alphabet_map;
    for (wchar_t character : alphabet) {
        alphabet_map[character] = position;
        position++;
    }
    return alphabet_map;
}

std::map<wchar_t, int> readAlphabetMapFromFile(std::string file_name) {
    std::map<wchar_t, int> charMap;

    std::locale::global(std::locale("en_US.UTF-8"));
    std::wifstream inputFile(file_name);
    inputFile.imbue(std::locale());

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return charMap;
    }

    wchar_t character;
    int number;

    while (inputFile >> character >> number) {
        charMap[character] = number;
    }

    inputFile.close();
    return charMap;
}

std::wstring extractAlphabet(std::map<wchar_t, int> alphabet_map) {
    std::wstring alphabet; 
    for (auto pair : alphabet_map) {
        alphabet.push_back(pair.first);
    }
    return alphabet;
}

int LCM(int a, int b) {
    int lower_number = a, higher_number = b, upper_limit = a * b;
    if (a > b) lower_number = b, higher_number = a;
    int multiple = higher_number;
    while (multiple < upper_limit) {
        if (!(multiple % lower_number)) {
            return multiple;
        }
        multiple += higher_number;
    }
    return multiple;
}

int GCD(int a, int b) {
    return a * b / LCM(a, b);
}