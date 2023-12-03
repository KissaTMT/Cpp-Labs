#include "ev_matrix.h"

double ev_matrix::get(int row, int column)
{
    return matrix[row][column];
}

void ev_matrix::set(int row, int column, double value)
{
    matrix[row][column] = value;
}

ev_matrix::ev_matrix(int size)
{
    this->size = size;

    matrix = new double*[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
    }
}

ev_matrix::ev_matrix(int size, double** matrix)
{
    this->matrix = matrix;
    this->size = size;

}

ev_matrix* ev_matrix::random()
{
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand();
        }
    }

    return this;
}

void ev_matrix::inverse_iteration()
{
    eigen_vectors.clear();
    for (int i = 0; i < size; ++i) {
        ev_matrix* B = new ev_matrix(size);
        ev_vector* v = (new ev_vector(size))->random();

        for (int n = 0; n < size; n++) {
            for (int m = 0; m < size; m++) {
                B->set(n,m,matrix[n][m]);
                if (n == m) B->set(n, m, B->get(n,m) - matrix[n][m]);;
            }
        }
        v->normalize();
        int iterations = 100;
        double epsilon = 1e-12;
        for (int j = 0; j < iterations; ++j) {
            ev_vector* next_v = ((*v) * (*B))->normalize();
            ev_vector* error = *next_v - *v;
            bool flag = true;
            for (int k = 0; k < error->size; k++) {
                if (error->get(k) >= epsilon) {
                    flag = false;
                }
            }
            if(flag){
                v = next_v;
                break;
            }
            v = next_v;
        }
        eigen_vectors.push_back(*v);
    }
}
