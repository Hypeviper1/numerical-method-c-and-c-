#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x*x+3*x-4; // Example function: f(x) = x^2 + 3x - 4
}
double f1(double x) {
    return 2*x+3;;
}

void newtonRapson(double x, double e) {
    int iter = 0;
    int max_iter = 100;
    while (iter < max_iter){
        double fx = f(x);
        double fx1 = f1(x);
        
        if (fabs(fx1) < e) {
            cout << "Derivative too small, stopping iteration." << endl;
            break;
        }
        
        double x1 = x - fx / fx1;

        cout << "Iteration " << iter + 1 << ": x = " << setprecision(6) << x1 << endl;
        
        
        if (fabs(x1 - x) < e) {
            cout << "\nRoot found: " << x1 << " after " << iter + 1 << " iterations." << endl;
            return; 
        }
        
        x = x1;
        iter++; 
    }
    cout << "Did not converge in " << max_iter << " iterations." << endl;
}

int main() {
    double x0, e;
    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> e;

    newtonRapson(x0, e);

    return 0;
}
