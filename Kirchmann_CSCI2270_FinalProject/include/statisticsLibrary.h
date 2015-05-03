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
		void addDataPoint(float num,int i);
        void sortDataMinToMax();
        float mean();
        float median();
        float standardDeviation();
        float variance();
        virtual ~statisticsLibrary();
        void printData();
        void writeDatatoFile(char*);
        float maxVal();
        float minVal();
        void fillRandomData(int n_elements,int minVal,int maxVal);
    protected:
    private:
        void bubbleSort();
        void quickSort(float,float);


};

#endif // STATISTICSLIBRARY_H
