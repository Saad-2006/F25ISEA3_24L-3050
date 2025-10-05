#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> ///< Provides character classification (isalnum, tolower, etc.)
using namespace std;

/**
 * @brief Normalize a string by removing non-alphanumeric characters
 *        and converting all letters to lowercase.
 *
 * This function ensures that spaces, punctuation, and case differences
 * do not affect palindrome checking.
 * 
 * static cast is used to also treat non-ASCII values correctly with the 
 * cctype functions like isalnum()
 *
 * @param str The original input string from the user.
 * @return A cleaned string containing only lowercase alphanumeric characters.
 */
string normalize(const string& str) {
    string cleaned;
    for (char ch : str) {
        if (isalnum(static_cast<unsigned char>(ch))) {
            cleaned.push_back(tolower(ch));
        }
    }
    return cleaned;
}

/**
 * @brief Check if a given string is a palindrome.
 *
 * A palindrome is a string that reads the same forwards and backwards.
 * This function uses the two-pointer technique to compare characters
 * from both ends of the string until the middle is reached.
 *
 * @param str The normalized string to check.
 * @return true if the string is a palindrome, false otherwise.
 */
bool isPalindrome(const string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}

/**
 * @brief Main entry point of the program.
 *
 * The program repeatedly asks the user to enter a string and determines
 * whether it is a palindrome. The user can type "exit" or "quit" to end
 * the program. Input is normalized before checking to ensure robustness.
 *
 * @return int Exit status code (0 for success).
 */
int main() {
    cout << "Palindrome Checker (type 'exit' or 'quit' to terminate the program)\n";
    

    while (true) {
        cout << "\nEnter a string: ";
        string input;
        getline(cin, input);

        /// Exit condition: user types "exit" or "quit"
        /// Other variants like "EXIT" or "qUit", etc... are not going to terminate, to 
        /// allow the user to check them for palindrome. 
        /// I'm trading a pinch of functionality with usability here :)
        if (input == "exit" || input == "quit") {
            cout << "Exiting program...\n";
            break;
        }

        string cleaned = normalize(input);

        if (cleaned.empty()) {
            cout << "Not Palindrome (no valid characters)\n";
        } else if (isPalindrome(cleaned)) {
            cout << "Palindrome\n";
        } else {
            cout << "Not Palindrome\n";
        }
    }
    return 0;
}