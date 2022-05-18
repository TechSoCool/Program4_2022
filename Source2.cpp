// Sterling Gerard
// March 31, 2022
/*
Write a program that uses an arrays of at least 20 string . It should call a function that uses the linear search algorithm to locate one of the name.
Read list of name from an input file call "StudentName.txt"
The function should keep a count of the numbers of comparisons it makes until it finds the value.
The program then should call a function that uses the binary search algorithm to locate the same value.
It should also keep count of the numbers of comparisons it makes. Display these values to a file call "out.txt"
*/
// Required header files
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include<string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
// function prototypes
int linearSearch(string names[], string search, int cnt, int& comparisionCnt);
void binarySearchlinearSearch(string names[], string search, int cnt, int& comparisionCnt);
int main() {
    //Declaring variables
    const int SIZE = 20;
    string names[SIZE];
    string search;
    int cnt = 0,
        comparisionCnt = 0;
    ifstream dataIn;
    ofstream dataOut;
    dataIn.open("StudentName.txt"); // Open the StudentName.txt file. 
    if (dataIn.fail()) {
        cout << "** File Not Found **";
        return 1;
    }
    else {
        dataOut.open("out.txt");
        //Reading the data from the file
        while (getline(dataIn, names[cnt])) {
            cnt++;
        }
        dataIn.close();
        cout << "Enter Name to search :"; // Prompt the user to enter name for search
        getline(cin, search); // Read the value given by the user
        int index = linearSearch(names, search, cnt, comparisionCnt);
        if (index != -1) {
            cout << "No of comparisions in Linear Search :" << comparisionCnt << endl; // Displaying the number of comparisions in Linear search
            dataOut << "No of comparisions in Linear Search :" << comparisionCnt << endl;
            comparisionCnt = 0;
            binarySearchlinearSearch(names, search, cnt, comparisionCnt); // Calling the BinarySearch function and Linear Search function
            cout << "No of comparisions in Binary Search :" << comparisionCnt << endl;
            dataOut << "No of comparisions in Binary Search :" << comparisionCnt << endl;
            dataOut.close();
        }
        else {
            cout << search << " not found in the array" << endl;
            dataOut << search << " not found in the array" << endl;
            dataOut.close();
        }
    }
    return 0;
}
int linearSearch(string names[], string search, int cnt, int& comparisionCnt) { // function definition
    for (int i = 0; i < cnt; i++) {
        if (names[i].compare(search) == 0) {
            return i;
        }
        comparisionCnt++; // Increment the comparision count
    }
    return -1;
}
void binarySearchlinearSearch(string names[], string search, int cnt, int& comparisionCnt) { // function definition
   // Declaring varibles
    int low = 0;
    int flag = 0, pos;
    int high = cnt - 1;
    while (high >= low) {
        int middle = (low + high) / 2;
        if (names[middle].compare(search) == 0) {
            flag = 1;
            pos = middle;
            break;
        }
        if (names[middle].compare(search) < 0) {
            low = middle + 1;
            comparisionCnt++;
        }
        if (names[middle].compare(search) > 0) {
            high = middle - 1;
            comparisionCnt++;
        }
    }
}