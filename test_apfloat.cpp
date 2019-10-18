#include <iostream>
#include "apfloat.h"

using namespace std;

int main()
{
   cout<<"APFloat Calculation\n";
   // Test binary2float
   apfloat<8, 7> ap_float1(1, 17, 8); // -8.1852e-34
   apfloat<8, 7> ap_float2(0, 17, 80); // -1.25185e-33
   apfloat<8, 7> ap_float3(1, 127, 8); // -1.0625
   apfloat<8, 7> ap_float4(0, 127, 80); // 1.625
   cout<<"binary2float:\nap_float1: " << ap_float1.binary2float() << endl;
   cout<<"ap_float2: " << ap_float2.binary2float() << endl;
   cout<<"ap_float3: " << ap_float3.binary2float() << endl;
   cout<<"ap_float4: " << ap_float4.binary2float() << endl;
   
   // Test float2binary
   apfloat<8, 7> ap_float5(0, 132, 54); // 45.25
   apfloat<8, 7> ap_float6;
   ap_float6.float2binary(45.45);
   cout<<"float2binary:\nap_float5: " << ap_float5.binary2float() << endl;
   
   return 0;
}


