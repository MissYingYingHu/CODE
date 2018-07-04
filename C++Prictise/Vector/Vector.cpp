#include"Vector.h"
#include<string.h>
#include<assert.h>
Vector::Vector ()
	:first(NULL)
	,finish(NULL)
	,endofstorage(NULL)
{}
size_t Vector::Size()const
{
	return finish - first;
}
size_t Vector::Capacity()const
{
	return endofstorage - first;
}
void Vector::Expand(size_t n)
{
	if(endofstorage == NULL)
	{
		first = new DataType[3];
		finish = first;
		endofstorage = first + 3;
		return;
	}
	if(n >= Capacity())
	{
		DataType fin = Size();
		DataType capacity = Capacity();
		DataType *tmp = new DataType[Capacity()*2];
		memcpy(tmp,first,Size()*sizeof(DataType));
		delete[] first;
		first = tmp;
		finish = first + fin;
		endofstorage = first + capacity*2;
		return;
	}
}
Vector::Vector(const Vector& v)
{
	if(v.first != v.finish )
	//如果v是空的顺序表，当memcpy时就会崩溃
	{
		DataType *tmp = new DataType[v.Size()];
		memcpy(tmp,v.first,v.Size()*sizeof(DataType));
		first = tmp;
		finish = first + v.Size();;
		endofstorage = first + v.Size();
	}
	else
	//如果v是空的顺序表。就把需要构造的顺序表的3个成员变量置为空
	{
		first = finish = endofstorage = NULL;
	}
}
Vector& Vector::operator=(const Vector& v)
{
	if(first != v.first)
	{
		if(v.first != v.finish)
		{
			DataType *tmp = new DataType[v.Size()];
			memcpy(tmp,v.first,v.Size()*sizeof(DataType));
			delete[] first;
			first = tmp;
			finish = first + v.Size();
			endofstorage = first + v.Capacity();
		}
	}
	else
	{
		first = finish = endofstorage = NULL;
	}
	return *this;
}
Vector::~Vector()
{
	delete[] first;
	first = finish = endofstorage = NULL;
}
void Vector::PushBack(DataType value)
{
	if(Capacity() <= Size())
	{
		Expand(Size());
	}
	*finish = value;
	++finish;
}
void Vector::PopBack()
{
	if(Size() == 0)
	{
		return;
	}
	--finish;
}
void Vector::Insert (size_t pos,DataType value)
{
	assert(pos <= Size());
	DataType i = Size();
	++finish;
	if(Capacity() <= Size())
	{
		Expand(Size());
	}
	for(;i > (DataType)pos;--i)
	{
		first[i] = first[i - 1];
	}
	first[pos] = value;
}
void Vector::Erase(size_t pos)
{
	assert(pos <= Size());
	DataType i = (DataType)pos;
	for(;i < Size();++i)
	{
		first[i] = first[i + 1];
	}
	--finish;
}
size_t Vector::Find(DataType to_find)
{
	int cur = 0;
	for(;cur < Size();++cur)
	{
		if(first[cur] == to_find)
		{
			return cur;
		}
	}
	return (size_t)-1;
}
