#pragma once
#include<iostream>

typedef int DataType;
class Vector
{
public:
	Vector();
	Vector(const Vector& v);
	Vector& operator=(const Vector& v);
	~Vector();
	size_t Size()const;
	size_t Capacity()const;
	void Expand(size_t n);
	void PushBack(DataType value);
	//void Reserve(size_t n);  
	void PopBack();
	void Insert(size_t pos,DataType value);
	void Erase(size_t pos);
	size_t Find(DataType to_find);
	void DisplayVector(char* msg);
private:
	DataType* first;
	DataType* finish;
	DataType* endofstorage;
};