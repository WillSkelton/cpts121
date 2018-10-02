# Programming Assignment 4: "Craps"

  - [Description](#description)
  - [Functions](#functions)
    - [showRules](#showrules)
    - [getBankBalance](#getbankbalance)
    - [getWagerAmount](#getwageramount)
    - [checkWagerAmount](#checkwageramount)
    - [rollDie](#rolldie)
    - [calculateDiceSum](#calculatedicesum)
    - [firstRollVerdict](#firstrollverdict)
    - [successiveRollVerdict](#successiverollverdict)
    - [adjustBankBalance](#adjustbankbalance)
    - [chatterMessages](#chattermessages)
  - [Changes](#changes)

## Description
This program simulates the game of "craps".

## Functions
- ### showRules
```c
void showRules(void)
```
  showRules() takes no parameters and returns nothing. All it does is prints out the game rules to the console like this:

  ```
========================= Rules =========================
1.) Pick a number
2.) Roll Dice
  i.) If the sum of the dice is 7 or 11, then you win.
  ii.) If the sum is 2, 3, or 12, you lose.
  iii.) If the sum is 4, 5, 6,8, 9, or 10, add that sum to your score until you hit your mark. Skip to step 3.
    * Note: if you roll a 7 or 11 after the first roll, you lose
3.) If you made it this far, keep rolling until you either hit your mark and you win or you roll a 7 or 11 and you lose.
=========================================================
  ```
- ### getBankBalance
```c
double getBankBalance (void)
```

- ### getWagerAmount
```c
double getWagerAmouunt (void)
```

- ### checkWagerAmount
```c
int checkWagerAmount (double wager, double balance)
```

- ### rollDie
```c
int rollDie (void)
  ```

- ### calculateDiceSum
```c
int calculateDiceSum (int die1_value, int die2_value)
```

- ### firstRollVerdict
```c
int firstRollVerdict (int sum_dice)
```

- ### successiveRollVerdict
```c
successiveRollVerdict(int sum_dice, int point_value)
```

- ### adjustBankBalance
```c
adjustBankBalance (double bankBalance, double wagerAmount, int addOrSubtract)
```

- ### chatterMessages
```c
void chatterMessages (int numRolls, int verdict, double initialBalance, double currentBalance)
```
  
## Changes