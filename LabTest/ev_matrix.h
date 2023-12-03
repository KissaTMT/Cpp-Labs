#pragma once
#include <vector>
#include "ev_vector.h"
#include <ctime>
using namespace std;
class ev_matrix
{
public:
	int size;
	double** matrix;
	vector<double> eigen_values;
	vector<ev_vector> eigen_vectors;

	ev_matrix(int size);
	ev_matrix(int size, double** matrix);
	double get(int row, int column);
	void set(int row, int column, double value);
	ev_matrix* random();
	void inverse_iteration();
};

