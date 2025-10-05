# F25ISEA3_24L-3050

# 🎯 C++ Mini Projects: Palindrome, Tic‑Tac‑Toe, and Hangman

This repository contains three C++ programs developed as part of a study in **Software Engineering principles** and **software qualities**.  
Each program is implemented to meet **explicit user requirements**, while also demonstrating **good design practices** such as modularity, robustness, and maintainability.

---

## 1. Palindrome Checker

### User Requirements
- Input: A string from the user.
- Normalize the string by:
  - Removing non‑alphanumeric characters.
  - Converting all letters to lowercase.
- Check if the normalized string is a palindrome.
- Output whether the string is a palindrome or not.

### Mapping to SE Principles
- **Rigor & Formality** → Using strict library functions for validation and normalization along with a precise two pointer algorithm.
- **Separation of Concerns** → `normalize()` handles cleaning, `isPalindrome()` handles checking.  
- **Modularity** → Functions are small and testable.  
- **Abstraction** → User sees only the result, not the normalization details.  
- **Anticipation of Change** → Easy to extend normalization (e.g., ignore diacritics).  
- **Generality** → Works for any string input, not just ASCII letters.  
- **Incrementality** → Can test normalization and palindrome logic independently.

### Software Qualities
- **Correctness** → Accurately detects palindromes.  
- **Robustness** → Handles punctuation, spaces, and case differences.  
- **Maintainability** → Clear modular functions and comments.  
- **Understandability** → Doxygen comments and structured code.  

---

## 2. Tic‑Tac‑Toe

### User Requirements
- Two players take turns placing `X` and `O` on a **3×3 grid**.
- Show the updated grid after every move.
- Detect win conditions (three in a row: horizontal, vertical, diagonal).
- Detect draw condition if the board is full.
- Announce winner or draw.

### Mapping to SE Principles
- **Rigor & Formality** → Input validation ensures only valid moves (0–2 indices, empty cells).  
- **Separation of Concerns** → `printBoard()`, `makeMove()`, `checkWin()`, `isDraw()` are distinct.  
- **Modularity** → Each function is small and testable.  
- **Abstraction** → Board represented as a 2D vector, hiding low‑level details.  
- **Anticipation of Change** → Limited, since requirements explicitly fix a 3×3 board.  
- **Generality** → Works for any two players, not tied to names.  
- **Incrementality** → Can test board printing, move logic, and win detection separately.

### Software Qualities
- **Correctness** → Detects wins and draws exactly as specified.  
- **Robustness** → Rejects invalid input and occupied cells.  
- **Maintainability** → Modular functions and constants.  
- **Understandability** → Clear prompts, structured board display, Doxygen comments.  
- **User Experience** → Visual grid with separators, clear win/draw messages.  

---

## 3. Hangman

### User Requirements
- Load a list of words from a text file (`words.txt`).
- Randomly select one word.
- Display underscores for missing letters.
- Player guesses letters:
  - If correct → reveal all positions of that letter.
  - If incorrect → decrement mistakes (max 7).
- Show mistakes left after each wrong guess.
- End game when:
  - Player reveals all letters (win).
  - Mistakes exceed 7 (loss).

### Mapping to SE Principles
- **Rigor & Formality** → Strict input validation (single alphabetic char only).  
- **Separation of Concerns** → `loadWords()`, `chooseWord()`, `displayState()`, `processGuess()`, `checkWin()` are distinct.  
- **Modularity** → Each function is small, testable, and reusable.  
- **Abstraction** → Word state represented as underscores and revealed letters.  
- **Anticipation of Change** → Mistake limit is a constant; word list externalized in a file.  
- **Generality** → Works for any word list, any word length.  
- **Incrementality** → Can test file loading, guessing, and win/loss logic independently.

### Software Qualities
- **Correctness** → Implements rules faithfully (7 mistakes, win/loss detection).  
- **Robustness** → Handles invalid input, repeated guesses, missing file.  
- **Maintainability** → Modular functions, constants, and comments.  
- **Understandability** → Doxygen comments, clear prompts, structured output.  
- **User Experience** → Shows blanks, feedback on guesses, mistakes left, win/loss messages.  

---

-> Across all three programs:
- **Palindrome Checker** demonstrates how to handle vague requirements by generalizing and anticipating change.  
- **Tic‑Tac‑Toe** demonstrates how to respect explicit requirements with rigor and clarity, without over‑engineering.  
- **Hangman** demonstrates a balance: explicit rules (7 mistakes, win/loss) but flexible design (external word list, constants).  

Together, these projects show how **SE principles** (rigor, modularity, abstraction, anticipation of change) and **software qualities** (correctness, robustness, maintainability, understandability, user experience) guide the design of even small programs.


