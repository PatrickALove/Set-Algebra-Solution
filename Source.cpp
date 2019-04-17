#include<stdio.h>
#include<iostream>
#include<array>
using namespace std;

class IntegerSet
{
private:
	array<bool, 256> arr;
public:
	IntegerSet();
	IntegerSet(int m);
	IntegerSet(const int array[], int n);
	IntegerSet operator+(IntegerSet& b);
	IntegerSet operator*(IntegerSet& b);
	IntegerSet operator-(IntegerSet& b);
	void insertElement(int k);
	void deleteElement(int k);
	bool operator!=(IntegerSet& s);
	bool operator==(IntegerSet& s);
	bool operator<=(IntegerSet& s);
	bool operator>=(IntegerSet& s);

	friend istream& operator>>(istream& in, IntegerSet& I)
	{
		int n = 0;
		while (1)
		{
			in >> n;
			if (n != -1)
				I.arr[n] = true;
			else
				break;
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const IntegerSet& I)
	{
		for (int i = 0; i < 256; i++)
		{
			if (I.arr[i] == true)
				out << i << " ";
		}
		cout << endl;
		return out;
	}

};

//default constructor initializes all elements of array to false
IntegerSet::IntegerSet()
{
	arr = { false };
}

//Constructor taking parameter with m and sets true in the arr[m]
IntegerSet::IntegerSet(int m)
{
	arr = { false };
	if (m > 255)
	{
		cout << "Out of bounds";
	}
	else
		arr[m] = true;
}

//build Integer set using an array
IntegerSet::IntegerSet(const int array[], int n)
{
	arr = { false };
	for (int i = 0; i < n; i++)
	{
		if (array[i] <= 255)
			arr[array[i]] = true;
	}
}

//union of two Integer sets
IntegerSet IntegerSet::operator+(IntegerSet& b)
{
	IntegerSet c; //Initially all flase with default constructor
	for (int i = 0; i < 256; i++)
	{
		if (this->arr[i] == true || b.arr[i] == true) //if present in atleast in one
			c.arr[i] = true;
	}
	return c;
}

//Intersection of two Integer Sets
IntegerSet IntegerSet::operator*(IntegerSet& b)
{
	IntegerSet c; //Initially all flase with default constructor
	for (int i = 0; i < 256; i++)
	{
		if (this->arr[i] == true && b.arr[i] == true) //If present in both
			c.arr[i] = true;
	}
	return c;
}

//Set difference of two Integer Sets
IntegerSet IntegerSet::operator-(IntegerSet& b)
{
	IntegerSet c; //Initially all flase with default constructor
	for (int i = 0; i < 256; i++)
	{
		//If present in either of them
		if ((this->arr[i] == true && b.arr[i] == false) || (this->arr[i] == false && b.arr[i] == true))
			c.arr[i] = true;
	}
	return c;

}

//inserts a new integer k into a set (by setting arr[k] to 1)
void IntegerSet::insertElement(int k)
{
	if (k > 255)
	{
		cout << "Out of bounds";
	}
	else
		arr[k] = true;
}

//delete an integer k from the set (by setting arr[k] to 0)
void IntegerSet::deleteElement(int k)
{
	if (k > 255)
	{
		cout << "Out of bounds";
	}
	else
		arr[k] = false;
}

//return true if different else false
bool IntegerSet::operator!=(IntegerSet& s)
{
	for (int i = 0; i < 256; i++)
	{
		if (this->arr[i] != s.arr[i])
			return true;
	}

	return false;
}

//return true if both the sets are same else false
bool IntegerSet::operator==(IntegerSet& s)
{
	for (int i = 0; i < 256; i++)
	{
		if (this->arr[i] != s.arr[i])
			return false;
	}

	return true;

}

//return true if first set is a subset of second set or else return false
bool IntegerSet::operator<=(IntegerSet& s)
{
	for (int i = 0; i < 256; i++)
	{
		if (this->arr[i] == true && s.arr[i] != true)
			return false;
	}
	return true;
}

//return true if first set is superset of second set or else return false
bool IntegerSet::operator>=(IntegerSet& s)
{
	for (int i = 0; i < 256; i++)
	{
		if (s.arr[i] == true && this->arr[i] != true)
			return false;
	}
	return true;

}