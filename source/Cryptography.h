#pragma once
#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include "Auxiliary.h"
#include <string>
#include <map>

std::wstring Ceaser_cipher(const std::wstring& alphabet, std::map<wchar_t, int> alphabet_map, const std::wstring& message, int key);
std::wstring Ceaser_decipher(const std::wstring& alphabet, std::map<wchar_t, int> alphabet_map, const std::wstring& message, int key);
std::wstring affine_cipher(const std::wstring& alphabet, std::map<wchar_t, int> alphabet_map, const std::wstring& message, int key_1, int key_2);
std::wstring affine_decipher(const std::wstring& alphabet, std::map<wchar_t, int> alphabet_map, const std::wstring& message, int key_1, int key_2);

#endif