/*
 * Started at 5:10 pm Saturday the 20th
 * Finished at 8:47 pm Saturday the 20th
 *
 * Created by Thomas Nielsen
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

//setup functions
void WordPicker(string& wordUsed);
void WelcomeScreen();
void CorrectGuessSet(vector<char>& rightGuesses, string wordUsed);
//gamePlay functions
void GallowsPrinter(int livesLeft);
void ScreenPrinter(int livesLeft, vector<char> totalGuesses, vector<char> rightGuesses);
void ReceiveGuess(vector<char>& userGuesses, vector<char>& rightGuesses, int& livesLeft, string wordUsed, bool&gameWon);

int main() {
    //variables
    char playAgain = 'y';
    while(playAgain == 'y') {   // this repeats until the player no longer wants to play.
    string wordUsed;
    bool gameWon = false;
    int livesLeft = 6;          // this might seem weird that every iteration of the while loop the variables are
    vector<char> totalGuesses;  // re-initialize, but it seemed like the easiest way to reset everything after each game.
    vector<char> rightGuesses;
    //Welcome to gamey
    WelcomeScreen();
    cout << "Would you like to start? (y - yes, n - no)" << endl;
    cin >> playAgain;
    WordPicker(wordUsed);
    CorrectGuessSet(rightGuesses, wordUsed);
    while((livesLeft > 0) && !gameWon) { //this repeats until the game is over
        ScreenPrinter(livesLeft, totalGuesses, rightGuesses);
        ReceiveGuess(totalGuesses, rightGuesses, livesLeft, wordUsed, gameWon);
    }
        if(gameWon) {
            cout << "YOU WIN!!! The correct word was " << wordUsed << endl;
        } else {
            cout << "You lost. The word was " << wordUsed << endl;
        }
    cout << "Would you like to play again?" << endl;
    cin >> playAgain;
}

    cout << "Thank you for playing, Goodbye" << endl;

    return 0;
}


void WordPicker(string& wordUsed) { //chooses the word for the game
    string words[10] = {"zit", "jump", "skill", "thrill", "through", "achieved", "architect", "puzzlingly", "marshmallow", "abbreviating"};
    srand(time(0));
    int wordIndex = rand() % 10;
    wordUsed = words[wordIndex];
    cout << "The word has " << wordUsed.size() << " letters!" << endl;
    cout << endl;
}
void CorrectGuessSet(vector<char>& rightGuesses, string wordUsed) { //sets the vector that will show the correct guesses
    for(int i = 0; i < wordUsed.size(); i++) {
        rightGuesses.push_back('_');
    }
}

void WelcomeScreen() { // welcome and rules
    cout << "* * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "*                                             *" << endl;
    cout << "*           Welcome to Hangman!!!             *" << endl;
    cout << "*                                             *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "*                                             *" << endl;
    cout << "*                   Rules                     *" << endl;
    cout << "* 1. Only type lower-case letters             *" << endl;
    cout << "* 2. You begin each game with 6 lives         *" << endl;
    cout << "* 3. With each missed guess, you lose a life  *" << endl;
    cout << "* 4. Have fun!!!!!!!!!                        *" << endl;
    cout << "*                                             *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << endl;
}
void GallowsPrinter(int livesLeft) { //prints the gallows and person based on lives left
    if(livesLeft == 0) {
        cout << "     * * * * * * * " << endl;
        cout << "     :           * " << endl;
        cout << "     0           * " << endl;
        cout << "     |           * " << endl;
        cout << " - - - - -       * " << endl;
        cout << "     |           * " << endl;
        cout << "    / \\          * " << endl;
        cout << "   /   \\         * " << endl;
        cout << "                 * " << endl;
        cout << "       * * * * * * * * * * " << endl;
    } else if(livesLeft == 1) {
        cout << "     * * * * * * * " << endl;
        cout << "     :           * " << endl;
        cout << "     0           * " << endl;
        cout << "     |           * " << endl;
        cout << " - - - - -       * " << endl;
        cout << "     |           * " << endl;
        cout << "      \\          * " << endl;
        cout << "       \\         * " << endl;
        cout << "                 * " << endl;
        cout << "       * * * * * * * * * * " << endl;

    } else if(livesLeft == 2) {
        cout << "     * * * * * * * " << endl;
        cout << "     :           * " << endl;
        cout << "     0           * " << endl;
        cout << "     |           * " << endl;
        cout << " - - - - -       * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "       * * * * * * * * * * " << endl;

    } else if(livesLeft == 3) {
        cout << "     * * * * * * * " << endl;
        cout << "     :           * " << endl;
        cout << "     0           * " << endl;
        cout << "     |           * " << endl;
        cout << " - - -           * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "       * * * * * * * * * * " << endl;
    } else if(livesLeft == 4) {
        cout << "     * * * * * * * " << endl;
        cout << "     :           * " << endl;
        cout << "     0           * " << endl;
        cout << "     |           * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "       * * * * * * * * * * " << endl;
    } else if(livesLeft == 5) {
        cout << "     * * * * * * * " << endl;
        cout << "     :           * " << endl;
        cout << "     0           * " << endl; //0 is a head
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "       * * * * * * * * * * " << endl;
    } else {
        cout << "     * * * * * * * " << endl;
        cout << "     :           * " << endl;
        cout << "     O           * " << endl; //O is a noose
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "                 * " << endl;
        cout << "       * * * * * * * * * * " << endl;
    }
}
void ScreenPrinter(int livesLeft, vector<char> totalGuesses, vector<char> rightGuesses) { //Prints lives and guesses(right and wrong
    cout << "You have " << livesLeft << " incorrect guesses 'til you die..." << endl;
    cout << "You have guessed these letters:" << endl;
    for(int i = 0; i < totalGuesses.size(); i++) {
        cout << totalGuesses.at(i) << " ";
    }
    cout << endl;
    cout << "This is what you have correctly guessed so far:" << endl;

    for(int i = 0; i < rightGuesses.size(); i++) {
        cout << rightGuesses.at(i);
    }
    cout << endl;
}
void ReceiveGuess(vector<char>& userGuesses, vector<char>& rightGuesses, int& livesLeft, string wordUsed, bool& gameWon) {
    char userGuess;                                // user enters a guess and the funtions determines if
    bool correct = false;                          // the guess is correct or not and if the player wins
    cout << "What letter would you like to guess?" << endl;
    cin >> userGuess;
    for(int i = 0; i < rightGuesses.size(); i++){
        if(userGuess == wordUsed.at(i)) {

            correct = true;
            rightGuesses.at(i) = userGuess;

        }
    }
    gameWon = true;

    for(int i = 0; i < rightGuesses.size(); i++){

        if(rightGuesses.at(i) != wordUsed.at(i)) {

            gameWon = false;
        }
    }

    if(correct) {

        cout << "CONGRATS!!! " << userGuess << " was in the word!" << endl;
    } else {
        cout << "I'm sorry, " << userGuess << " was not in the word!" << endl;
        livesLeft -= 1;
    }
    if(userGuesses.size() == 0) {
        userGuesses.push_back(userGuess);
    }
    int vectorSize = userGuesses.size();    /*
                                            * When I used userGuesses.size()
                                            * in the for loop it was an infinite loop
                                            */
    for(int i = 0; i < vectorSize; i++) {
        if(userGuess < userGuesses.at(i)) {
            userGuesses.insert(userGuesses.begin() + i, userGuess);
            break;
        }
        if(userGuess > userGuesses.at(vectorSize - 1)) {
            userGuesses.push_back(userGuess);
            break;
        }
    }
    GallowsPrinter(livesLeft);
}

