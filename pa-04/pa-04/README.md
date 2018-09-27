# Programming Assignment 4: "Craps"

[[toc]]
## Description
## Functions

### Print Game Rules
  ```c
  void print_game_rules (void)
  ```

### Get Bank Balance
  ```c
  double get_bank_balance (void)
  ```

### Get Wager Amouunt
  ```c
  double get_wager_amount (void) 
  ```
  
### Check Wager Amount
```c
  int check_wager_amount (double wager, double balance)
```

### Roll Die
  ```c
  int roll_die (void)
  ```
  
### Calculate Sum of Dice
  ```c
  int calculateDiceSum (int die1_value, int die2_value) 
  ```

### 1st Roll Verdict
  ```c
  int firstRollVerdict (int sum_dice)
  ```

### Successive Roll Verdict
  ```c
  int successiveRollVerdict(int sum_dice, int point_value)
  ```

### Adjust Bank Balance
  ```c
  adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
  ```

### Chatter Message
  ```c
  void chatter_messages (int numRolls, int verdict, double initialBalance, double currentBalance)
  ```
 ## Changes made to starting functions