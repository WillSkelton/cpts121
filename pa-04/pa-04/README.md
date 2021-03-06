# Programming Assignment 4: "Craps"

  - [Description](#description)
  - [Functions](#functions)
    - [gameLoop()](#gameloop)
    - [showMenu()](#showmenu)
    - [showRules()](#showrules)
    - [rollDice()](#rolldice)
    - [playGame()](#playgame)
    - [successiveRoll()](#successiveroll)
    - [setAccountBalance()](#setaccountbalance)
    - [getWager()](#getwager)
    - [printDice()](#printdice)
    - [gameChatter()](#gamechatter)

## Description
***NOTE:***   If you're reading the plaintext version of this README, go to https://github.com/WillSkelton/cpts121/tree/master/pa-04/pa-04 to see the styled page. It's much easier to read.

This program simulates the game of "craps". 


## Functions

### gameLoop
```c
int gameLoop(void);
```
This function is the main "REPL" (**R**ead **E**valuate **P**rint **L**oop) for the game. It does the following:
  - Seeds the random number generator
  - Calls [getAccountBalance()](#getaccountbalance) and gets the user's bank account balance
  - Checks to make sure the player has money in their account. The inevitably will the first time through because getAccountBalance() won't let them enter 0 or less. However, later on, this will check to make sure the player hasn't run out of money and will kick them out if they have.
  - Calls [showMenu()](#showmenu) to show the menu
  - Accepts user input and does one of the following
    - user inputs 1 $\Rightarrow$ [showRules()](#showrules)
    - user inputs 2 $\Rightarrow$ [playGame()](#playgame)
      - after playGame() runs, the account Balance is updated here with either the winnings or losings
    - user inputs 3 $\Rightarrow$ shows account balance
    - user inputs 4 $\Rightarrow$ quits game
      - ***NOTE:*** Any other input will cause the program to re-prompt the user for a valid input


### showMenu
```c
void showMenu(void);
```
This Function prints the following:
```
Press 1 to show the rules:
Press 2 to start the game:
Press 3 to show your account balance:
Press 4 to clear the screen:
Press 5 to cash out:
```

### showRules
```c
void showRules(void);
```
This function prints the game rules like this:
```
1.) Roll Dice
2.) If the sum of the dice is 7 or 11, then you win 2x what you bet.
3.) If the sum is 2, 3, or 12, you lose.
4.) If the sum is 4, 5, 6,8, 9, or 10, that's your new goal. You have to keep rolling until you get that.
  * Note: if you roll a 7 or 11 after the first roll, you lose
```

### rollDice
```c
int rollDice(void);
```
This function randomly generates 2 integers between 1 and 6 (inclusive), prints them to the console and returns the sum of the 2 numbers.

### playGame
```c
double playGame(double accountBalance);
```
This function plays one round of the game. The steps are as follows:
  - Calls  [getWager()](#getwager) to ask the user how much they would like to bet on this round
  - Calls [rollDice()](#rolldice)
    - ***If the sum is 7 or 11***, the the player wins and is notified of their success and new balance.
    - ***If the sum is 2, 3, or 12***, the the player loses and is notified of their loss and new balance.
    - that becomes the player's **mark**. The program keeps rolling the dice until the player's mark is rolled and they win or either a 7 or 11 is rolled and they lose. Either way, the player is notified. This part is handled in [successiveRoll()](#successiveroll)
  - Returns the winnings ($\pm wager$ depending on if they win or lose) to the [gameLoop()](#gameloop)
 
### successiveRoll()
This function handles what heppens if the player makes it through the first roll. If the player rolls a ***4, 5, 6, 8, 9, or 10***, the program will continue rolling until the player rolls a 7 or 11 and they lose or the player hits their mark and wins.

### setAccountBalance
```c
double getAccountBalance(void);
```
This function asks the user for their bank account balance. It must be greater than 0.0. The program will continue to ask until the user enters a valid number. Once the player enters a valid number, the value is returned to [gameLoop()](#gameloop).

### getWager
```c
double getWager(double accountBalance);
```
This function asks the user to input a value to wager for the next game. The program then checks to make sure the player isn't betting more money than they have and will continue to ask the user for a valid number until they enter one.

### printDice()
```c
void printDice(int num);
```

This function takes an integer (1-6) and prints an ascii die for that number. They look much better in the game window. See below:
```
     1            2            3 
 _________    _________    _________
|         |  | O       |  | O       |
|    O    |  |         |  |    O    |
|         |  |       O |  |       O |
|_________|  |_________|  |_________|

     4            5            6
 _________    _________    _________
| O     O |  | O     O |  | O     O |
|         |  |    O    |  | O     O |
| O     O |  | O     O |  | O     O |
|_________|  |_________|  |_________|

```

### gameChatter
```c
void gameChatter(int num);
```
This function takes a number from 0-2 with 0 representing losing, 1 representing still playing, and 2 being winning. It takes that number and uses it to print a relevant but random statement to the screen during gameplay.