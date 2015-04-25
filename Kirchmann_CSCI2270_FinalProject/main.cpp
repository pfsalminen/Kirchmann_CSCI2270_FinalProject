#include <statisticsLibrary.h>
#include <iostream>
#include <mgl2/mgl.h>
using namespace std;

int main()
{
    statisticsLibrary stat(1);//initialize a statisticsLibrary object, contains a data vector of size 1


    //stat.printData();
    //cout<<stat.mean()<<endl;
    //cout<<stat.median()<<endl;
    //cout<<stat.standardDeviation()<<endl;
    stat.fillRandomData(100,500,1000);
    //stat.sortDataMinToMax();
    stat.printData();
    stat.writeDatatoFile();
    stat.~statisticsLibrary();
    //stat.printData();
    return 0;
}
