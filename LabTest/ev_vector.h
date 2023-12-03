#pragma once
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "ev_matrix.h"
using namespace std;
class ev_vector
{
public:
	double* data;
	int size;

	ev_vector(int size);
	double get(int index);
	void set(int index, double value);
	ev_vector* normalize();
	ev_vector* random();
	ev_vector* operator+(ev_vector& other);
	ev_vector* operator-(ev_vector& other);
	ev_vector* operator*(ev_matrix& other);
};

