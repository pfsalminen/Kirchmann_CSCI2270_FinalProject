#include "vector"
#include <iostream>
#include "statisticsLibrary.h"
using namespace std;
statisticsLibrary::statisticsLibrary()
{
    //ctor
}

statisticsLibrary::statisticsLibrary(int size)
{
    //ctor
    vector<float> data (size);
}
void statisticsLibrary::sortDataMinToMax(){
    //give the option of using bubble or selection sort
}

void statisticsLibrary::printData(){
    for (int i = 0;i<data.size();i++){
        cout<<data[i]<<endl;
    }
}

float statisticsLibrary::mean(){
    float sum =0;
    for (int i=0;i<data.size();i++){
        sum = data[i] + sum;
    }
    return sum/data.size();
}

float statisticsLibrary::standardDeviation(){
}

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
