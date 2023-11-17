#include <iostream>
#include <math.h>
using namespace std;


double formula_forward(int n) {
	double I_n = log(7 / double(6)), I_next, arg = 7/6;
	cout << "First formula calculations:" << endl;
	for (int i = 1; i <= n; i++) {
		I_next = 1 / double(i + 1) - 6 * I_n;
		I_n = I_next;
		cout.precision(5);
		cout << scientific << "n = " << i << "\t" << "I_n = " << I_n << endl;
	}
	return I_n;
}

double formula_backward(int n) {
	double I_next = 0, I_n;
	for (int i = n + 40; i >= n; i--) {
		I_n = (1 / double(i + 1) - I_next) / double(6);
		I_next = I_n;
	}
	return I_n;
}

int main() {
	double I_forward = formula_forward(40);
	double I_backward = formula_backward(40);
	cout.precision(5);
	cout << scientific << "First formula:\t" << I_forward << endl << "Second formula:\t" << I_backward << endl << "The difference:\t" << fabs(I_backward - I_forward) << endl;
	return 1;
}