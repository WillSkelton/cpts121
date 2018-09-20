#include <stdio.h>
#include <math.h>

/******************************************************
* Function:                                           *
* Date Created:                                       *
* Date Last Modified:                                 *
* Description:                                        *
* Input Parameters:                                   *
* Returns:                                            *
* Preconditions:                                      *
* Postconditions:                                     *
******************************************************/
double calculateSums(FILE *infile);

/******************************************************
* Function:                                           *
* Date Created:                                       *
* Date Last Modified:                                 *
* Description:                                        *
* Input Parameters:                                   *
* Returns:                                            *
* Preconditions:                                      *
* Postconditions:                                     *
******************************************************/
double calculateMean(double sum, int num);

/******************************************************
* Function:                                           *
* Date Created:                                       *
* Date Last Modified:                                 *
* Description:                                        *
* Input Parameters:                                   *
* Returns:                                            *
* Preconditions:                                      *
* Postconditions:                                     *
******************************************************/
double calculateDev(double num, double mean);

/******************************************************
* Function:                                           *
* Date Created:                                       *
* Date Last Modified:                                 *
* Description:                                        *
* Input Parameters:                                   *
* Returns:                                            *
* Preconditions:                                      *
* Postconditions:                                     *
******************************************************/
double calculateVariance(double dev1, double dev2, double dev3, double dev4, double dev5, int num);

/******************************************************
* Function:                                           *
* Date Created:                                       *
* Date Last Modified:                                 *
* Description:                                        *
* Input Parameters:                                   *
* Returns:                                            *
* Preconditions:                                      *
* Postconditions:                                     *
******************************************************/
double calculateStandarddev(double variance);

/******************************************************
* Function:                                           *
* Date Created:                                       *
* Date Last Modified:                                 *
* Description:                                        *
* Input Parameters:                                   *
* Returns:                                            *
* Preconditions:                                      *
* Postconditions:                                     *
******************************************************/
double findMax(double num1, double num2, double num3, double num4, double num5);

/******************************************************
* Function:                                           *
* Date Created:                                       *
* Date Last Modified:                                 *
* Description:                                        *
* Input Parameters:                                   *
* Returns:                                            *
* Preconditions:                                      *
* Postconditions:                                     *
******************************************************/
double findMin(double num1, double num2, double num3, double num4, double num5);

