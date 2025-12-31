#pragma once

#include <vector>
#include <string>

class Phrase {
public:
    Phrase(std::vector<std::vector<std::string>> parts);
    bool isPhrase(std::string s);

private:
    std::vector<std::vector<std::string>> parts;
};