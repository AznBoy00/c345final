#include "MyArray.h"
#include <iostream>
using namespace std;

MyArray::MyArray() {
	this->size = 0;
	this->data = new int[size];
}

MyArray::~MyArray() {
	delete[] data;
	size = 0;
}

MyArray::MyArray(int arr[], int arrSize) {
	size = 0;
	data = new int[size];

	for (int i = 0; i < arrSize; i++) {
		if (!isInArray(arr[i])) {
			data[size] = arr[i];
			size++;
		}
	}
}

MyArray::MyArray(MyArray &arr) {
	this->size = arr.getSize();
	this->data = new int[size];

	for (int i = 0; i < size; i++) {
		this->data[i] = arr.data[i];
	}
}

bool MyArray::isInArray(int input) {
	int* d = this->data;
	for (int i = 0; i < getSize(); i++) {
		if (d[i] == input) {
			return true;
		}
	}
	return false;
}

const MyArray MyArray::operator=(const MyArray& anArr) {
	this->size = anArr.size;
	data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = anArr.data[i];
	}
	return *this;
}

inline int* MyArray::getArray() {
	return this->data;
}

inline int MyArray::getSize() {
	return this->size;
}

int main() {
	cout << "Creating statically allocated array..." << endl;
	int sampleArray[4] = { 1, 2, 2, 4 };
	cout << "Using constructor..." << endl;
	MyArray anArray(sampleArray, 4);
	cout << "Using copy constructor..." << endl;
	MyArray *copiedArray = new MyArray(anArray);
	cout << "Printing content of MyArray..." << endl;
	for (int i = 0; i < copiedArray->getSize(); i++)\
		cout << copiedArray->getArray()[i] << endl;
	cout << "destructing..." << endl;
	delete copiedArray;
	int i;  cin >> i;
}