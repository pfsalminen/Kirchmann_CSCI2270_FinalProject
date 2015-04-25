#include <statisticsLibrary.h>
#include <iostream>

using namespace std;

int main()
{
    statisticsLibrary stat(1);//initialize a statisticsLibrary object, contains a data vector of size 1

    stat.fillRandomData(100,500,1000); //fills data vector with 100 numbers betweem 500 and 1500 randomly

    stat.printData(); //prints the data in terminal

    cout<<"Mean: "<<stat.mean()<<endl; //prints the mean value of data

    stat.sortDataMinToMax();//user has to choose which sorting algorithm to use, input to terminal: 1 or 2

    cout<<"Median: "<<stat.median()<<endl; //prints the median value of data

    cout<<"Standard deviation: "<<stat.standardDeviation()<<endl; //prints the standard deviation of the data

    cout<<"Variance: "<<stat.variance()<<endl; //prints the variance of the data


    stat.printData(); //prints the data, now sorted

    stat.writeDatatoFile("testfile.png"); //writes the data to a png file with name testfile.png, remember to include .png
    return 0;
}
