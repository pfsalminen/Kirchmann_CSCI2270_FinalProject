# Kirchmann_CSCI2270_FinalProject

Project Description

Function prototype:
void statisticsLibrary::statisticsLibrary(int)

Function description:
Method to create a statisticsLibrary object.

Example:
statisticsLibrary stat(0);

Pre-conditions:
Post-conditions: Has a statisticsLibrary object that can be filled with data.



Function Prototype:
void statisticsLibrary::fillRandomData(int,int,int)

Function description: Method to fill n_elements (extends the vector if it is smaller than n_elements)
of the vector with random data, random data is set to be between a mininum and maximum value.

Example:
statisticsLibrary stat(0);
stat.fillRandomData(10,1,100);

Pre-conditions: Must have initialized a statisticsLibrary object, n_elements is a non-negative integer
Post-conditions: n_elements first elements in data vector now filled with numbers between minVal and maxVal



Function prototype:
void statisticsLibrary::printData()

Function description:
Method to print all data in vector called data.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
stat.printData();

Pre-conditions: Must create a statisticsLibrary object
Post-conditions: Prints all values in vector data



Function prototype:
float statisticsLibrary::mean()

Function description:
Method to get mean of data.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
stat.mean();

Pre-conditions: Must create a statisticsLibrary object
Post-conditions: Returns float mean


/*
Function prototype:
void statisticsLibrary::sortDataMinToMax()

Function description:
Method to sort all data in vector called data from lowest to highest, the user chooses which method
that is to be used to do the sorting, quicksort or bubblesort.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
stat.sortDataMinToMax();
1

Pre-conditions: Must create a statisticsLibrary object
Post-conditions: All data will be sorted from lowest to highest number



Function prototype:
void statisticsLibrary::sortDataMinToMax()

Function description:
Method to sort all data in vector called data from lowest to highest using the bubblesort algorithm

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
stat.sortDataMinToMax();
1

Pre-conditions: Must create a statisticsLibrary object
Post-conditions: All data will be sorted from lowest to highest number





Function prototype:
void statisticsLibrary::sortDataMinToMax()

Function description:
Method to sort all data in vector called data from lowest to highest, using the quicksort algorithm

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
stat.sortDataMinToMax();
2

Pre-conditions: Must create a statisticsLibrary object
Post-conditions: All data will be sorted from lowest to highest number





Function prototype:
float statisticsLibrary::standardDeviation()

Function description:
Finds the standard deviation of data in vector.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
float std = stat.standardDeivation();
cout<<std<<endl;

Pre-conditions: Must create a statisticsLibrary object
Post-conditions: Returns a float that is the standard deviation of the data collection.




Function prototype:
float statisticsLibrary::median()

Function description:
Method to get the median of data.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
stat.sortDataMinToMax();
1 //user input when running code
float meanVal = stat.mean();

Pre-conditions: Must create a statisticsLibrary object and must have sorted it
Post-conditions: Returns the value in the middle of the data collection, if number of elements is not divisible by 2 it
returns the mean of the two values.




Function prototype:
float statisticsLibrary::maxVal()

Function description:
Method to sort find the maximum value in data vector.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
float maxVal= stat.maxVal();
cout<<maxVal<<endl;

Pre-conditions: Must create a statisticsLibrary object and have >1 element in it
Post-conditions: Returns a float with the highest value in the data vector. Returns -1 if the vector is empty






Function prototype:
float statisticsLibrary::minVal()

Function description:
Method to sort find the minimum value in data vector.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
float minVal= stat.minVal();
cout<<maxVal<<endl;

Pre-conditions: Must create a statisticsLibrary object and have >1 element in it
Post-conditions: Returns a float with the highest value in the data vector. Returns 1000000 if the vector is empty




Function prototype:
void statisticsLibrary::writeDataToFile(char*)

Function description:
Method to print data and write to a png file.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
stat.writeDataToFile("filename.png"):

Pre-conditions: Must create a statisticsLibrary object, must include .png in filename
Post-conditions: Creates a png file in the same directory as the code




Function prototype:
float statisticsLibrary::variance()

Function description:
Method to sort find the variance of data vector.

Example:
statisticsLibrary stat;
stat.fillRandomData(100,1,100);
float variance= stat.variance();
cout<<variance<<endl;

Pre-conditions: Must create a statisticsLibrary object and have >1 element in it
Post-conditions: Returns a float with the variance





Function prototype:
statisticsLibrary::~statisticsLibrary()

Function description:
Method to destroy statisticsLibrary object.

Example:
c++ calls this function as soon as we run out of scope

Pre-conditions: Must create a statisticsLibrary object and have >1 element in it
Post-conditions: statisticsLibrary object memory is deallocated
