#pragma once
#ifndef AUXILIARY_H
#define AUXILIARY_H
#include <string>
#include <map>
#include <fstream>
#include <locale>
#include <iostream>
#include <vector>

std::vector<int> message_to_numbers(const std::map<wchar_t, int>& alphabet_map, const std::wstring& message);
std::wstring numbers_to_message(const std::wstring& alphabet, const std::vector<int>& numbers);
void saveAlphabetToFile(std::string file_name);
std::wstring readAlphabetFromFile(std::string file_name);
std::map<wchar_t, int> getAlphabetMapFromAlphabet(std::wstring alphabet);
std::map<wchar_t, int> readAlphabetMapFromFile(std::string file_name);
std::wstring extractAlphabet(std::map<wchar_t, int> alphabet_map);
int LCM(int a, int b);
int GCD(int a, int b);

#endif