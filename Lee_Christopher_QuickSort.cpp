/*  Copyright 2021 - CSCE 350
    Written by Christopher Lee

    Please read ReadMe file for instructions to compile, run, and synopsis of program.

    If you want to just compile and run; just run 'make' to compile.
    Run 'quicksort' with two arguments, the first argument is the input file name and the second is the output file name.

*/

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

//Function to swap 2 values which we will call later in our partition function in which we will swap the elements of an array.
void swapFloat(float *a, float *b)
{
    float c = *a;
    *a = *b;
    *b = c;
}
//Partition Function to find our pivot (using median of three) and then swap the values when conditions are met; will be called in our QuickSort function later.
int partition(float arr[], int first, int last)
{

//Finding our pivot (arr[high]) using the median of three (low, mid, and high)
    int low = first;
    int high = last;
    int mid = ((first + last) /2);

    if (arr[mid] < arr[low])
    {
        swapFloat (arr+low, arr+mid);
    }

    if (arr[high] < arr[low])
    {
        swapFloat (arr+low, arr+high);
    }

    if (arr[mid] < arr[high])
    {
        swapFloat (arr+mid, arr+high);
    }

    float pivot = arr[high];

/*  Once pivot is established, we set our index 'i' to the first index of the array.
    We then traverse the array through a for loop with 'j', when the value at 'j' is less than or
    equal to the pivot value, we increase our index 'i' and swap the values of those at 'i' and 'j'.
*/
    int i = first;

    for (int j = first; j < last; j++)
    {
        if (arr[j] <= pivot)
        {
            swapFloat(arr + i, arr + j);
            i++;
        }
    }
    swapFloat(arr + i, arr + last);
    return i;

}

/*  Function for QuickSort, recursively call QuickSort after establishing the pivot and partitions to sort 
    both halves the partition.  So the first quickSort call is 'left' half of the partition, in which it calls
    the first element of the array and its last element is 1 element BEFORE the partition (p-1).  The second
    quickSort call handles the 'right' side of the partition by calling its first element 1 element AFTER the partition (p+1)
    and the last element of the array. 
*/
void quickSort(float arr[], int first, int last)
{
    if (first < last)
    {
        int p = partition(arr, first, last);

        quickSort(arr, first, p - 1);

        quickSort(arr, p + 1, last);
    }
}

/*  Function to read in the input file argument.  This function uses fscanf in a while loop in which it will
    parse through the entire file, line by line, and pull all of the float values.  It uses a While-loop so that
    it goes through the entire document.  Within the loop, for each floating value it finds, it adds it to our array.
    Additionally, it increases the variable 'size' which will be returned at the end of the function and
    used later on in both the quickSort and writeOutput function to establish the size of the array.
*/
int readInput(const char *file, float *arr)
{
    FILE *f = NULL;
    float num;
    f = fopen(file, "r");

    int size = 0;
    while (fscanf(f, "%f", &num) > 0)
    {
        arr[size] = num;
        size++;
    }

    fclose(f);
    return size;
}

/*  Function to write the elements of our array into a text file.  Simply uses a for loop and fprintf to go through
    the array and print the floating values of each element of the array.  Additionally added spaces after each element
    found to look similar to the input file.
*/
void writeOutput(const char *file, float *arr, int size)
{
    FILE *f = NULL;
    f = fopen(file, "w");
    int i;

    for (i = 0; i < size; i++)
    {
        fprintf(f, "%.3f\n\n", arr[i]);
    }

    fclose(f);
}

//Main function that passes in the arguments
int main(int argc, char const *argv[])
{

//Check that the there are two arguments (input & output) run with the program.  Otherwise alert the user and exit.
    if (argc < 3 || argc > 3)
    {
        fprintf(stderr, "**************************************\nIncorrect number of parameters. \nPlease provide an Input Filename and Output Filename. \n**************************************\n");
        exit(EXIT_FAILURE);
    }

//Just created a large array for us to fill.  Obviously if we're sorting input files with more than 200k values we can increase this or look to use vector instead.
    float arr[200000];

//Set the start time for our program which will be used later to measure the execution time.
    high_resolution_clock::time_point start = high_resolution_clock::now();

//Call the readInput function to read in the input file and fill our array.  Store our return size value into 'n'.
    int n = readInput(argv[1], arr);

//Call the quickSort function to sort our array.
    quickSort(arr, 0, n - 1);

//Call the writeOutput function to write our array into our output file (our second argument)
    writeOutput(argv[2], arr, n);

//Set the stop time for our clock which will be used later to calculate the execution time.
    high_resolution_clock::time_point stop = high_resolution_clock::now();

//Using duration_cast in milliseconds, determine the execution time in milliseconds by subtracting the stop time by the start time.
    duration<float> duration = duration_cast<milliseconds>(stop - start);

//Display the execution time with a precision of 5 in milliseconds.
    cout << "Execution time: "
         << setprecision(5) << duration.count() << " milliseconds" << endl;

    return 0;
}