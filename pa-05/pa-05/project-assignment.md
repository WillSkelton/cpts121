# Programming Assignment 5: The Game of Yahtzee

Assigned: Friday, October 5, 2018

Due: Friday, October 19, 2018 by midnight (extended date!)

## I. Learner Objectives:

At the conclusion of this programming assignment, participants should be able to:

  - Apply repetition structures within algorithms
  - Construct while (), for (), or do-while () loops in C
  - Apply pointers, output parameters, and/or arrays in C
  - Compose C programs consisting of sequential, conditional, and iterative statements
  - Eliminate redundancy within a program by applying loops and functions
  - Create structure charts for a given problem
  - Determine an appropriate functional decomposition or top-down design from a structure chart
  - Generate random numbers for use within a C program

## II. Prerequisites:

Before starting this programming assignment, participants should be able to:
  - Analyze a basic set of requirements and apply top-down design principles for a problem
  - Customize and define C functions
  - Apply the 3 file format: 1 header file and 2 source files
  -  Open and close files
  - Read, write to, and update files
  - Apply standard library functions: fopen (), fclose (), fscanf (), and fprintf ()
  - Compose decision statements ("if" conditional statements)
  - Create and utilize compound conditions
  - Summarize topics from Hanly & Koffman Chapter 4 & 5 including:
  - What are counting, conditional, sentinel-controlled, flag-controlled, and end file-controlled loops
  - What are while (), do-while (), and for () loops
  - What is a selection or conditional statement
  - What is a compound condition
  - What is a Boolean expression
  - What is a flowchart
  
## III. Overview & Requirements:

Develop and implement an interactive two-player Yahtzee game. Yahtzee is a dice game that was invented by Milton Bradley and Edwin S. Lowe in 1956. The challenge of the game is to outduel the other player by scoring the most points. Points are obtained by rolling five 6-sided die across thirteen rounds. During each round, each player may roll the dice up to three times to make one of the possible scoring combinations. Once a combination has been achieved by the player, it may not be used again in future rounds, except for the Yahtzee combination may be used as many times as the player makes the combination. Each scoring combination has different point totals. Some of these totals are achieved through the accumulation of points across rolls and some are obtained as fixed sequences of values.

### The Rules of Yahtzee: 

The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations. See the table provided below:

 
| Name            | Combination         | Score |
| :-------------: | :-----------------: | :---: |
| Three-of-a-kind | 3 dice of same face | Sum of all face values on the 5 dice|
| Four-of-a-kind  | Four dice with the same face | Sum of all face values on the 5 dice |
| Full house      | One pair and a three-of-a-kind | 25 |
| Small straight  | A sequence of four dice | 30 |
| Large straight  | A sequence of five dice | 40 |
| Yahtzee (think five-of-a-kind) | Five dice with the same face | 50 |
| Chance | May be used for any sequence of dice; this is the **catch all** combination | Sum of all face values on the 5 dice |


## What is required for this assignment?

You may design the Yahtzee game with functions that you see fit. I recommend that you start with a structure chart and determine sub-problems and functions accordingly. You must also take advantage of applying pointers, output parameters, and/or arrays! Your Yahtzee game must also implement the following algorithm:
 
  - [ ] **(5 pts)** Print a game menu for Yahtzee with the following options:

    1. Print game rules
    2. Start a game of Yahtzee
    3. Exit
  - [ ] **(5 pts)** Get a menu option from the user; clear the screen
  - [ ] **(10 pts)** 
    - If option 1 is entered: then 
      - print the game rules stated above and repeat step (1)
    - otherwise if option 2 is entered
      - continue on to step (4); player 1 starts the game
    - otherwise if option 3 is entered
      - print a goodbye message and quit the program
    - otherwise repeat step (1)

  - [ ] **(5 pts)** Ask the player to hit any key to continue on to roll the five dice

  - [ ] **(5 pts)** Roll the five dice and display the face values of each die; enumerate each die with
  - a number 1 - 5; add 1 to the total number of rolls for this round
  - [ ] **(10 pts)**
    - If the total number of rolls for this round is less than three,
      - then ask the player (Y/N) if he/she wants to use the roll for one of the game combinations

    - otherwise a combination must be selected.
      
      |               |                        |
      | :-----------: | :--------------------: |
      | 1. Sum of 1's | 7. Three-of-a-kind     |
      | 2. Sum of 2's | 8. Four-of-a-kind      |
      | 3. Sum of 3's | 9. Full house          |
      | 4. Sum of 4's | 10. Small straight     |
      | 5. Sum of 5's | 11. Large straight     |
      | 6. Sum of 6's | 12. Yahtzee            |
      |               | 13. Chance             |

  - [ ] **(15 pts)** If the number of rolls is three or "yes" is entered, then save the combination and it may not be selected again in the future
  - (Note: The selection of the combination must be verified. 
    - If the user selects full house, but does not have one, then you
      - must assign 0 points for the combination);
      - continue on to step (8); clear the screen
    
    - otherwise if "no" is entered
      - ask the user which dice to re-roll (1 - 5);
      - re-roll the selected die or dice;
      - clear the screen;
      - repeat step (6)

    - otherwise repeat step (6)

  - [ ] **(5 pts)* Alternate players

  - [ ] **(10 pts)** 
    - If each player has rolled for the round
      - increment the round number
    
      - if the round number is equal to 14
        - continue on to step (10)
     
      - otherwise repeat step (4)

    -  otherwise repeat step (4)

  - [ ] **(5 pts)** If the total score in the upper section is greater than or equal to 63 for a player, then add 35 points to the total score
  - [ ] **(5 pts)** Print the scores for both players and print the winner
  - [ ] **(5 pts)** Repeat step (1)

## IV. Expected Results:

I recommend that you check out this website http://www.yahtzeeonline.org/ to grasp the game play for Yahtzee. Of course the game you build is text based.

## V. Submitting Assignments:
Using the OSBLE+ MS VS plugin, please submit your solution. Please visit https://github.com/WSU-HELPLAB/OSBLE/wiki/Submitting-an-Assignment for more information about submitting using OSBLE+.
Your project must contain one header file (a .h file), two C source files (which must be .c files), and project workspace.
Your project must build properly. The most points an assignment can receive if it does not build properly is 65 out of 100.
 
## VI. Grading Guidelines:

This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:

 
- 85 pts for adherence to the algorithm stated above (see the individual points above)
- 10 pts for appropriate top-down design of functions and usage of pointers and/or arrays
- 5 pts for adherence to proper programming style established for the class and comments