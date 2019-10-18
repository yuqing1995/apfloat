#ifndef LINT_H
#define LINT_H
#include<math.h>
using namespace std;

template<unsigned int l>
struct lint
{
    // Set the length of the bits
    unsigned int val;
    unsigned int maxVal= pow(2, l) - 1;
};

#endif