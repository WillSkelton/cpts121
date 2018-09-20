#include <stdio.h>
#include <math.h>

/**************************************************************************
* Function: calculateSums                                                 *
* Date Created: 9/19/18                                                   *
* Date Last Modified: 9/19/18                                             *
* Description: loops through a 5 element array of doubles and returns sum *
* Input Parameters: 5 element array of doubles                            *
* Returns: sum of all doubles in the array                                *
* Preconditions: call main                                                *
* Postconditions: n/a                                                     *
**************************************************************************/
double calculateSums(double nums[]);

/**************************************************************************
* Function: calculateMean                                                 *
* Date Created: 9/19/18                                                   *
* Date Last Modified: 9/19/18                                             *
* Description: Takes a sum and a number of values and find the average    *
* Input Parameters: a double sum of numbers and an int number of items    *
* Returns: the mean (sum / num)                                           *
* Preconditions: run main and then tun calculateSums to get a sum         *
* Postconditions: N/A                                                     *
**************************************************************************/
double calculateMean(double sum, int num);

/**************************************************************************
* Function: calculateMean                                                 *
* Date Created: 9/19/18                                                   *
* Date Last Modified: 9/19/18                                             *
* Description: takes a number and a mean and calculates the deviation     *
* Input Parameters: double number and double mean                         *
* Returns: double deviation                                               *
* Preconditions: run main > calculateSums > calculateMean                 *
* Postconditions: N/A                                                     *
**************************************************************************/
double calculateDev(double num, double mean);

/**************************************************************************
* Function: calculateVariance                                             *
* Date Created: 9/19/19                                                   *
* Date Last Modified: 9/19/19                                             *
* Description: calculates the variance of all the numbers in an array     *
* Input Parameters: a array of doubles devieations and an int num         *
* Returns: double variance                                                *
* Preconditions: run main > calculateSums > calculateMean > calculate Dev *
* Postconditions: N/A                                                     *
**************************************************************************/
double calculateVariance(double deviations[], int num);

/******************************************************************************************
* Function: calculateStandardDev                                                          *
* Date Created: 9/19/18                                                                   *
* Date Last Modified: 9/19/18                                                             *
* Description: calculates the standart deviation based on a given variance                *
* Input Parameters: double variance                                                       *
* Returns: double standard deviation                                                      *
* Preconditions: main > calculateSums > calculateMean > calculateDev > calculate variance *
* Postconditions: N/A                                                                     *
******************************************************************************************/ 
double calculateStandardDev(double variance);

/*************************************************************
* Function: findMax                                          *
* Date Created: 9/19/18                                      *
* Date Last Modified: 9/19/18                                *
* Description: finds the largest number in a 5 element array *
* Input Parameters: double nums[] (Must be 5 elements long)  *
* Returns: double max number                                 *
* Preconditions: main                                        *
* Postconditions: N/A                                        *
*************************************************************/
double findMax(double nums[]);

/**************************************************************
* Function: findMin                                           *
* Date Created: 9/19/18                                       *
* Date Last Modified: 9/19/18                                 *
* Description: finds the smallest number in a 5 element array *
* Input Parameters: double nums[] (Must be 5 elements long)   *
* Returns: double min number                                  *
* Preconditions: main                                         *
* Postconditions: N/A                                         *
**************************************************************/
double findMin(double nums[]);

/**************************************************************
* Function: readDouble                                        *
* Date Created: 9/19/18                                       *
* Date Last Modified: 9/19/18                                 *
* Description: Takes a FILE and reads the next double from it *
* Input Parameters: a file to parse                           *
* Returns: the next double in the file                        *
* Preconditions: run main                                     *
* Postconditions: N/A                                         *
***************************************************************/
double readDouble(FILE *infile);

/**************************************************************
* Function: readInt                                           *
* Date Created: 9/19/18                                       *
* Date Last Modified: 9/19/18                                 *
* Description: Takes a FILE and reads the next int from it    *
* Input Parameters: a file to parse                           *
* Returns: the next int in the file                           *
* Preconditions: run main                                     *
* Postconditions: N/A                                         *
***************************************************************/
int readInteger(FILE *infile);

/**************************************************************
* Function: printDouble                                       *
* Date Created: 9/19/18                                       *
* Date Last Modified: 9/19/18                                 *
* Description: Takes a FILE and prints a double to it         *
* Input Parameters: a file to print to and a number to print  *
* Returns: nothing                                            *
* Preconditions: run main                                     *
* Postconditions: N/A                                         *
***************************************************************/
void printDouble(FILE *outfile, double num);

/***************************************************************
* Function: printMD                                            *
* Date Created: 9/19/18                                        *
* Date Last Modified: 9/19/18                                  *
* Description: Takes an array and prints it to a markdown file *
* Input Parameters: a file to print to and an array to print   *
* Returns: nothing                                             *
* Preconditions: run main                                      *
* Postconditions: N/A                                          *
****************************************************************/
void printMD(FILE *markdown, double nums[]);

