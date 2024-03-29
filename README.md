# Implementing the Quick-Sort Algorithm using C++

## Goal

This project reads an input ASCII file that contains unsorted floating-point numbers separated by a blank space. It then sorts the values using the quicksort method by choosing a pivot using the median-of-three method. Finally, it produces an output ASCII file that contains the sorted floating-point numbers separated by a blank space.

## Usage

To compile this program, you just need to run `make`, but in case it's not possible, you can do:

```
g++ -O2 -std=c++11 -lm -Wall -Wpedantic -o quicksort Lee_Christopher_QuickSort.cpp
```

To run it, you start the `quicksort` binary.

`quicksort` accepts two parameters:

The first parameter is the input ASCII filename the user wants to read.  This file should be in the same directory as the quicksort binary file.

The second parameter is the output ASCII filename the user wants to create.

## Description

### Lee_Christopher_QuickSort.cpp

In this program, we take in two arguments, the first is the input file the program parses through to fill an array with float values.  The second argument will be the filename in which the program will write to after successfully sorting the array.

To parse the file, we use a while loop with fscanf to search through the file, line by line for float values.  The while loop is used so that it reads through the entire file until it reaches a point where there is no longer any values (ie. the end).  Within the loop we insert each found float value into our array as well as increment our 'size' variable which will be used later when we output to our file.

Once the array has been filled via the `readInput` function, we then call our `quickSort` function which recursively calls `quickSort` after establishing the pivot and partitions to sort both halves of the partition.  

Firstly, the `quickSort` function calls the `partition` function.  The `partition` function is used to find our pivot (using the median of three).  The pivot is found by examining the first, middle, and last element of the array.  It compares these 3 values against one another to find the highest value and swaps this value to the end of the array, and establishes this as our pivot.  Once a pivot is established, it uses Lomuto's algorithm to traverse and partition the array (lower values than pivot to the left of the pivot, greater values than the pivot to the right of the pivot).

Once the `partition` function completes, it has now established a pivot and 2 partitions.  We now recursively call `quickSort` to sort our respective sides of the partition.  The first quickSort call is the 'left' half of the partition, in which it calls the first element of the array and its last element is 1 element BEFORE the partition (p-1).  The second quickSort call handles the 'right' side of the partition by calling its first element 1 element AFTER the partition (p+1) and the last element of the array. 

Once the `quickSort` function completes, the array has been fully sorted so we then call `writeOutput` function to write the contents of our array into a text file.  The name of the text file was established as the second argument for our program.


### InputFileGenerator.cpp

In this program, we generate 100 ASCII input files for a particular input size. The input size can be altered in the code by changing 'SIZE' in main to the user's specification.

Once the size is established, the program will create an array of that size. It will then completely fill this array (fillArray function) with random numbers between -100 to 100. The random numbers are generated by the mersenne twister 19937 generator.

Once the array is filled, the writeOutput function is called to create the output ASCII file. The function creates a file using the filename convention: "input", followed by the SIZE as designated by the user, followed by "-", followed by an increasing 'count' number for each file created, finally ended by the extention ".txt". The file is then written into, pulling in the values of each of the elements of the array. The precision was set to 5 and also created a blank space between each array element.

Lastly, a for-loop was created in main to run the fillArray and writeOutput functions. The loop will run 100 times (or however much numFiles is set to) to create all of the input files. A 'count' variable is added at the end of the for-loop which will continue to grow after each loop; this was used to differentiate the filenames as described earlier.

## Resource Links Used

- [Mersenne Twister 19937 Generator](https://www.cplusplus.com/reference/random/mt19937/)
- [Uniform Real Distribution](https://www.cplusplus.com/reference/random/uniform_real_distribution/)
- [MakeFile Tutorial](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/)

