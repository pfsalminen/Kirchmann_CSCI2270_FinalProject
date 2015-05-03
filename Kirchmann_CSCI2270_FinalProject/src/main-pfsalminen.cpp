/*This main function was written by pfsalminen.
It organizes the statisticsLibrary class to improve user functionality.
It is based off of the menu organization we used throughout the semester,
giving choices for the user to tell the program what it wants to see/do.
I have also added the functionality to use a file for data. The user can
either use random data (as before), a given data file, or the user's data.
Since this was originally built to plot the data as data vs. element number,
the data file can only contain one piece of info (ie. no x,y points).
This file must also be organized so that each data point is on its own line.
See the given data file for an example of how it must be organized.
*/

#include <statisticsLibrary.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*This prints out the main menu after
each function choice has been completed*/
void printMenu() {
	cout << "1. Print Data" << endl
	<< "2. Print Stats" << endl
	<< "3. Find Max and Min Values" << endl
	<< "4. Sort Data Low to High" << endl
	<< "5. Print Data to File" << endl
	<< "6. Quit" << endl;
}

int main() {
	statisticsLibrary stat(1);  //Initialize class
    string filename = "givenData.txt";  //Set filename to the given data file
	int dataType;   //Used to find which data to use

    //Ask if user wants to use random data, the given data, or his/her own data
	cout << "Would you like to use (1) Random Data (2) Provided Data (3) Your Data" << endl;
	cin >> dataType;
    cin.clear();
    cin.ignore(10000,'\n');

	float point;
	int counter = 0;
    string line;
	if(dataType == 2) { //Create data with given file
		ifstream infile (filename);
        while (!infile.eof()) {
            getline(infile, line);
            if (line != "") {
                point = stof(line);
                stat.addDataPoint(point, counter);
                counter++;
            } else
                break;
        }
	infile.close();
	} else if(dataType == 3) {  //Create data with other file
		cout << "Enter file name: ";
		getline(cin, filename);
		ifstream infile (filename);
        while (!infile.eof()) {
            getline(infile, line);
            if (line != "") {
                point = stof(line);
                stat.addDataPoint(point, counter);
                counter++;
            } else
                break;
        }
	} else {    //Create data with random numbers. 100 points between 500 and 1500
		stat.fillRandomData(100, 500, 1000);
	}

    cout << "\nData Loaded!" << endl;
    float mini; //Variable for min value
    float maxi; //Variable for max value
    float mean; //Data mean
    float median;   //Data median
    float standev;  //Data standard deviation
    float var;  //Data variance
    int choice; //User input of which function to perform
	bool go = true; //Keep looping through function until quit
	string outName; //Name to save file to
	char* cname;    //Used to convert outName from
	while(go) {
        //Print menu and input user choice
		printMenu();
		cin >> choice;
		cin.clear();
        cin.ignore(10000,'\n');

		switch(choice) {
			case 1: //Print all data
				stat.printData();
				break;
			case 2: //Print basic data stats
				mean = stat.mean();
				median = stat.median();
				var = stat.variance();
				standev = stat.standardDeviation();
				cout << "Mean: " << mean << endl
				<< "Median: " << median << endl
				<< "Variance: " << var << endl
				<< "Standard Deviation: " << standev << endl;
				break;
			case 3: //Print data max and min
				maxi = stat.maxVal();
				mini = stat.minVal();
				cout << "Min: " << mini << "\nMax: " << maxi << endl;
				break;
			case 4: //Sort data, either quicksort or bubblesort (asked in function)
				stat.sortDataMinToMax();
				cout << "Data Sorted!" << endl;
				stat.printData();   //Print data after sort
				break;
			case 5: //Write data to file
			    cout << "Enter filename to write (end with .png): ";
			    getline(cin, outName);
                cname = new char[outName.length() + 1];
                strcpy(cname, outName.c_str());
				stat.writeDatatoFile(cname);
				break;
			case 6: //Quit program
				go = false;
				break;
			default:    //If user doesn't enter 1-6
				cout << "Invalid Choice" << endl;
				break;
			}
		}
	return 0;
}
