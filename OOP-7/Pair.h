#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int first, double second);
	Pair(const Pair& P);
	~Pair();
	void set_first(int first);
	void set_second(double second);
	int get_first();
	double get_second();
	void print();

	Pair operator+(const int& first) const;
	Pair operator+(const double& second) const;
	Pair operator-(const Pair& P) const;
	friend Pair operator+(const int& first, const Pair& P);
	friend Pair operator+(const double& second, const Pair& P);
	friend ostream& operator<<(ostream& out, const Pair& P);
	friend istream& operator>>(istream& in, Pair& P);
};
