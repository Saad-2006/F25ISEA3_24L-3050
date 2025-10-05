#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAX_MISTAKES = 7; ///< Maximum allowed mistakes

/**
 * @brief Load words from a text file into a vector.
 *
 * Each line in the file should contain one word.
 *
 * @param filename The name of the file containing words.
 * @return A vector of words loaded from the file.
 */
vector<string> loadWords(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string word;
    while (file >> word) {
        // Convert to lowercase for consistency
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }
    return words;
}

/**
 * @brief Choose a random word from the list of words.
 *
 * @param words The vector of words to choose from.
 * @return A randomly selected word.
 */
string chooseWord(const vector<string>& words) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % words.size();
    return words[index];
}

/**
 * @brief Display the current state of the guessed word.
 *
 * Shows underscores for unguessed letters and reveals guessed ones.
 *
 * @param word The original word.
 * @param guessed The current guessed state.
 */
void displayState(const string& guessed, int mistakesLeft) {
    cout << "\nWord: " << guessed << "\n";
    cout << "Mistakes left: " << mistakesLeft << "\n";
}

/**
 * @brief Process a player's guess.
 *
 * Checks if the guessed letter is in the word and updates the guessed state.
 *
 * @param word The original word.
 * @param guessed The current guessed state (underscores and letters).
 * @param letter The guessed letter.
 * @return true if the guess was correct, false otherwise.
 */
bool processGuess(const string& word, string& guessed, char letter) {
    bool correct = false;
    for (size_t i = 0; i < word.size(); i++) {
        if (word[i] == letter && guessed[i] == '_') {
            guessed[i] = letter;
            correct = true;
        }
    }
    return correct;
}

/**
 * @brief Check if the player has won.
 *
 * @param guessed The current guessed state.
 * @return true if no underscores remain, false otherwise.
 */
bool checkWin(const string& guessed) {
    return guessed.find('_') == string::npos;
}

/**
 * @brief Main entry point of the program.
 *
 * Runs the Hangman game: loads words, selects one, and manages the game loop.
 *
 * @return int Exit status code (0 for success).
 */
int main() {
    vector<string> words = loadWords("words.txt");
    if (words.empty()) {
        cout << "Word list is empty or file not found!\n";
        return 1;
    }

    string word = chooseWord(words);
    string guessed(word.size(), '_');
    int mistakesLeft = MAX_MISTAKES;
    vector<char> usedLetters;

    cout << "Welcome to Hangman!\n";
    displayState(guessed, mistakesLeft);

    while (mistakesLeft > 0) {
        cout << "\nEnter a letter: ";
        string input;
        getline(cin, input);

        if (input.size() != 1 || !isalpha(input[0])) {
            cout << "Invalid input! Please enter a single alphabetic character.\n";
            continue;
        }

        char letter = tolower(input[0]);

        // Check if already guessed
        if (find(usedLetters.begin(), usedLetters.end(), letter) != usedLetters.end()) {
            cout << "You already guessed '" << letter << "'. Try another.\n";
            continue;
        }

        usedLetters.push_back(letter);

        if (processGuess(word, guessed, letter)) {
            cout << "Good guess!\n";
        } else {
            mistakesLeft--;
            cout << "Wrong guess!\n";
        }

        displayState(guessed, mistakesLeft);

        if (checkWin(guessed)) {
            cout << "\nCongratulations! You guessed the word: " << word << "\n";
            return 0;
        }
    }

    cout << "\nYou lost! The word was: " << word << "\n";
    return 0;
}
