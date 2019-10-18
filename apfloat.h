#ifndef APFLOAT_H
#define APFLOAT_H

#include <iostream>
#include <math.h>
#include "lint.h"

using namespace std;

template< unsigned int le, unsigned int lf >
class apfloat
{
    public:
        // apfloat Constructor 
        apfloat() {};
        apfloat(const bool neg, const unsigned int exp, const unsigned int frac){
            if (exp > _exp.maxVal || frac > _frac.maxVal){
            cout << "Construction Failed, max exponent value: " 
                    << _exp.maxVal << "max fraction value: " << _frac.maxVal<<endl;
            return;
            }
            _exp.val = exp;
            _frac.val = frac;
            _neg = neg;
        }
        ~apfloat() {};
        // Operation Function 
        float binary2float();
        void float2binary(const float temp);
    private:
        // number of bits of exponent
        lint<le> _exp;
        // number of bits of precision
        lint<lf> _frac; 
        // true if it is a negative number or false vice versa
        bool _neg;
};

template<unsigned int le, unsigned int lf> float apfloat<le, lf>::binary2float() {
    // Use formular v = s × 2^e × (1 + f) to transfer the floating point
    // Calculate the exponent value and bias based on the digit of exponent
    int bias = (_exp.maxVal + 1) / 2 - 1;
    int e = _exp.val - bias;
    // Calculate the f
    int tmp_frac = _frac.val;
    float f = 0.0;
    int reminder = 0;
    for (int i = lf; i > 0; i--){
        reminder = tmp_frac % 2;
        tmp_frac = tmp_frac / 2;
        f += reminder * (1/pow(2, i));
    }
    // Use formular to calculate the result value based on _neg
    return _neg == 1 ? float(0.0 - (pow(2, e) * (1 + f))) : float(pow(2, e) * (1 + f));
}
template<unsigned int le, unsigned int lf> void apfloat<le, lf>::float2binary(const float temp) {
    int integer = int(temp);
    float fp = temp - integer;
    int bias = (_exp.maxVal + 1) / 2 - 1;
    int size = log2(integer) + 1;
    char floatBinary[lf]; 
    // Construct the binary array of char with '0' and '1'
    for (int i=0; i<size; i++){
        floatBinary[i] = '0' + (integer % 2);
        integer = integer / 2;
    }
    int exp = size - 1 + bias;
    int frac = 0;
    if (lf <= size - 1){
        for (int i = lf; i >= 1; i--){
            frac += (floatBinary[i]-'0') * pow(2, (lf-i));
        }
    }
    else{
        for(int i = size; i < lf-size; i++){
            fp = 2 * fp;
            if (fp > 1){
                floatBinary[i] = '0'+1;
                fp = fp - 1;
            }else{
                floatBinary[i] = '0';
            }
        }
        for (int i = lf; i >= 1; i--){
            frac += (floatBinary[i]-'0') * pow(2, (lf-i));
        }
    }
    // Assign praivate variable
    if (temp < 0){
        _neg = 1;
    }else{
        _neg = 0;
    }
    _exp.val = exp;
    _frac.val = frac;
    cout << "neg: " << _neg<<" exp: "<<_exp.val<<" frac: "<<_frac.val<<endl;
}


#endif