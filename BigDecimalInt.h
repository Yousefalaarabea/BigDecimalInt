#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <regex>
#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt
{
private:
    string decStr;
    int decInt;
public:
    BigDecimalInt();
    BigDecimalInt(string s);
    BigDecimalInt(int n);
    string gett();
    void sett(string c);
    BigDecimalInt operator+( BigDecimalInt& bdi);
    BigDecimalInt operator-(BigDecimalInt& bdi);
    string subtract(string a,string b);
    string complement10(string b);
    string sumBig(string a, string b);
    string add(string a, string b,string sign);
    string reverseNumber(string x);
    void addZeros(string& z, int sz);
    void removeZeros(string &s);
    char returnChar(int x);
    BigDecimalInt& operator= (const BigDecimalInt& dec2);
    bool operator > (BigDecimalInt dec2);
    bool operator < (BigDecimalInt dec2);
    bool operator==(BigDecimalInt dec2);
    bool validation(string s);
    int sign();
    int size_n();
    friend ostream& operator << (ostream& out, BigDecimalInt b);
};
ostream& operator << (ostream& out, BigDecimalInt b);

#endif // BIGDECIMALINT_H
