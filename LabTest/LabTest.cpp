#include <iostream>
#include <cmath>
#include <vector>
#include "ev_matrix.h"

using namespace std;

int main() {
   
    ev_matrix m(3);
    m.random();
    m.inverse_iteration();
    auto v = m.eigen_vectors;

    for (int i = 0; i < v.size(); i++) {

        for (int j = 0; j < v[i].size; j++) {
            cout << v[i].get(j) << " ";
        }
        cout << endl;
    }

    return 0;
}
