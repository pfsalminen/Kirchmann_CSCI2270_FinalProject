/*This file has been modified by pfsalminen to include the addDataPoint function
which is used to input data from a file*/

#include "vector" //used to store data
#include <iostream>
#include <math.h> //used for random number generator
#include "statisticsLibrary.h"
#include <time.h> //used for random number generator
#include <mgl2/mgl.h>//used to write plot to file
using namespace std;

/*
Function prototype:
void statisticsLibrary::statisticsLibrary(int)

Function description:
Method to create a statisticsLibrary object.

Example:
statisticsLibrary stat(0);

Pre-conditions:
Post-conditions: Has a statisticsLibrary object that can be filled with data.
*/
statisticsLibrary::statisticsLibrary(int size)
{
    //ctor
    vector<float> data (size);
}

/*This function is part of the contribution by pfsalminen.
This runs automatically from main if a data file is going to
be used instead of random numbers. It takes in the data point,
and the location in the vector. Since the program was initially
built to graph data vs. element number, this contribution is build
to take in a list of data points, each point on its own line.
It will not take in x, y points*/
void statisticsLibrary::addDataPoint(float num, int i) {
    if (i>=data.size())
        data.push_back(num);
    else
        data[i] = num;
}

/*
Function Prototype:
void statisticsLibrary::fillRandomData(int,int,int)

Function description: Method to fill n_elements (extends the vector if it is smaller than n_elements)
of the vector with random data, random data is set to be between a mininum and maximum value.

Example:
statisticsLibrary stat(0);
stat.fillRandomData(10,1,100);

Pre-conditions: Must have initialized a statisticsLibrary object, n_elements is a non-negative integer
Post-conditions: n_elements first elements in data vector now filled with numbers between minVal and maxVal
*/
void statisticsLibrary::fillRandomData(int n_elements, int minVal,int maxVal){
    float randVal;
    srand(time(NULL));//if I don't have an input to the algorithm it will give me the some values each time this function is called
    for (int i = 0;i<n_elements;i++){
        randVal = rand() % maxVal + minVal;
        if (i>=data.size()){
            data.push_back(randVal);
        }else{
            data[i]=randVal;
        }

    }

}


/*
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
*/

void statisticsLibrary::printData(){
    for (int i = 0;i<data.size();i++){
        cout<<data[i]<<endl;
    }
}

/*
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
*/
float statisticsLibrary::mean(){
    float sum =0;
    int sizeOfData = data.size();
    for (int i=0;i<sizeOfData;i++){
        sum = data[i] + sum;
    }
    return sum/data.size();
}



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
*/
void statisticsLibrary::sortDataMinToMax(){
    int input;
    cout<<"Use bubble to sort (1) or quicksort(2)?"<<endl;
    cin >> input;
    switch (input)
    {
        case 1:
            //bubbleSort
            bubbleSort();
            break;

        case 2:
            //quicksort
            quickSort(data[0],data[data.size()-1]);
            break;
    }
}


/*
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
*/
void statisticsLibrary::bubbleSort(){ //n is the size of the array
    float temp;
    int sizeOfData = data.size();
    for(int c = 0; c < sizeOfData - 1; c++){
        for(int d = 0; d < sizeOfData - c - 1; d++){
            if(data[d] > data[d+1]){
                temp= data[d];
                data[d] = data[d+1];
                data[d+1] = temp;
            }
        }
    }
}
/*
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
*/
void statisticsLibrary::quickSort(float left, float right){
     float i = left;
     float j = right;
     float tmp;
     float pivot = data[(left + right) / 2];
     while(i <= j){
          while(data[i] < pivot)
               i++;
          while(data[j] > pivot)
               j--;
          if(i <= j){
               tmp = data[i];
               data[i] = data[j];
               data[j] = tmp;
               i++;
               j--;
          }
     }
     if (left < j)
          quickSort( left, j);
     if (i < right)
          quickSort(i, right);
}



/*
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
*/
float statisticsLibrary::standardDeviation(){
    float meanVal=mean();
    float sum_deviation=0.0;
    int dataSize=data.size();
    for(int i=0; i<dataSize;++i)
        sum_deviation+=(data[i]-meanVal)*(data[i]-meanVal);
    return sqrt(sum_deviation/dataSize);


}


/*
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
*/
float statisticsLibrary::median(){
    //have to sort it first, have a boolean sorted?
    //force to sort here even though it has been sorted?
    int sizeOfData = data.size();
    if ((sizeOfData% 2) == 0) {
        return (data[sizeOfData/2] + data[(sizeOfData/2) - 1])/2;
    } else {
        return data[sizeOfData/2];
    }
}

/*
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
*/
float statisticsLibrary::maxVal(){
    float maximum=-1;
    for (int i =0;i<data.size();i++){
        if (maximum<data[i]){
            maximum = data[i];
        }
    }
    return maximum;
}



/*
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
*/
float statisticsLibrary::minVal(){
    int minimum=1000000; //initialize with really high number
    for (int i =0;i<data.size();i++){
        if (minimum>data[i]){
            minimum= data[i];
        }
    }
    return minimum;
}


/*
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
*/
void statisticsLibrary::writeDatatoFile(char *fileName){

    int a;
    mglGraph *gr = new mglGraph(1000, 2000);
    gr->Clf(0,0,100);
    mglData y(data.size());
    for (int i = 0;i<data.size();i++){
        y.a[i] = data[i];//transfer data from vector to math gl to be able to plot it
        gr->Alpha(true);
        gr->Light(true);
    }
    gr->SetRange('x',0,data.size());//x axis adjusted after size of data
    gr->SetRange('y',minVal(),1.2*maxVal());// y-axis adjusted after max and min element in data
    gr->Plot(y);

    gr->Title("Plot of data (y-axis) vs element number (x-axis)");
    gr->SetTicks('x');

    gr->SetTicks('y');            // logarithmic
    gr->SetTuneTicks(true);

    gr->Box();
    gr->Label('x', "Element number", 0);
    gr->Label('y', "Data value", 0);
    gr->Axis("xy");

    gr->WritePNG(fileName);    // Don't forget to save the result!
    delete gr;

}


/*
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
*/
float statisticsLibrary::variance(){
   float meanVal = mean();

        float temp = 0;
        for(int i = 0; i < data.size(); i++)
        {
             temp += (data[i] - meanVal) * (data[i] - meanVal) ;
        }
        return temp / data.size();
}


/*
Function prototype:
statisticsLibrary::~statisticsLibrary()

Function description:
Method to destroy statisticsLibrary object.

Example:
c++ calls this function as soon as we run out of scope

Pre-conditions: Must create a statisticsLibrary object and have >1 element in it
Post-conditions: statisticsLibrary object memory is deallocated
*/
statisticsLibrary::~statisticsLibrary()
{
    //dtor

}
