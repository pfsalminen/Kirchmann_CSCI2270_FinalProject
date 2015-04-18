#include <iostream>
#include "statisticsLibrary.h"

//create mean, sort, variance, max, min

//use a vector
using namespace std;

int main()
{
    statisticsLibrary stat(19);
    for (float i = 0;i<19;i++){
        stat.data.push_back(i);
    }
    for (float i = 0;i<19;i++){
        stat.data.insert(stat.data.begin()+i,i);
    }
    stat.printData();
    cout<<stat.mean()<<endl;
    cout<<stat.median()<<endl;

    return 0;
}
