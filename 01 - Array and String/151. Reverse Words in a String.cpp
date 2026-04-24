#include "../leetcode_test.hpp"

class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        int i = s.size() - 1;

        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int j = i;

            while (j >= 0 && s[j] != ' ')
                j--;

            if (!result.empty())
                result += ' ';
            result.append(s.substr(j + 1, i - j));

            i = j - 1;
        }

        return result;
    }
};

// LOCAL_TEST_BEGIN
#ifdef LOCAL_TEST
int main()
{
    {
        Solution solution;
        string s = "the sky is blue";
        string actual = solution.reverseWords(s);
        string expected = "blue is sky the";
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        string s = "  hello world  ";
        string actual = solution.reverseWords(s);
        string expected = "world hello";
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    {
        Solution solution;
        string s = "a good   example";
        string actual = solution.reverseWords(s);
        string expected = "example good a";
        leetcode::expectEqual(actual, expected, "Example 3");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
