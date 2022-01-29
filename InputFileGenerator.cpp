/*  Copyright 2021 - CSCE 350
    Written by Christopher Lee
*/
#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//Function to fill the array with random numbers.
void fillArray(float arr[], int size)
{
    random_device random;

//Using the Mersenne Twister 19937 generator
    mt19937 ranNum(random());

//Distribute values between -100 and 100
    uniform_real_distribution<> dist(-100, 100);

//For loop to fill array with the parameters mentioned above.
    for (int i = 0; i < size; i++)
    {
        arr[i] = dist(ranNum);
    }

}

//Function to output Array into a .txt file
void writeOutput(float *arr, int SIZE, int count)
{

/*  Created a file nomenclature in which each file created will have a name like: 'input(input size)-(file number)'
    The file number is a running count in main within a loop, this will allow us to incrementally create a new input file so 
    it doesn't overwrite the previous input file due to the same name.
*/
    ofstream file("input" + to_string(SIZE) + "-" + to_string(count) + ".txt");

//For loop to write the array into our file, the precision was set at 5.
    for (int i = 0; i < SIZE; i++)
    {
        file << setprecision(5) << arr[i] << endl
             << endl;
    }

    file.close();
}

int main()
{

//Can change this SIZE variable to whatever input file you want (ie 10, 100, 1000, etc.)
    int SIZE = 100;

    float numGen[SIZE];

//This will be the number of files you want to create, so for our project we wanted to make 100 files of an input size.
    int numFiles = 100;

//This is the running count we'll use in our loop that will be added to the file name and increment to avoid overwriting previous file.
    int count = 0;

//For loop that calls our fillArray function to fill the array, writeOutput to write our array into a file, and increase our count for the file name.
    for (int i = 0; i < numFiles; i++)
    {
        fillArray(numGen, SIZE);

        writeOutput(numGen, SIZE, count);

        count++;
    }

    return 0;
}