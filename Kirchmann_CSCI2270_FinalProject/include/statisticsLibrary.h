#include<vector>
#include <iostream>
#ifndef STATISTICSLIBRARY_H
#define STATISTICSLIBRARY_H

using namespace std;
class statisticsLibrary
{
    public:
        vector<float> data;
        statisticsLibrary(int dataSize);
        statisticsLibrary();
        void randomNumbers(int low_limit,int upper_limit);
        void sortDataMinToMax();
        float mean();
        float median();
        float standardDeviation();
        float variance();
        virtual ~statisticsLibrary();
        void printData();
    protected:
    private:
        void bubbleSort();
        void selectionSort();


};

#endif // STATISTICSLIBRARY_H
