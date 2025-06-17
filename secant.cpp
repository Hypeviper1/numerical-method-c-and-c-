#include<iostream>
#include<cmath>
using namespace std;
double func(double x) {
    return exp(0.5 * x) + sin(x) - 3;
}

float secant (float x0, float x1, float epsilon) {
    float x2;
    int iter = 1;

    cout << "Iter\t\t1 x0\t\t x1\t\t x2\t\t f(x2)\n";

    do {
        if (func(x1) - func(x0) == 0) {
            cout << "Division by zero error.\n";
            return -1;
        }
        x2 = x1 - func(x1) * (x1 - x0) / (func(x1) - func(x0));
        cout << iter << "\t\t" << x0 << "\t\t " << x1 << "\t\t " << x2 << "\t\t " << func(x2) << endl;

        if (fabs(func(x2)) < epsilon)
            break;

        x0 = x1;
        x1 = x2;
        iter++;
    } while (fabs(func(x2)) >= epsilon);

    cout << "\nApproximate root: " << x2 << endl;
    return x2;
}
int main() {
    float x0, x1, epsilon;

    // Get user input
    cout << "Enter the value of x0: ";
    cin >> x0;
    cout << "Enter the value of x1: ";
    cin >> x1;
    cout << "Enter the tolerance (epsilon): ";
    cin >> epsilon;

    // Call secant function
    secant(x0, x1, epsilon);

    return 0;
}