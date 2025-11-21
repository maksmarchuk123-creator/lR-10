#pragma once
#include <cmath>

ref class FunctionCalc {
public:
    static double Calc(double x, double Q, double z) {
        if (x > Q) {
            return cos(x) / (4 + sqrt(fabs(x)));
        }
        else {
            return 2 * atan(x + z);
        }
    }
};