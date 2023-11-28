#pragma once

#include "adding.h"

int Sdk::add_public(int a, int b)
{
    return a + b;
}

int Sdk::add_private(int a, int b)
{
    return 0 - (a + b);
}
