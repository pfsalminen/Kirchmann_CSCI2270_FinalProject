#include "vector"
#include <iostream>
#include<math.h>
#include "statisticsLibrary.h"
#include <time.h>
using namespace std;

/*
statisticsLibrary(int)
Constructor, creates a vector of floats of input size
Example of function call: statisticsLibrary(10) input has to be nonnegative
No pre or post conditions
*/
statisticsLibrary::statisticsLibrary(int size)
{
    //ctor
    vector<float> data (size);
}



/*
Prototype: fillRandomData(int,int,int)
Method to fill n_elements (extends the vector if it is smaller than n_elements) of the vector with random data, random data is set to be between a mininum and maximum value.
Example of function call: fillRandomData(10,1,100);
No pre- or post-conditions
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
Method to print data in vector "data"
Pre-conditon: Must have created a statisticsLibrary object and inserted values to datavector
*/
void statisticsLibrary::printData(){
    for (int i = 0;i<data.size();i++){
        cout<<data[i]<<endl;
    }
}

float statisticsLibrary::mean(){
    float sum =0;
    int sizeOfData = data.size();
    for (int i=0;i<sizeOfData;i++){
        sum = data[i] + sum;
    }
    return sum/data.size();
}


/*
Method that gives the user the option to sort the data by using two different sorting algorithms
Pre-condition: user must have called the constructor and initialized the vector, the user must also have filled it with values
since there is nothing to sort otherwise.
*/
void statisticsLibrary::sortDataMinToMax(){
    int input;
    cout<<"Use bubble to sort (1) or blabla (2)?"<<endl;
    cin >> input;
    switch (input)
    {
        case 1:
            //bubbleSort
            bubbleSort();
            break;

        case 2:
            //other kind of sort
            break;

    }
}


/*
bubblesort()
Method that sorts data to be from low to high in data vector.
bubbleSort()
Pre-condition: Must have data to sort before calling bubbleSort
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
R
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


float statisticsLibrary::standardDeviation(){
    float meanVal=mean();
    float sum_deviation=0.0;
    int dataSize=data.size();
    for(int i=0; i<dataSize;++i)
        sum_deviation+=(data[i]-meanVal)*(data[i]-meanVal);
    return sqrt(sum_deviation/dataSize);


}


/*
median()
Method that returns the median of data in vector.
Example call: median()
Pre-condition: Must have inserted data and also sorted it using any sorting algorithm
*/
float statisticsLibrary::median(){
    //have to sort it first, have a boolean sorted?
    //force to sort here even though it has been sorted?
    float median;
    int sizeOfData = data.size();
    if ((sizeOfData% 2) == 0) {
        return (data[sizeOfData/2] + data[(sizeOfData/2) - 1])/2;
    } else {
        return data[sizeOfData/2];
    }
}



statisticsLibrary::~statisticsLibrary()
{
    //dtor
}
