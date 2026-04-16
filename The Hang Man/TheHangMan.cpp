#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to display the word with blanks for unguessed letters
string displayWord(const string& secretWord, const string& guessedLetters) {
    string display = "";
    for (char letter : secretWord) {
        if (guessedLetters.find(letter) != string::npos) {
            display += letter;
        } else {
            display += "_";
        }
        display += " ";
    }
    return display;
}

int main() {
    // Create a list of words to choose from
    vector<string> words = {"apple", "banana", "cherry", "date", 
        "elderberry", "mountain", "glass", "shadow", "river", "clock", 
        "forest", "paper", "thunder", "pillow", "engine", "mirror", 
        "ocean", "candle", "ladder", "blanket", "rocket", "feather", 
        "puzzle", "window", "carpet", "bottle", "camera", "keyboard", 
        "desert", "helmet", "bridge", "pocket", "lantern", "marble", 
        "whistle", "compass", "suitcase", "hammer", "notebook", "cable", 
        "jacket", "diamond", "shovel", "basket", "violin", "helmet", 
        "corridor", "tower", "magnet", "umbrella", "satellite"};
    
    // Choose a random word from the list
    srand(time(0)); // Seed the random number generator with current time
    string secretWord = words[rand() % words.size()];
    
    // Initialize game state variables
    string guessedLetters = "";  // String to store all guessed letters
    int maxAttempts = 6;         // Maximum number of wrong guesses allowed
    int wrongGuesses = 0;        // Counter for wrong guesses
    bool gameWon = false;        // Flag to track if player has won
    
    // Main game loop - continues until player wins or runs out of attempts
    while (wrongGuesses < maxAttempts && !gameWon) {
        // Display current game state
        cout << "Word: " << displayWord(secretWord, guessedLetters) << endl;
        cout << "Guessed letters: " << guessedLetters << endl;
        cout << "Attempts left: " << (maxAttempts - wrongGuesses) << endl;
        
        // Get player's guess
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
        guess = tolower(guess); // Convert to lowercase for case-insensitive comparison
        
        // Check if letter was already guessed
        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter!" << endl;
            continue; // Skip to next iteration
        }
        
        // Add the guess to the list of guessed letters
        guessedLetters += guess;
        
        // Check if the guess is correct (letter exists in secret word)
        if (secretWord.find(guess) != string::npos) {
            cout << "Good guess!" << endl;
        } else {
            cout << "Wrong guess!" << endl;
            wrongGuesses++; // Increment wrong guess counter
        }
        
        // Check if player has won (all letters in secret word have been guessed)
        gameWon = true; // Assume won, then check
        for (char letter : secretWord) {
            if (guessedLetters.find(letter) == string::npos) {
                gameWon = false; // Found an unguessed letter, so not won yet
                break;
            }
        }
    }
    
    // Display final result
    if (gameWon) {
        cout << "Congratulations! You won! The word was: " << secretWord << endl;
    } else {
        cout << "Sorry, you lost! The word was: " << secretWord << endl;
    }
    
    return 0;
}