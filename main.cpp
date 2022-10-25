#include <iostream>
#include <regex>
#include <bits/stdc++.h>
#include "BigDecimalInt.h"
using namespace std;

int main()
{
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4 = num2 + num1;
    BigDecimalInt num5 = num2 - num1;
    cout << "num1 = " << num1.gett() << endl;
    cout << "num2 = " << num2.gett() << endl;
    cout << "num2 + num1 = " << num4 << endl;
    cout << "num2 - num1 = " << num5 << endl;

    cout<<"____________________________________________"<<endl;

    num4 = num2 + num3;
    num5 = num2 - num3;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    cout << "num2 + num3 = " << num4 << endl;
    cout << "num2 - num3 = " << num5 << endl;

    cout<<"____________________________________________"<<endl;

    num4 = num3 + num1;
    num5 = num3 - num1;
    cout << "num3 = " << num3.gett() << endl;
    cout << "num1 = " << num1.gett() << endl;
    cout << "num3 + num1 = " << num4 << endl;
    cout << "num3 - num1 = " << num5 << endl;
}
//
