#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Define the ODE function dy/dx = f(x, y)
double f(double x, double y) {
    return 4*exp(0.8*x)-0.5*y; // Example ODE: dy/dx = x + y
}

// Runge-Kutta 4th Order method returning final y
double rk4(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;

    while (x < xn - 1e-9) {  // allow small floating-point margin
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);

        y += (1.0 / 6.0) * (k1 + 2*k2 + 2*k3 + k4);
        x += h;
    }

    return y;
}

int main() {
    double x0, y0, h, xn;

    cout << "Enter initial value x0: ";
    cin >> x0;

    cout << "Enter initial value y0: ";
    cin >> y0;

    cout << "Enter step size h: ";
    cin >> h;

    cout << "Enter final value of x (xn): ";
    cin >> xn;

    double result = rk4(x0, y0, h, xn);

    cout << fixed << setprecision(6);
    cout << "\nApproximate value of y at x = " << xn << " is " << result << endl;

    return 0;
}
