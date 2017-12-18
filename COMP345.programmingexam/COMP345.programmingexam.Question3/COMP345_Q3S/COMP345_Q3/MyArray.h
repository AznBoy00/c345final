#pragma once
class MyArray {
private:
	int size;
	int* data;
public:
	MyArray();
	MyArray(int arr[], int size); //Statically allocated array, must delete duplicates
	MyArray(MyArray &arr); // Copy Constructor
	~MyArray();
	int* getArray();
	int getSize();
	bool isInArray(int input);
	const MyArray operator=(const MyArray&);
};

