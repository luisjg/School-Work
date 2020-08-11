#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class people
{

public:
	people(): name(""), value(0)
	{
	}

	people(string n, T val): name(n), value(val)
	{
	}

	people(people<T>& p)
	{
		name = p.name;
		value = p.value;
	}
	void setName(string s)
	{
		name=s;
	}
	void setValue(T val)
	{
		value-val;
	}

friend ostream& operator<< <T>(ostream& out, people<T>& p);

    void test(people<T> p)
	{
		cout << p;
	}
	bool operator>(people<T> p);

const operator=(&people<T> p);

private:
	string name;
	T value;
};

template <typename T>
bool people<T>::operator>(people<T> p)
{
	return name > p.name;
}

template <typename T>
ostream& operator<<(ostream& out, people<T>& p)
{
	out << p.name << " " << p.value << endl;
	return out;
}

template <typename T>
const people<T>::operator=(people<T>& right)
{
	if(&right != this){
		&right = this;
	}
	else
	{
		cout << "Assigning People object to the same People Object" << endl;
	}
}