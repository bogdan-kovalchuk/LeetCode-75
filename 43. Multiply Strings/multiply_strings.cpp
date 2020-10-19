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
// #include <math.h>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1.length() == 1 || num2.length() == 1)
            return to_string(stoi(num1) * stoi(num2));

        int m = min(num1.size(), num2.size()) / 2;

        string x0, x1, y0, y1;
        int z0, z1, z2;

        x0 = num1.substr(m);
        x1 = num1.substr(0, m);

        y0 = num2.substr(m);
        y1 = num2.substr(0, m);

        z0 = stoi(multiply(x0, y0));
        z1 = stoi(multiply(x1, y0)) + stoi(multiply(x0, y1));
        z2 = stoi(multiply(x1, y1));

        return to_string(z2 * 10 ^ (m * 2) + (z1 - z2 - z0) * 10 ^ m + z0);
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