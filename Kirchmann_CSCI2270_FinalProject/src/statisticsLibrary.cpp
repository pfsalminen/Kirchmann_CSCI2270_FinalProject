#include "vector"
#include <iostream>
#include<math.h>
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
    int sizeOfData = data.size();
    for (int i=0;i<sizeOfData;i++){
        sum = data[i] + sum;
    }
    return sum/data.size();
}


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


float statisticsLibrary::standardDeviation(){
    float meanVal=mean();
    float sum_deviation=0.0;
    int dataSize=data.size();
    for(int i=0; i<dataSize;++i)
        sum_deviation+=(data[i]-meanVal)*(data[i]-meanVal);
    return sqrt(sum_deviation/dataSize);


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
