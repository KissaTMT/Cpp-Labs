#include "ev_vector.h"


ev_vector::ev_vector(int size)
{
    this->size = size;
    data = new double(size);
}

double ev_vector::get(int index)
{
	return data[index];
}

void ev_vector::set(int index, double value)
{
	data[index] = value;
}

ev_vector* ev_vector::random()
{
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        data[i] = (double)rand()/RAND_MAX;
    }

    return this;
}
ev_vector* ev_vector::normalize() {
    double norm = 0;
    for (int i = 0; i < size; i++) {
        norm += data[i] * data[i];
    }
    norm = sqrt(norm);
    for (int i = 0; i < size; i++) {
        data[i] /= norm;
    }
    return this;
}
ev_vector* ev_vector::operator+(ev_vector& other) {
    ev_vector* result = new ev_vector(size);
    for (int i = 0; i < size; i++) {
        result->set(i,data[i] + other.get(i));
    }
    return result;
}
ev_vector* ev_vector::operator-(ev_vector& other) {
    ev_vector* result = new ev_vector(size);
    for (int i = 0; i < size; i++) {
        result->set(i, data[i] - other.get(i));
    }
    return result;
}
ev_vector* ev_vector::operator*(ev_matrix& m)
{
    ev_vector* result = new ev_vector(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result->set(i, data[i] + m.get(i, j) * data[j]);
        }
    }
    return result;
}
