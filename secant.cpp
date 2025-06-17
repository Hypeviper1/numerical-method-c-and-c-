#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x) {
    return exp(0.5 * x) + sin(x) - 3;
}

double secant(double x0, double x1, double epsilon) {
    double x2, f0, f1, f2;
    int iter = 1;
    const int MAX_ITER = 100;

    cout << fixed << setprecision(6);
    cout << "Iter\t\tx0\t\tx1\t\tx2\t\tf(x2)\n";

    do {
        f0 = func(x0);
        f1 = func(x1);
        if (f1 - f0 == 0) {
            cout << "Division by zero error.\n";
            return -1;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        f2 = func(x2);

        cout << iter << "\t\t" << x0 << "\t" << x1 << "\t" << x2 << "\t" << f2 << endl;

        if (fabs(f2) < epsilon)
            break;

        x0 = x1;
        x1 = x2;
        iter++;

    } while (fabs(f2) >= epsilon && iter < MAX_ITER);

    if (iter >= MAX_ITER)
        cout << "Method did not converge in " << MAX_ITER << " iterations.\n";
    else
        cout << "\nApproximate root: " << x2 << endl;

    return x2;
}

int main() {
    double x0, x1, epsilon;

    cout << "Enter the value of x0: ";
    cin >> x0;
    cout << "Enter the value of x1: ";
    cin >> x1;
    cout << "Enter the tolerance (epsilon): ";
    cin >> epsilon;

    secant(x0, x1, epsilon);
    return 0;
}
