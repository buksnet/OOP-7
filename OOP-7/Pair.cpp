#include "Pair.h"

Pair::Pair() {
	first = 0;
	second = 0;
}
Pair::Pair(int first = 0, double second = 0) {
	this->first = first;
	this->second = second;
}
Pair::Pair(const Pair& P) {
	this->first = P.first;
	this->second = P.second;
}
Pair::~Pair() {
}
int Pair::get_first() { return this->first; }
void Pair::set_first(int first) { this->first = first; }
double Pair::get_second() { return this->second; }
void Pair::set_second(double second) { this->second = second; }
void Pair::print() {
	cout << this->first << " : " << this->second << endl;
}

Pair Pair::operator+(const int& first) const {
	return Pair(this->first + first, this->second);
}
Pair Pair::operator+(const double& second) const {
	return Pair(this->first, this->second + second);
}
Pair Pair::operator-(const Pair& P) const {
	return Pair(this->first - P.first, this->second - P.second);
}

Pair operator+(const int& first, const Pair& P) {
	return P + first;
}
Pair operator+(const double& second, const Pair& P) {
	return P + second;
}
ostream& operator<<(ostream& out, const Pair& P) {
	out << " " << P.first << " : " << P.second << endl;
	return out;
}

istream& operator>>(istream& in, Pair& P) {
	cout << "Enter int value: ";
	in >> P.first;
	cout << "Enter double value: ";
	in >> P.second;
	return in;
}