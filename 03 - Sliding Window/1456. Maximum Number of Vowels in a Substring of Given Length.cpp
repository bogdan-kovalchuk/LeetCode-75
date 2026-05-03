#include "../leetcode_test.hpp"

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        std::string vowels = "aeiou";
        int n_vowels = 0;

        for (int i = 0; i < k; ++i)
            if (vowels.find(s[i]) != std::string::npos)
                n_vowels++;

        int max_vowels = n_vowels;

        for (int i = k; i < s.length(); ++i)
        {
            if (vowels.find(s[i - k]) != std::string::npos)
                n_vowels--;

            if (vowels.find(s[i]) != std::string::npos)
                n_vowels++;

            max_vowels = std::max(max_vowels, n_vowels);
        }
        return max_vowels;
    }
};

// LOCAL_TEST_BEGIN
#ifdef LOCAL_TEST
int main()
{
    {
        Solution solution;
        string s = "abciiidef";
        int k = 3;
        int actual = solution.maxVowels(s, k);
        int expected = 3;
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        string s = "aeiou";
        int k = 2;
        int actual = solution.maxVowels(s, k);
        int expected = 2;
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    {
        Solution solution;
        string s = "leetcode";
        int k = 3;
        int actual = solution.maxVowels(s, k);
        int expected = 2;
        leetcode::expectEqual(actual, expected, "Example 3");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
