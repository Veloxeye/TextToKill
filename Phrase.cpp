#include "Phrase.h"
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

Phrase::Phrase(vector<vector<string>> parts)
    : parts(parts) {}

bool Phrase::isPhrase(string s) {
    // clear whitespace
    s.erase(remove_if(s.begin(), s.end(),
        [](unsigned char c) { return std::isspace(c); }),
        s.end());

    vector<int> lastIndices = { 0 };

    cout << "PARTS:" << endl;
    for (int partI = 0; partI < parts.size(); partI++) {
        cout << "<" << partI << ">" << endl;
        vector<string> synonyms = parts.at(partI);
        bool foundMatch = false;
        vector<int> newIndices;

        for (int indexI = 0; indexI < lastIndices.size(); indexI++) {
            cout << "starting at index " << lastIndices.at(indexI) << endl;

            for (int synonymI = 0; synonymI < synonyms.size(); synonymI++) {
                string synonym = synonyms.at(synonymI);

                bool synonymEndsPhrase = false;
                if (!synonym.empty() && synonym.back() == '\n') {
                    synonym.pop_back();
                    synonymEndsPhrase = true;
                }
                if (partI == parts.size() - 1)
                    synonymEndsPhrase = true;

                synonym.erase(remove_if(synonym.begin(), synonym.end(),
                    [](unsigned char c) { return std::isspace(c); }),
                    synonym.end());

                string word = s.substr(lastIndices.at(indexI), synonym.length());

                cout << "comparing: <" << word << "> to <" << synonym << ">" << endl;

                if (word == synonym) {
                    cout << "matches!" << endl;
                    if (synonymEndsPhrase &&
                        s.length() == lastIndices.at(indexI) + synonym.length()) {
                        return true;
                    }
                    foundMatch = true;
                    newIndices.push_back(lastIndices.at(indexI) + synonym.length());
                }
                else {
                    cout << "does not match!" << endl;
                }
            }
        }

        if (!foundMatch)
            return false;

        lastIndices = newIndices;
    }
    return false;
}