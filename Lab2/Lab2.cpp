#include <iostream>
using namespace std;

template <typename T>
void swap(T* a, T* b) {
	T t = *a;
	*a = *b;
	*b = t;
}

float* get_pointer_of_max_element(float* arr, int n) {
	int len = n;
	float max = INT_FAST32_MIN;
	float* max_element = &max;
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = *(arr + i);
			max_element = (arr + i);
		}
	}
	return max_element;
}

void try_input(int* n) {
	float k;
	cin >> k;

	while (true) {
		*n = k;
		if (*n == k && k > 0) {
			break;
		}
		else {
			cout << "Ввелите целое число: ";
			cin >> k;
			cout << endl;
		}
	}
}

int main() {

	setlocale(LC_ALL, "RUSSIAN");
	int n;
	cout << "Ввелите целое число: ";
	try_input(&n);

	float* arr = new float[n];

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		arr[i] = (float)rand() / RAND_MAX;
		cout << *(arr + i) << endl;
	}
	cout << endl;

	swap(&arr[n - 1], get_pointer_of_max_element(arr, n));

	for (int i = 0; i < n; i++) {
		cout << *(arr + i) << endl;
	}

	system("pause");
	return 0;
}