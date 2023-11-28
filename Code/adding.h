#pragma once

#include "opencv2/core.hpp"

class Sdk
{
public:
    int add_public(int a, int b);

private:
    int add_private(int a, int b);

    double b;
    double a;
};
