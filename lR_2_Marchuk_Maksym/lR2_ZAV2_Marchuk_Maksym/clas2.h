#pragma once
#include <cmath>
#define _USE_MATH_DEFINES
#include <cmath>

class clas2
{
public:

    double CalcLength(double r)
    {
        return 2 * 3.141592653589793 * r;
    }

    double CalcArea(double r)
    {
        return 3.141592653589793 * r * r;
    }
};
