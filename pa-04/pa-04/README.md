# Programming Assignment 4: "Craps"

  - [Description](#description)
  - [Functions](#functions)
    - [printGameRules](#printgamerules)
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
- ### printGameRules
```c
void printGameRules (void)
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