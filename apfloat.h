#ifndef APFLOAT_H
#define APFLOAT_H
#include "lint.h"

using namespace std;

template< unsigned int le, unsigned int lf >
struct apfloat
{
private:
    // number of bits of exponent
    lint<le> _exp;
    // number of bits of precision
    lint<lf> _frac; 
    // true if it is a negative number or false vice versa
    bool _neg;
public:
    // apfloat Constructor 
    apfloat() {}
    apfloat(const bool neg, const unsigned int exp, const unsigned int frac){
        if (exp > _exp.maxVal || frac > _frac.maxVal){
        cout << "Construction Failed, max exponent value: " 
                << _exp.maxVal << "max fraction value: " << _frac.maxVal<<endl;
        return;
        }
        _exp = exp;
        _neg = neg;
        _frac = frac;
    }
    float binary2float();
    bool float2binary(const float temp);
    ~apfloat() {};
};



#endif