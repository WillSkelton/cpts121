# Will's Programming Assignment #3
[[toc]]

## Description: 
This program takes a file named "input.dat" with five student's records and processes them. Then, it outputs the following calculations to two files named "output.dat" **and**  "output.md". Output.md is a markdown file that I added just for fun. 

## Some information for the Grader:

**NOTE:** If you're reading this in a plain-text, you can go to [github.com/WillSkelton/cpts121](https://github.com/WillSkelton/cpts121/tree/master/pa-03/pa-03) ***OR*** you can checkout the README.html. Either of which will be way easier on the eyes.

I modified a number of functions to work a little differently from the ones given in the assignment. Most of the modifications involve storing data in arrays to organize my variables a little more or changing algorithms to accommodate an array. Also, I recognize that having parallel arrays can be hazardous but C doesn't have hash-maps so I did it this way. The changes are as follows:

  - #### calculateSums
    calculateSums now takes an *array of doubles*. I did this to avoid having 5 parameters in a function but to also keep things a little more organized. Now, calculateSums traverses an array of 5 doubles and returns the sum.
  ```c
  double calculateSums(double nums[])
  {
  	double sum = 0.0;
  	
  	for (int i = 0; i < 5; i += 1)
  	{
  		sum += nums[i];
  	}
  
  	return sum;
  
  }
  ```
  
  - #### calculateVariance
    calculateVariance also takes an array of doubles now. Again, this was done to avoid having a large number of parameters and to increase organization.
  ```c
  double calculateVariance(double deviations[], int num)
  {
  	double variance = 0.0;
  
  	for (int i = 0; i < 5; i += 1) {
  		variance += pow(deviations[i], 2);
  	}
  
  	variance /= num;
  
  	return variance;
  }
  ``` 
  - #### findMax
  findMax uses a loop to traverse through an array and find the largest element.
  ```c
  
  double findMax(double nums[])
  {
  	double max = 0.0;
  	for (int i = 0; i < 5; i += 1) {
  		if (max < nums[i]) {
  			max = nums[i];
  		}
  	}
  	return max;
  }
  ```
  
  - #### findMin
    findMin does the exact same thing as findMax except it finds the smallest element. 
  ```c
  double findMin(double nums[])
  {
  	double min = nums[0];
  	for (int i = 0; i < 5; i += 1) {
  		if (min > nums[i]) {
  			min = nums[i];
  		}
  	}
  	return min;
  }
  ```
  
  - #### printMD
    printMD is *new*. It takes an array of 6 doubles and prints the array to a markdown file. This was mainly done for fun and to see if I could use `fscanf()` on a `*.md` file. When it worked, I kept it in.
  ```c
  void printMD(FILE *markdown, double nums[])
  {
  	fprintf(markdown, "# Results:\n");
  
  	for (int i = 0; i < 6; i += 1) {
  		fprintf(markdown, "  - %.2f\n", nums[i]);
  	}
  }
  ```
  
  - #### main
    There is obviously a lot more to main than this snippet, but this was important because of the other modifications I made. I did this to either have 20 lines that all called `readDouble();` or I'd have to traverse the file multiple times. The first is disorganized, the second is ineffective, and neither one scales to larger file sizes. This way let me go through the file *once* and put each thing it it's respective "box". However, one slight downside was that in order to use the same function for 4 types of data from the file, I had to put the *student ids* and *class standings* into doubles. However, we don't use the SIDs and the class standings get averaged anyways so I figured that it wouldn't be an issue in this case.
    
  ```c
    // Traverse the data file and get records
	for (int i = 0; i < 5; i += 1) {
		SIDs[i] = readDouble(infile);

		GPAs[i] = readDouble(infile);

		classStandings[i] = readDouble(infile);

		ages[i] = readDouble(infile);
	}
  ```
