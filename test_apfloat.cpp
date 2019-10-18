#include <iostream>
#include "apfloat.h"

using namespace std;

int main()
{
   cout<<"Hello World\n";
   apfloat<8, 13> ap_float(0, 124, 22);
   cout<<"binary2float: " << ap_float.binary2float();
   return 0;
}


