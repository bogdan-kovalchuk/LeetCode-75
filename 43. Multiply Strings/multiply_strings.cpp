// Source : https://leetcode.com/problems/multiply-strings/
// Author : Bogdan Kovalchuk
// Date   : 2020-10-18

/**
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * Note:
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
**/

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1.length() < 2 || num2.length() < 2)
            return simpl_mul(num1, num2);

        int min_len = min(num1.length(), num2.length());
        int m = min_len / 2;

        string x0, x1, y0, y1, z0, z1, z2;

        x0 = num1.substr(num1.length() - m);
        x1 = num1.substr(0, num1.length() - m);

        y0 = num2.substr(num2.length() - m);
        y1 = num2.substr(0, num2.length() - m);

        z0 = multiply(x0, y0);
        z1 = add_str(multiply(x0, y1), multiply(y0, x1));
        z2 = multiply(x1, y1);

        pow10_str(z2, 2 * m);
        pow10_str(z1, m);

        return add_str(add_str(z2, z1), z0);
    }

    string add_str(const string &num1, const string &num2)
    {
        int sum = 0, i = num1.length() - 1, j = num2.length() - 1;
        string str;
        while (i >= 0 || j >= 0 || sum > 0)
        {
            if (i >= 0)
                sum += (num1[i--] - '0');
            if (j >= 0)
                sum += (num2[j--] - '0');
            str.insert(0, 1, (sum % 10) + '0');
            sum /= 10;
        }
        return str;
    }

    string simpl_mul(string num1, string num2)
    {
        string out = "0";
        if (num1.length() > num2.length())
        {
            swap(num1, num2);
        }

        for (int i = 0; i < num1[0] - '0'; ++i)
        {
            out = add_str(out, num2);
        }

        return out;
    }

    void pow10_str(string &num, int degree)
    {
        for (int i = 0; i < degree; ++i)
            num += '0';
    }
};

int main()
{
    string num1 = "233";
    string num2 = "3345";
    Solution solution;

    cout << solution.multiply(num1, num2) << endl;

    return 0;
}