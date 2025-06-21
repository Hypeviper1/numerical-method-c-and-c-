#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, double y ) {
    return x+y;
}
void euler(double x0, double y0, double h, double xn){
    double x = x0, y = y0;
    int step  = 0;

    cout << fixed << setprecision(4);
     cout << "Step\t x\t\t y\n";

    while (x < xn) {
        cout << step << "\t " << x << "\t\t " << y << endl;
        y += h * f(x, y);
        x += h;
        step++;
    }
    cout << "\nApproximate solution at x = " << xn << " is y = " << y << endl;
}


int main() {
     double x0, y0, h, xn;
    cout << "Enter initial values x0, y0, step size h, and final x value xn: ";
    cin >> x0 >> y0 >> h >> xn; 
    euler(x0, y0, h, xn);
    return 0;
    
}
