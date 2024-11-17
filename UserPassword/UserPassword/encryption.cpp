#include "encryption.h"
#include <algorithm>

std::string encrypt(const std::string& str) {
    std::string encrypted = str;
    std::transform(encrypted.begin(), encrypted.end(), encrypted.begin(), [](char c) { return c + 1; });
    return encrypted;
}

std::string decrypt(const std::string& str) {
    std::string decrypted = str;
    std::transform(decrypted.begin(), decrypted.end(), decrypted.begin(), [](char c) { return c - 1; });
    return decrypted;
}
