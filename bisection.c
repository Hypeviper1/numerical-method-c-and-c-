#include <stdio.h>
#include <math.h>

// Define the function f(x)
double func(double x) {
    return exp(0.5*x) +  sin(x) - 3;
}

void bisection(double a, double b, double epsilon) {
    if (func(a) * func(b) >= 0) {
        printf("Invalid interval. f(a) * f(b) must be < 0.\n");
        return;
    }

    double c;
   int iter = 1;

    printf("Iter\t a\t\t b\t\t c\t\t f(c)\n");

    do {
        c = (a + b) / 2;
        printf("%d\t %.6lf\t %.6lf\t %.6lf\t %.6lf\n", iter, a, b, c, func(c));
        if ((func(a)*func(b)) ==epsilon){
            break;
        }

        if (func(a) * func(c) < 0)
            b = c;
        else
            a = c;

        iter++;
    } while (fabs(func(c)) >= epsilon && (b - a) / 2 > epsilon);

    printf("\nApproximate root: %.6lf\n", c);
}

int main() {
    double a, b, epsilon;

    // Get user input
    printf("Enter the value of a: ");
    scanf("%lf", &a);
    printf("Enter the value of b: ");
    scanf("%lf", &b);
    printf("Enter the tolerance (epsilon): ");
    scanf("%lf", &epsilon);

    // Call bisection function
    bisection(a, b, epsilon);

    return 0;
}
