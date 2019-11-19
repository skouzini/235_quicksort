#include "QS.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

QS::QS() {
    array = NULL;
}
QS::~QS() {
    delete array;
}

/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QS::sortAll() {
    
}

/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS::medianOfThree(int left, int right) {
    cout << "starting medianOfThree...\n";///////////////
    //int swaps = 0;
    if (array == NULL || (left < 0 || right > array_pos - 1) || right < left) {
        cout << "...returning -1 from medianOfThree\n";//////////////
        return -1;
    }
    else {
        int *temp;
        middle = (left + right) / 2;
        
        MedianSort(*(array + left), *(array + middle), *(array + right));
        // *(array + left) = *(temp + 0);
        // *(array + middle) = *(temp + 1);
        // *(array + right) = *(temp + 2);
        
        cout << "...returning middle from medianOfThree\n";///////////////
        return middle;
    }
}

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.  Because there are multiple ways to partition a list,
* we will follow the algorithm on page 611 of the course text when testing this function.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not within the sub-array designated by left and right.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QS::partition(int left, int right, int pivotIndex) {
    cout << "starting partition...\n";///////////////
    int tempInt;
    int median_val = *(array + pivotIndex);
    bool up_found = false;
    bool down_found = false;
    
    if (array == NULL 
    || (left < 0 || right > array_pos - 1) 
    || right < left 
    || !(pivotIndex > left && pivotIndex < right)) {
        cout << "...returning -1 from partition\n";///////////////
        return -1;
    }
    else {
        int up = left + 1;
        int down = right - 1;
        int *temp;
        MedianSort(*(array + left), *(array + pivotIndex), *(array + right));
        // *(array + left) = *(temp + 0);
        // *(array + pivotIndex) = *(temp + 1);
        // *(array + right) = *(temp + 2);
        
        tempInt = *(array + pivotIndex); 
        *(array + pivotIndex) = *(array + left);
        *(array + left) = tempInt;
        
      do {
        while (*(array + up) < median_val || up < right - 1) {
            up++;
        }
        
        while (*(array + down) > median_val || down > left) {
            down--;
        }
        
        if (up < down) {
            tempInt = *(array + up); 
            *(array + up) = *(array + down);
            *(array + down) = tempInt;
        }
        else {
            break;
        }
      } while (up < down);
      
      tempInt = *(array + down); 
      *(array + down) = *(array + left);
      *(array + left) = tempInt;
      
      cout << "...returning down from partition\n";/////////////////
      return down;
    }
}

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS::getArray() const {
    cout << "starting getArray...\n";//////////////
    ostringstream out_array;
    if (array == NULL) {
        cout << "...returning out_array from getArray\n";/////////////
        return out_array.str();
    }
    else if (array != NULL) {
        for (int i = 0; i < array_pos; ++i) {
            out_array << *(array + i);
            if (i < array_pos - 1) {
                out_array << ", ";
            }
        }
        
        cout << "...returning out_array from getArray\n";/////////////
        return out_array.str();
    }
}

/*
* Returns the number of elements which have been added to the array.
*/
int QS::getSize() const {
    return array_pos;
}

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
* returns true if a value was added, false otherwise.
*/
bool QS::addToArray(int value) {
    if (array_pos < array_size) {
        *(array + array_pos) = value;
        array_pos++;
        return true;
    }
    
    return false;
}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int capacity) {
    cout << "starting createArray...\n";////////////
    array_size = capacity;
    array = new int[capacity];
    array_pos = 0;
    
    if (array != NULL) 
        return true;
    else 
        return false;
}

/*
* Resets the array to an empty or NULL state.
*/
void QS::clear() {
    array = NULL;
    array_pos = 0;
}

void QS::MedianSort(int& left, int& middle, int& right) {
    cout << "starting MedianSort...\n";////////////
    
    do {
            if (left <= middle && middle <= right) {
                break;
            }
            else if (middle < left) {
                int temp = middle;
                middle = left;
                left = temp;
            }
            else if (right < middle) {
                int temp = right;
                right = middle;
                middle = temp;
            }
            
    } while(true);
    
    cout << "...returning sort from Median Sort\n";//////////
    //return sort;
}