#include "BigDecimalInt.h"
#include <iostream>
#include <regex>
#include <bits/stdc++.h>
using namespace std;

BigDecimalInt::BigDecimalInt()
{
    decStr = "";
}
BigDecimalInt::BigDecimalInt(string s)
{
    string s2="";

    if (validation(s))
    {
        if(s[0]=='+' || s[0]=='-')
        {
            decStr = s;
        }
        else
        {
            s2 = "+";
            s2 += s;
            decStr = s2;
        }
    }
    else
    {
        while (!validation(s))
        {
            cout << "\nInvalid input, please input another one : ";
            cin >> s ;
            decStr=s;
        }
    }
}
BigDecimalInt::BigDecimalInt(int n)
{
    string b = to_string(n);
    decStr = b;
}
string BigDecimalInt:: gett()
{
    return decStr;
}
void BigDecimalInt:: sett(string c)
{
    decStr = c;
}

BigDecimalInt BigDecimalInt:: operator+( BigDecimalInt& bdi)  ///b3=b1.operate+(b2)
{
    BigDecimalInt bdi2;
    string a = decStr;
    string b = bdi.gett();
    if(a[0]=='+' && b[0]=='+')
    {
        string sign="+";
        string str = add(a, b, sign);
        bdi2.sett(str);
        return bdi2;
    }
    else if(a[0]=='-' && b[0]=='-')
    {
        string sign="-";
        string str = add(a, b, sign);
        bdi2.sett(str);
        return bdi2;
    }
    else if(a[0]=='+' && b[0]=='-')
    {
        string s1 = "", s2 = "";
        for(int i=1; i<a.length(); i++)
        {
            s1 += a[i];
            s2 += b[i];
        }
        if(s1 > s2)
        {
            string str="+";
            str +=subtract(s1, s2);
            bdi2.sett(str);
            return bdi2;

        }
        else if(s1 < s2)
        {
            string str="-";
            str +=subtract(s1, s2);
            bdi2.sett(str);
            return bdi2;

        }
        else if(*this == bdi)
        {
            bdi2.sett("0");
            return bdi2;
        }
    }
    else if(a[0]=='-' && b[0]=='+')
    {
        string s1 = "", s2 = "";
        for(int i=1; i<a.length(); i++)
        {
            s1 += a[i];
            s2 += b[i];
        }
        if(s1 > s2)
        {
            string str="-";
            str += subtract(s1, s2);
            bdi2.sett(str);
            return bdi2;

        }
        else if(s1 < s2)
        {
            string str="+";
            str +=subtract(s1, s2);
            bdi2.sett(str);
            return bdi2;

        }
        else if(*this == bdi)
        {
            bdi2.sett("0");
            return bdi2;
        }
    }
}
BigDecimalInt BigDecimalInt:: operator-(BigDecimalInt& bdi)
{
    BigDecimalInt bdi2;
    string a = decStr;
    string b = bdi.gett();
    if(a[0]=='+' && b[0]=='-')
    {
        string s1 = "", s2 = "";
        for(int i=1; i<a.length(); i++)
        {
            s1 += a[i];
            s2 += b[i];
        }
        if(s1 > s2)
        {
            string sign="+";
            string str = add(a, b, sign);
            bdi2.sett(str);
            return bdi2;
        }
        else if(s1 < s2)
        {
            string sign="-";
            string str = add(a, b, sign);
            bdi2.sett(str);
            return bdi2;
        }
        else if(s1 == s2)
        {
            bdi2.sett("0");
            return bdi2;
        }
    }
    else if(a[0]=='-' && b[0]=='+')
    {
        string s1 = "", s2 = "";
        for(int i=1; i<a.length(); i++)
        {
            s1 += a[i];
            s2 += b[i];
        }
        if(s1 > s2)
        {
            string sign="-";
            string str = add(a, b, sign);
            bdi2.sett(str);
            return bdi2;
        }
        else if(s1 < s2)
        {
            string sign="+";
            string str = add(a, b, sign);
            bdi2.sett(str);
            return bdi2;
        }
        else if(s1 == s2)
        {
            bdi2.sett("0");
            return bdi2;
        }
    }
    else if(a[0]=='+' && b[0]=='+')
    {
        string s1 = "", s2 = "";
        for(int i=1; i<a.length(); i++)
        {
            s1 += a[i];
            s2 += b[i];
        }
        if(s1 > s2)
        {
            string str="+";
            str +=subtract(s1, s2);
            bdi2.sett(str);
            return bdi2;
        }
        else if(s1 < s2)
        {
            string str="-";
            str += subtract(a,b);
            bdi2.sett(str);
            return bdi2;
        }
        else if(*this == bdi)
        {
            bdi2.sett("0");
            return bdi2;
        }
    }
    else if(a[0]=='-' && b[0]=='-')
    {
        string s1 = "", s2 = "";
        for(int i=1; i<a.length(); i++)
        {
            s1 += a[i];
            s2 += b[i];
        }
        if(s1 > s2)
        {
            string str="-";
            str +=subtract(s1, s2);
            bdi2.sett(str);
            return bdi2;
        }
        else if(s1 < s2)
        {
            string str="+";
            str += subtract(a,b);
            bdi2.sett(str);
            return bdi2;
        }
        else if(*this == bdi)
        {
            bdi2.sett("0");
            return bdi2;
        }
    }
}



string BigDecimalInt:: subtract(string a,string b)
{
    if (a.length() < b.length())     // If second string is larger

    {
        swap(a, b);
    }
    int l1 = a.length(), l2 = b.length();
    int diffLen = l1 - l2;          // If lengths aren't equal

    for (int i = 0; i < diffLen; i++) // Insert 0's to the beginning of b to make both the lengths equal
    {
        b = "0" + b;
    }

    string c = sumBig(a, complement10(b));   // Add (complement of B) and A

    if (c.length() > a.length()) // If length of new string is greater than length of first string than carry is generated
    {
        string::iterator it;
        it = c.begin();
        c.erase(it);

        it = c.begin(); // Trim zeros at the beginning
        while (*it == '0')
        {
            c.erase(it);
        }
        return c;
    }

    else
    {
        return complement10(c);   // If both lengths are equal

    }

}

string BigDecimalInt:: complement10(string b)
{
    string complement=""; ///to get 10's complement -> 9's + 1

    for (int i = 0; i < b.size(); i++) // Calculate 9's complement
    {
        complement += '9' - b[i] + '0';
    }
    complement = sumBig(complement, "1"); //to add the one
    return complement;
}

string BigDecimalInt:: sumBig(string a, string b)
{
    if (a.length() > b.length())
    {
        swap(a, b);
    }

    string str="";
    int n1 = a.length(), n2 = b.length();
    int diff = n2 - n1;
    int carry = 0;

    for (int i = n1 - 1; i >= 0; i--) // to store from end of both strings
    {
        int sum = ((a[i] - '0') + (b[i + diff] - '0') + carry); //sum of current digits and carry

        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    // Add remaining digits of str2[]
    for (int i = n2 - n1 - 1; i >= 0; i--)
    {

        int sum = ((b[i] - '0') + carry);

        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)  //if there are remaining carry
    {
        str.push_back(carry + '0');
    }

    reverse(str.begin(),str.end());   // Reverse result string
    return str;
}

string BigDecimalInt:: add(string a, string b,string sign)
{
    string Tsum = "";
    if (a.size() > b.size())
    {
        addZeros(b, a.size() - b.size());
    }
    else if (a.size() < b.size())
    {
        addZeros(a, b.size() - a.size());
    }

    int aSz = a.size();
    int bSz = b.size();
    int carry = 0;
    while (aSz != 1 or bSz !=1)
    {
        bool valid = false;
        int sum;
        int x = 0, y = 0;
        if (aSz > 0)
        {
            x = a[aSz - 1] - '0';
            aSz--;
        }
        if (bSz > 0)
        {
            y = b[bSz - 1] - '0';
            bSz--;
        }
        sum = (carry + x + y);
        if (sum >= 10)
        {
            Tsum += returnChar(sum % 10);

            carry = 1;
        }
        else
        {
            carry = 0;
            Tsum += returnChar(sum);
        }
    }
    Tsum+=sign;
    if (!carry)
    {
        Tsum = reverseNumber(Tsum);
    }
    else
    {
        Tsum += returnChar(carry);
        Tsum = reverseNumber(Tsum);
    }
    removeZeros(Tsum);
    return Tsum;
}

//Function to reverse the number
string BigDecimalInt:: reverseNumber(string x)
{
    string FinalNumber = "";
    for (int i = x.size() - 1; i >= 0; i--)
    {
        FinalNumber += x[i];
    }
    return FinalNumber;
}
//Function to add zeros to equal the two numbers' lengths.
void BigDecimalInt:: addZeros(string& z, int sz)
{
    string m = "";
    for (int i = 0; i < sz; i++)
    {
        m += '0';
    }
    for (int i = 0; i < z.size(); i++)
    {
        m += z[i];
    }
    z = m;
}
//Function to remove all the leading zeros.
void BigDecimalInt:: removeZeros(string &s)
{
    int count_ = 0;
    if(s[0]=='0')
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') count_++;
            else break;
        }
    }
    if ((s[0]=='-' || s[0]=='+') && s[1]=='0')
    {
        int i=0;
        while (s[i+1]=='0')
            i++;
        if (i==s.length())
        {
            s.erase(1,i-1);
        }
        else
        {
            s.erase(1,i);
        }
    }
    s.erase(0, count_);
}
//Function to return the digit from int to char.
char BigDecimalInt:: returnChar(int x)
{
    switch(x)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    default:
        return '9';
    }
}

BigDecimalInt& BigDecimalInt :: operator= (const BigDecimalInt& dec2)  ///num4=num3
{
    decStr =dec2.decStr;
    decInt = dec2.decInt;
}

bool BigDecimalInt:: operator > (BigDecimalInt dec2)  ///if(decStr > dec2.decStr)
{
    removeZeros(decStr);
    removeZeros(dec2.decStr);
    if (dec2.decStr[0]=='-' && decStr[0]=='+')
    {
        return true;
    }
    else if(decStr[0]=='-' && dec2.decStr[0]=='+' )
    {
        return false;
    }
    else if(decStr[0]=='+' && dec2.decStr[0]=='+')
    {
        if(decStr.length()<dec2.decStr.length())
        {
            return false;
        }
        else if(decStr.length()>dec2.decStr.length())
        {
            return true;
        }
        else
        {
            for(int i=1; i<decStr.length(); i++)
            {
                if(decStr[i]>dec2.decStr[i])
                {
                    return true;
                    break;
                }
                else if(decStr[i] > dec2.decStr[i])
                {
                    return false;
                    break;
                }
            }
        }
    }
    else if(decStr[0]=='-' && dec2.decStr[0]=='-')
    {
        if(decStr.length() > dec2.decStr.length())
        {
            return false;
        }
        else if(decStr.length() < dec2.decStr.length())
        {
            return true;
        }
        else
        {
            for(int i=0; i<decStr.length(); i++)
            {
                if(decStr[i] < dec2.decStr[i])
                {
                    return true;
                    break;
                }
                else if(decStr[i] > dec2.decStr[i])
                {
                    return false;
                    break;
                }
            }
        }
    }
}

bool BigDecimalInt:: operator < (BigDecimalInt dec2)  ///if(decStr1 < decStr2)
{
    removeZeros(decStr);
    removeZeros(dec2.decStr);
    if ( decStr[0]=='+' && dec2.decStr[0]=='-')
    {
        return false;
    }
    else if(decStr[0]=='-' && dec2.decStr[0]=='+' )
    {
        return true;
    }
    else if(decStr[0]=='+' && dec2.decStr[0]=='+')
    {
        if(decStr.length() < dec2.decStr.length())
        {
            return true;
        }
        else if(decStr.length() > dec2.decStr.length())
        {
            return false;
        }
        else
        {
            for(int i=0; i<decStr.length(); i++)
            {
                if(decStr[i] > dec2.decStr[i])
                {
                    return false;
                    break;
                }
                else if(decStr[i] < dec2.decStr[i])
                {
                    return true;
                    break;
                }
            }
        }
    }
    else if(decStr[0]=='-' && dec2.decStr[0]=='-')
    {
        if(decStr.length() > dec2.decStr.length())
        {
            return true;
        }
        else if(decStr.length() < dec2.decStr.length())
        {
            return false;
        }
        else
        {
            for(int i=0; i<decStr.length(); i++)
            {
                if(decStr[i] < dec2.decStr[i])
                {
                    return false;
                    break;
                }
                else if(decStr[i] > dec2.decStr[i])
                {
                    return true;
                    break;
                }
            }
        }
    }
}

bool BigDecimalInt:: operator==(BigDecimalInt dec2)
{
    removeZeros(decStr);
    removeZeros(dec2.decStr);
    bool flag=true;
    if(decStr.length()!=dec2.decStr.length())
    {
        return false;
    }
    else
    {
        for(int i=0; i<decStr.length(); i++)
        {
            if(decStr[i]!=dec2.decStr[i])
            {
                flag = false;
            }
        }
        return flag;
    }

}

// regex to validate the given decStrbers.
bool BigDecimalInt:: validation(string s)
{
    regex decStr_format("[+-]?[0-9]+");
    return regex_match (s, decStr_format);
}

// function to return the sign
int BigDecimalInt:: sign()
{
    if(decStr[0]=='-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// function to return the size
int BigDecimalInt:: size_n()
{
    return (decStr.length()-1);
}

ostream& operator << (ostream& out, BigDecimalInt b)
{
    out<<b.decStr;
}

