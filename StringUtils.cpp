#include "StringUtils.h"
#include <algorithm>
using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string clearSpaces(string str) {
    str.erase(remove_if(str.begin(), str.end(),
        [](unsigned char c) { return isspace(c); }),
        str.end());
    return str;
}