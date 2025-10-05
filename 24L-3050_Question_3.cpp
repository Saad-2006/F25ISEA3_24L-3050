#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

const int SIZE = 3; ///< Board size (3x3) - Given

/**
 * @brief Print the current Tic-tac-toe board.
 *
 * Displays the board in a grid format with rows and columns,
 * including separators for readability.
 *
 * @param board 2D vector representing the game board.
 */
void printBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) cout << "|";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---★---★---\n";
    }
    cout << "\n";
}

/**
 * @brief Check if a player has won the game.
 *
 * A win occurs if the player has three consecutive marks
 * horizontally, vertically, or diagonally.
 *
 * @param board 2D vector representing the game board.
 * @param player The character ('X' or 'O') to check.
 * @return true if the player has won, false otherwise.
 */
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

/**
 * @brief Check if the board is full (draw condition).
 *
 * A draw occurs if all cells are filled and no player has won.
 *
 * @param board 2D vector representing the game board.
 * @return true if the board is full and no winner, false otherwise.
 */
bool isDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

/**
 * @brief Attempt to make a move on the board.
 *
 * Validates that the chosen cell is empty before placing the player's mark.
 *
 * @param board 2D vector representing the game board.
 * @param row Row index (0-based).
 * @param col Column index (0-based).
 * @param player The character ('X' or 'O') making the move.
 * @return true if the move was successful, false otherwise.
 */
bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (board[row][col] != ' ') {
        cout << "Cell already occupied! Try again.\n";
        return false;
    }
    board[row][col] = player;
    return true;
}

/**
 * @brief Validate that input is a single digit between 0 and 2.
 *
 * Reads user input as a string, checks that it is a single digit,
 * and converts it to an integer index if valid.
 *
 * @param prompt The message to display to the user.
 * @param index Reference to store the validated index.
 * @return true if the input is valid, false otherwise.
 */
bool getValidIndex(const string& prompt, int& index) {
    string input;
    cout << prompt;
    getline(cin, input);

    if (input.size() != 1 || !isdigit(input[0])) {
        cout << "Invalid input! Enter a number between 0 and 2.\n";
        return false;
    }

    index = input[0] - '0';
    if (index < 0 || index > 2) {
        cout << "Out of range! Enter 0, 1, or 2.\n";
        return false;
    }
    return true;
}

/**
 * @brief Main entry point of the program.
 *
 * Runs a two-player Tic-tac-toe game. Players alternate turns
 * entering row and column positions until one wins or the game is drawn.
 *
 * @return int Exit status code (0 for success).
 */
int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Tic-Tac-Toe Game (Player X vs Player O)\n";
    printBoard(board);

    while (!gameOver) {
        int row, col;

        // Get valid row
        while (!getValidIndex("Player " + string(1, currentPlayer) + ", enter row (0-2): ", row));

        // Get valid column
        while (!getValidIndex("Player " + string(1, currentPlayer) + ", enter column (0-2): ", col));

        if (!makeMove(board, row, col, currentPlayer)) {
            continue; // retry if cell occupied
        }

        printBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (isDraw(board)) {
            cout << "Game drawn!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
