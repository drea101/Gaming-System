#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void rps(){
// Declare variables to store player choices
string p1,p2;
int winner = 2;
cout << "This game requires 2 players. Enter either rock, paper,
or scissors to pick the action."<< endl;
// Prompt player 1 to choose their play
cout<<"Player 1 chose your action: "<<endl;
// Input player 1's choice
cin>>p1;
//Checks for any input that is not rock paper or scissors and
prompts the user to reenter their choice until it is valid
while (p1 != "rock" && p1 !="paper" && p1 !="scissors"){
cout << "That is not rock, paper, or scissors. please enter it
again"<< endl;
cin >> p1;
}
// Prompt player 2 to choose their play
cout<<"Player 2 chose your action: "<<endl;
// Input player 2's choice
cin >> p2;
//Checks for any input that is not rock paper or scissors and
prompts the user to reenter their choice until it is valid
while (p2 != "rock" && p2 !="paper" && p2 !="scissors"){
cout << "That is not rock, paper, or scissors. please enter it
again"<< endl;
cin >> p2;
}
// Determine the winner based on player choices, used if
statements for every possible scenario of player 1 winning.
if ((p1=="rock" && p2=="scissors") || (p1=="paper" && p2=="rock")
|| (p1=="scissors" && p2=="paper")) {
winner = 1;
}
// Determine the winner based on player choices, used if
statements for every possible scenario of player 2 winning.
else if ((p2=="rock" && p1=="scissors") || (p2=="paper" &&
p1=="rock") || (p2=="scissors" && p1=="paper")){
winner = 0;
}
// for draws
else {
winner = 2;
}
//a switch statment because I was not sure where else to include
one -Dillon
switch (winner){
case 0:
cout << "Player 2 wins!" <<endl;
break;
case 1:
cout << "Player 1 wins!" <<endl;
break;
case 2:
cout << "Its a Draw." << endl;
break;
}
}
//function to generate the number in range of max and man
int GenerateRandomNumber (int min, int max){
return rand() % max + min;
}
//function to check the compare the guess of the user and return
true or false to continue or end the game if it is over
bool checkGuess(int guess, int randNumber){
if (guess < randNumber){
cout <<"Your guess was too low. Go higher. "<<endl;
return true;
}
else if (guess > randNumber){
cout <<"Your guess was too high. Go lower. "<<endl;
return true;
}
else{
cout <<"Thats the number! You got it! Congrats!"<<endl;
return false;
}
}
//fucntion to choose word for user to guess
string chooseWord (string words[10]){
return words [(rand() % 11)];
}
//function to return the current state of the word being guessed
void displayWord (string words, bool guessedLetters[]){
for (int i = 0; i < words.length(); i++)
if (guessedLetters[i] == true){
cout << words[i];
}
else{
cout << "_";
}
}
//fucntion to check whether or not the letter guessed by the user
is in the word
int checkGuess(string word, char guessedLetter){
bool thing = false;
while (thing == false){
for (int i = 0; i < word.length(); i++){
if (word[i] == guessedLetter){
return i;
}
}
return -1;
}
}
void numberGuesser(){
//initialize variables
int maximum, minimum, userGuess, theNumber;
//prompt user for minimum and maximum values to guess from
cout << "Welcome to number guesser 4k! Pick the smallest number
in the range you would like to guess from: ";
cin >> minimum;
cout << "OK, now pick the biggest number in the range you would
like to guess from: ";
cin >> maximum;
//call function to generate number for user to guess
theNumber = GenerateRandomNumber(minimum, maximum);
//prompt user to guess number
cout << "Okay I'm thinking of a number between " << minimum << "
and " << maximum << ". Take your first guess!";
//game loop. Let the user know if their guess is lower or higher
than the number. Repeat until number is guessed.
do {
cin >> userGuess;
while ((userGuess > maximum) || (userGuess < minimum)){
cout << "That number is out of the range. Please try again ";
cin >> userGuess;
}
}
while (checkGuess(userGuess, theNumber));
}
void wordGuessGame (){
//declaring all variables
string possible [] = {"smoke", "dillon", "kangaroo", "jelly",
"dance", "compile", "bamboozle", "encapsulate", "jester",
"destruction"};
char usersGuess, hold;
string theWord = chooseWord(possible);
int length = theWord.length();
bool guesses [length];
int amountOfGuess = 10;
int correctGuesses = 0;
char alreadySelected [11] {' ', ' ',' ',' ',' ',' ',' ',' ',' ','
'
, ' '};
//filling out the guesses array for the selected word's length
for (int i = 0; i < length; i++){
guesses[i] = false;
}
cout << "Welcome to word guesser 5k! Choose a letter to start
guessing the word!";
//game loop
while (amountOfGuess != 0){
cin >> usersGuess;
//makes sure the user doesnt enter a number and will tell them
to enter something different if so
while (usersGuess =='0'||usersGuess =='1'||usersGuess
=='2'||usersGuess =='3'||usersGuess =='4'||usersGuess
=='5'||usersGuess =='6'||usersGuess =='7'||usersGuess
=='8'||usersGuess =='9'){
cout << endl << "You entered a number, please enter a
letter";
cin >> usersGuess;
}
//checks for already guessed letters by comparing the user's
guess to the guessed letter array
for (int i = 0; i <= (sizeof(alreadySelected)/sizeof(char));
i++){
hold = alreadySelected[i];
while (hold == usersGuess){
cout << endl << "You already guessed that silly! Try a
different letter: ";
cin >> usersGuess;
i = -1;
}
}
//adds the user's guess to the guessed letter array
alreadySelected[amountOfGuess] = usersGuess;
//when user correctly guesses letter
if (checkGuess(theWord, usersGuess) != -1){
guesses [checkGuess(theWord, usersGuess)] = true;
//check for duplicate letters in the word
for (int i = 0; i < length; i++){
for (int j = i+1; j < length; j++){
if ((theWord[i] == theWord[j]) && (guesses[i]== true)){
guesses[j] = true;
if (theWord[j] == usersGuess){
correctGuesses++;
}
}
}
}
correctGuesses ++;
cout<< "Word: ";
displayWord(theWord, guesses);
cout << endl << "Good guess! You have "<< (amountOfGuess -1)
<< " Guesses left!";
}
//for an incorrect guess
else{
cout<< "Word: ";
displayWord(theWord, guesses);
amountOfGuess -= 1;
cout << endl << "Sorry, thats not in the word. Try a
different letter! you have "<< amountOfGuess << " guesses left";
}
//displays loss message when user runs out of guesses
if (amountOfGuess == 0){
cout << endl << "Sorry, the word was " << theWord << ". Try
again some other time!";
}
//displays victory message if user guesses word correctly
if (correctGuesses == (length)){
cout << endl << "Congrats, you got it! The word was " <<
theWord<< endl;
amountOfGuess = 0;
}
}
}
int main(){
//sets the random seed for games that use rand function
srand (time(NULL));
//variables for the menu
int selectedGame;
bool inGame = true;
//introduce menu to user
cout << "Welcome to the 3 games collection! there are only 3
games! type in the number coresponding to the game to select it! We
have:" << endl;
//menu will display until user quits
while (inGame){
cout << "1. Rock Paper Scissors" <<endl <<"2. Word
Guesser"<<endl <<"3. Number Guesser" <<endl<< "4. Quit"<<endl;
cin >> selectedGame;
if (selectedGame == 1){
rps();
cout << "pick another game!"<< endl;
}
else if (selectedGame == 2){
wordGuessGame();
cout << "pick another game!"<< endl;
}
else if (selectedGame == 3){
numberGuesser();
cout << "pick another game!"<< endl;
}
else if (selectedGame == 4){
inGame = false;
}
else{
cout << "That wasnt one of the numbers! Pick from one of
these below:"<< endl;
}
}
}