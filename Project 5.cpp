//***************************************
// Name: Cooper Vandiver
// Course: CS 155 - Computer Science 1
// Semester: Spring 2021
// Project 5: You are to write a program that mimics the game Memory. We will do this by having two “decks” of cards with values 1-10,
// randomly inserted into each deck. (Effectively, you will create two rows of 10 cards each, randomly ordered.) The values of these two
// decks will be stored in two separate arrays but the specific order of these values (the order of the cards in the deck) will be hidden
// from the user. The card choices will be displayed “face down” to the user with the top row numbered 1-10 and the second row numbered 11-20.
// Then, prompt the user to pick a card from each row of cards. If there is a match, the two cards are discarded (an X will appear in the row
// for each matched pair). The user continues to play the game until all ten matches have been found.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*name: initializeArray
  INCOMING:  An array of integer values and an additional integer value
  OUTGOING:  None
*/
void initializeArray(int[], int);

/*name: insertRand
  INCOMING:  An array of integer values and an additional integer value
  OUTGOING:  None
*/
void insertRand(int[], int);

/*name: printBoard
  INCOMING:  Two integer arrays (one for each row of numbers) and an additional integer value
  OUTGOING:  None
*/
void printBoard(int[], int[], int);

/*name: getGuess
  INCOMING:  Two integer arrays (one for each row of numbers), an integer value, and an integer value passed by reference to signify when game is over
  OUTGOING:  None
*/
void getGuess(int[], int[], int, int&);


int main(){
    srand(time(0)); //setting seed for random number generation

    int ttlFound = 0; //declaring variable

    int row1[10]; //declaring array of integer values and specifying size of array
    int row2[10]; //declaring array of integer values and specifying size of array

    initializeArray(row1, 10); //calling initializeArray for the array with first row of numbers
    initializeArray(row2, 10); //calling initializeArray for the array with second row of numbers

    insertRand(row1, 10); //calling insertRand to assign random values to each element of array with first row of numbers
    insertRand(row2, 10); //calling insertRand to assign random values to each element of array with second row of numbers

    printBoard(row1, row2, 10); //calling printBoard

    while(ttlFound < 10){ //setting up while statement to run until ttlFound reaches a value of 10 and game is over
        getGuess(row1, row2, 10, ttlFound); //calling getGuess to get input from user and increment value of ttlFound if guess is correct
        printBoard(row1, row2, 10); //calling printBoard to print remaining values that haven't been matched
    }
    cout<<"Game Over!"<<endl; //outputting to user that the game is finished
}

void initializeArray(int row[], int num){ //defining void initializeArray(int[], int) and declaring variables
    for(int i = 0; i<num; i++){ //setting up for statement to run while i is less than value assigned to num
        row[i] = -1; //assigning one to each element of the array determined by value of i
    }
}

void insertRand(int row[], int num){ //defining void insertRand(int[], int) and declaring variables
    int next = 0; //declaring variable and setting equal to 0
    for(int i = 1; i<=10; i++){ //setting up for statement to run while i is less than or equal to 10
        next = rand()%10; //assigning a random value to next
        while(row[next] != -1){ //while statement to test if element of array corresponding to next has had another value assigned to it
            next++; //incrementing next
            next = next % 10; //finding remainder of next divided by 10 to prevent the value of next from going above 9
        }
        row[next] = i; //when an element is found that has not had a value assigned to it, the value of i is assigned to that element
    }
}

void printBoard(int row1[], int row2[], int num){ //defining void printBoard(int[], int[], num)
    for(int i = 0; i < num; i++){ //setting up for statement to run while i is less than num
        if(row1[i] == 11){ //if statement to check if element of row1 corresponding to i has been matched
            cout<<"X "; //outputting an X instead of the number corresponding to that element of row1
        }
        else{ //if the element of row1 has not been matched
            cout<<i+1<<" "; //output the number corresponding to that element plus one (to show value as 1-10 instead of 0-9)
        }
    }
    cout<<endl; //ending the line after all values corresponding to row1 have been printed
    for(int i = 0; i<num; i++){ //setting up for statement to run while i is less than num
        if(row2[i] == 11){ //if statement to check if the element of row2 corresponding to i has been matched
            cout<<"X "; //outputting an X instead of the number corresponding to that element of row2
        }
        else{ //if the element of row2 has not been matched
            cout<<i+11<<" "; //output the number corresponding to that element plus one (to show value as 1-10 instead of 0-9)
        }
    }
    cout<<endl; //ending line after all values corresponding to elements of row2 have been printed
}

void getGuess(int row1[], int row2[], int num, int& ttlFound){ //defining void getGuess(int[], int[], int, int&) and declaring variables
    int guess; //declaring variable guess
    int guess2; //declaring variable guess2
    cout<<"What number card would you like to check from the first row?"<<endl; //prompting user to input first guess
    cin>>guess; //getting first guess
    cout<<guess<<" is a(n) "<<row1[guess - 1]<<endl; //outputting value of the element of row1 corresponding to guess
    cout<<"What number card would you like to check from the second row?"<<endl; //prompting user to input second guess
    cin>>guess2; //getting second guess
    cout<<guess2<<" is a(n) "<<row2[guess2 - 11]<<endl; //outputting value of the element of row2 corresponding to guess2
    if(row1[guess - 1] == row2[guess2 - 11]){ //if statement to check if the numbers guess have a matching value
        cout<<"Match!"<<endl; //outputting to the user that a match has been found
        row1[guess - 1] = 11; //setting value of the element in row1 that has been matched to 11
        row2[guess2 - 11] = 11; //setting value of the element in row2 that has been matched to 11
        ttlFound++; //incrementing ttlFound to keep track of when all numbers have been matched
    }
    else{ //if the guessed numbers do not have matching values
        cout<<"No match!"<<endl; //outputting to the suer that a match has not been found
    }
    cout<<endl; //ending line again for improved readability
}
