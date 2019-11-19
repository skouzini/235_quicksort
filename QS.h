#pragma once

#include <iostream>
#include <string>
#include "QSInterface.h"

using namespace std;

class QS : public QSInterface 
{
private:
    int *array;
    int array_size;
    int array_pos;
    int current_size;
    int middle;
    int sort[3];
    
public:
	QS();
	~QS();

	void sortAll();

	int medianOfThree(int left, int right);

	int partition(int left, int right, int pivotIndex);

	string getArray() const;

	int getSize() const;

	bool addToArray(int value);

	bool createArray(int capacity);

	void clear();
	
	void MedianSort(int& left, int& middle, int& right);
};