#include "../leetcode_test.hpp"

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int mx = *std::max_element(candies.begin(), candies.end());
        vector<bool> result;
        for (int n : candies)
        {
            result.push_back(n + extraCandies >= mx);
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
        vector<int> candies = vector<int>{2, 3, 5, 1, 3};
        int extraCandies = 3;
        vector<bool> actual = solution.kidsWithCandies(candies, extraCandies);
        vector<bool> expected = vector<bool>{true, true, true, false, true};
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        vector<int> candies = vector<int>{4, 2, 1, 1, 2};
        int extraCandies = 1;
        vector<bool> actual = solution.kidsWithCandies(candies, extraCandies);
        vector<bool> expected = vector<bool>{true, false, false, false, false};
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    {
        Solution solution;
        vector<int> candies = vector<int>{12, 1, 12};
        int extraCandies = 10;
        vector<bool> actual = solution.kidsWithCandies(candies, extraCandies);
        vector<bool> expected = vector<bool>{true, false, true};
        leetcode::expectEqual(actual, expected, "Example 3");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
