#include <stdio.h>
#include <math.h>

#define PI = 3.14159

// ================= Getter Functions

/******************************************************
* Function: getMassAndAcceleration                    *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: Gets mass and Acceleration from user   *
and calls secondLaw() with input                  *
* Input Parameters: None                              *
* Returns: 0                                          *
* Preconditions: N/a                                  *
* Postconditions: N/a                                 *
******************************************************/
int getMassAndAcceleration(void);

/******************************************************
* Function: getRadAndHeight                           *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: Gets radians and heightfrom user       *
and calls cylinderVolume() with input             *
* Input Parameters: None                              *
* Returns: 0                                          *
* Preconditions: N/a                                  *
* Postconditions: N/a                                 *
******************************************************/
int getRadAndHeight(void);

/******************************************************
* Function: getChar                                   *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: gets char and shift value from user    *
and calls encoder() with input                    *
* Input Parameters: None                              *
* Returns: 0                                          *
* Preconditions: N/a                                  *
* Postconditions: N/a                                 *
******************************************************/
int getChar(void);

/******************************************************
* Function: getPoints                                 *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: gets 2 points from user				  *
and calls distance() with input                   *
* Input Parameters: None                              *
* Returns: 0                                          *
* Preconditions: N/a                                  *
* Postconditions: N/a                                 *
******************************************************/
int getPoints(void);

/******************************************************
* Function: getTheta                                  *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: gets theta from user				      *
and calls calcTangent() with input                *
* Input Parameters: None                              *
* Returns: 0                                          *
* Preconditions: N/a                                  *
* Postconditions: N/a                                 *
******************************************************/
int getTheta(void);

/******************************************************
* Function: getResistors                              *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: gets 3 resistor values from user	      *
and calls parallelResistance() with input         *
* Input Parameters: None                              *
* Returns: 0                                          *
* Preconditions: N/a                                  *
* Postconditions: N/a                                 *
******************************************************/
int getResistors(void);

/******************************************************
* Function: getResistors                              *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: gets some values from user	          *
and calls genEquation() with input                *
* Input Parameters: None                              *
* Returns: 0                                          *
* Preconditions: N/a                                  *
* Postconditions: N/a                                 *
******************************************************/
int getTheLastStuff(void);

// ================= Doer Functions

/******************************************************
* Function: secondLaw                                 *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: calculates force         	          *
* Input Parameters: double mass, double acceleration  *
* Returns: double force                               *
* Preconditions: run getMassAndAcceleration()         *
* Postconditions: N/a                                 *
******************************************************/
double secondLaw(double mass, double acceleration);

/******************************************************
* Function: cylinderVolume                            *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: calculates the volume of a cylinder    *
* Input Parameters: double radius, double height      *
* Returns: double volume                              *
* Preconditions: run getRadAndHeight()                *
* Postconditions: N/a                                 *
******************************************************/
double cylinderVolume(double radius, double height);

/******************************************************
* Function: encoder                                   *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: encodes character                      *
* Input Parameters: char character, int shift         *
* Returns: double character                           *
* Preconditions: run getChar()                        *
* Postconditions: N/a                                 *
******************************************************/
char encoder(char character, int shift);

/***************************************************************
* Function: distance                                           *
* Date Created: 9/13/18                                        *
* Date Last Modified: 9/13/18                                  *
* Description: calculates the distance between 2 points        *
* Input Parameters: double x1, double y1, double x2, double y2 *
* Returns: double distance                                     *
* Preconditions: run getPoints()                               *
* Postconditions: N/a                                          *
***************************************************************/
double distance(double x1, double y1, double x2, double y2);

/******************************************************
* Function: calcTangent                               *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: computes the tangent in radians        *
* Input Parameters: double theta                      *
* Returns: double tangent                             *
* Preconditions: run gatTheta()                       *
* Postconditions: N/a                                 *
******************************************************/
double calcTangent(double theta);

/******************************************************
* Function: parallelResistance                        *
* Date Created: 9/13/18                               *
* Date Last Modified: 9/13/18                         *
* Description: calculates perallel resistance         *
* Input Parameters: int r1, int r2, int r3            *
* Returns: double pr                                  *
* Preconditions: run getResistors                     *
* Postconditions: N/a                                 *
******************************************************/
double parallelResistance(int r1, int r2, int r3);

// Asks user for x, y, z and a and calculates general equation
/********************************************************
* Function: genEquation                                 *
* Date Created: 9/13/18                                 *
* Date Last Modified: 9/13/18                           *
* Description: calculates perallel resistance           *
* Input Parameters: int a, double x, double y, double z *
* Returns: double y                                     *
* Preconditions: run getTheLastStuf                     *
* Postconditions: N/a                                   *
********************************************************/
double genEquation(int a, double x, double y, double z);



