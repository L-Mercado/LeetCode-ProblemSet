// Leet Code Problem 17. Letter Combinations Of A Phone Number | This program creates a hash map of the digits of a phone. Prompts the user to choose up to 4 digits, and then prints the possible combinations between the digits.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> result;

    void backtrack(const string& digits, int index, string& current) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        char digit = digits[index];
        string letters = phoneMap[digit];

        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        result.clear();
        string current = "";
        backtrack(digits, 0, current);
        return result;
    }
};

int main() {
    Solution solution;
    string digits;

    cout << "Enter Digits (1-4 Digits): ";
    cin >> digits;

    vector<string> combinations = solution.letterCombinations(digits);

   
    cout << "Number of Combinations: " << combinations.size() << " | All Combinations: ";

    for (size_t i = 0; i < combinations.size(); i++) {
        cout << combinations[i];
        if (i < combinations.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}