#include <stdio.h>
#include <math.h>

static double function(double x)
{
    return exp(x) - 5;
}

static double newtons_method(void)
{
     double x2;
     double x1 = 2.0;
     double x4 = 0;
     double x5;
     int offset = 5;
     double x6;

     x2 = x1 - (function(x1) / (exp(x1)));
     double x3 = x2 - ((exp(x2) - offset) / (exp(x2)));

     printf("First iteration: %f\n", x2);
     printf("Second iteration: %f\n", x3);

     x4 = x3 - (function(x3) / (exp(x3)));
     x5 = x4 - (function(x4) / (exp(x4)));

     x6 = x5 - ((exp(x5) - 5) / (exp(x5)));
     printf("Final value: %f\n", x6);
     return x6;
}

int main()
{
    printf("Let's run Newton's method on (e^x)-5\n");
    newtons_method();
    return 0;
}

// ----------------------------------------------- My Solution ---------------------------------------------------------
//#include <stdio.h>
//#include <math.h>
//
//static double function(double x)
//{
//    return exp(x) - 5;
//}
//
//static double newtons_method(int offset, double x1, int iterations)
//{
//    // double x2;
//    // double x1 = 2.0;
//    // double x4 = 0;
//    // double x5;
//    // //int offset = 5;
//    // double x6;
//    double result = 0;
//    result = x1 - (function(x1) / (exp(x1)));
//    while (iterations > 0) {
//        result = result - ((exp(result) - offset) / (exp(result)));
//        printf("Current value: %f\n", result);
//        iterations--;
//    }
//    printf("Final value: %f\n", result);
//    return result;
//    // // base = base-1 -(function(base-1) / exp(base-1))
//    // double result = x1 - (function(x1) / (exp(x1)));
//    // result = result - ((exp(result) - offset) / (exp(result)));
//
//    // //printf("First iteration: %f\n", x2);
//    // //printf("Second iteration: %f\n", x3);
//
//    // result = result - (function(result) / (exp(result)));
//    // //printf("Third iteration: %f\n", x4);
//    // x5 = x4 - (function(x4) / (exp(x4)));
//    // //printf("Fourth iteration: %f\n", x5);
//
//    // x6 = x5 - ((exp(x5) - 5) / (exp(x5)));
//    // printf("Final value: %f\n", x6);
//    // return x6;
//}
//
//int main()
//{
//    printf("Let's run Newton's method on (e^x)-5\n");
//    newtons_method(5, 2, 6);
//    return 0;
//}