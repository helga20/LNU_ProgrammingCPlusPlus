#pragma once
#include <iostream>
#include <string>
#include <fstream>

template <typename TElem>
class GenericArray
{
private:
	TElem* arr;
 	int size; // макс розмір
	int count; // к-ть заповнених ел-тів

public:
	GenericArray();
	GenericArray(int maxSize);
	~GenericArray();

	void addElem(const TElem& elem);
	void printArray() const;
	void readFromFile(const string& fileName);

	bool containsElement(const TElem& elem) const;
	int findIndex(const TElem& elem) const;
	TElem& findElement(const TElem& elem) const;
	TElem& getElement(int index) const;

	int getElementCount() const;
};

template <typename TElem>
GenericArray<TElem>::GenericArray()
	: size(0), count(0), arr(nullptr)
{}

template <typename TElem>
GenericArray<TElem>::GenericArray(int maxSize)
	: size(maxSize), count(0), arr(new TElem[maxSize])
{}

template <typename TElem>
GenericArray<TElem>::~GenericArray()
{
	if (arr != nullptr)
		delete[] arr;
}

template <typename TElem>
void GenericArray<TElem>::addElem(const TElem& elem)
{
	if (size == 0)
	{
		size = 10;
		arr = new TElem[size];
		count = 0;
	}
	else if (count == size)
	{
		size += 5;
		TElem* tempArr = new TElem[size];
		for (int i = 0; i < count; ++i)
		{
			tempArr[i] = arr[i];
		}
		delete[] arr;
		arr = tempArr;
	}
	arr[count] = elem;
	++count;
}

template <typename TElem>
void GenericArray<TElem>::printArray() const
{
	// (<count>/<size>)
	cout << "Array (count: " << count << " / size: " << size << "):\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << '\n';
	}
	cout << "\n";
}

template <typename TElem>
void GenericArray<TElem>::readFromFile(const string& fileName)
{
	//[25] 1 2 3 _ _ _ _ _ _ + [4] 4 5 6 7 -> ok
	//[5] 1 2 3 _ _
	// 7 size-count < filecount
	// [size+filecount+5] 1 2 3 x x x _ _ _
	ifstream iFile(fileName);
	int fileCount; iFile >> fileCount;

	if (arr == nullptr) // [0] nullptr
	{
		size = fileCount + 5;
		count = 0;
		arr = new TElem[size]; // [size] count _ _ _ _
	}
	else if (count + fileCount <= size)
	{
		size = size + fileCount + 5;
		TElem* tempArr = new TElem[size];
		for (int i = 0; i < count; ++i)
		{
			tempArr[i] = arr[i];
		}
		delete[] arr;
		arr = tempArr; // [size+fileCount] 1 2 3 count _ _ _ _ _ _
	}

	for (int i = 0; i < fileCount; ++i)
	{
		iFile >> arr[count];
		++count;
	}

	iFile.close();
}

template <typename TElem>
bool GenericArray<TElem>::containsElement(const TElem& elem) const
{
	for (int i = 0; i < count; ++i)
	{
		if (arr[i] == elem)
			return true;
	}
	return false;
}

template <typename TElem>
int GenericArray<TElem>::findIndex(const TElem& elem) const
{
	//for (int i = 0; i < count; ++i)
	//{
	//	if (arr[i] == elem)
	//		return i;
	//}
	return -1;
}

template <typename TElem>
TElem& GenericArray<TElem>::findElement(const TElem& elem) const
{
	int index = findIndex(elem);
	if (index == -1)
		throw "No element in array.";

	return arr[index];
}

template <typename TElem>
TElem& GenericArray<TElem>::getElement(int index) const
{
	if (index < 0 || index >= count)
		throw "Index out of range.";

	return arr[index];
}

template <typename TElem>
int GenericArray<TElem>::getElementCount() const
{
	return count;
}