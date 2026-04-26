#include "../leetcode_test.hpp"

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int first = INT_MAX;
        int second = INT_MAX;

        for (auto num : nums)
        {
            if (num <= first)
                first = num;
            else if (num <= second)
                second = num;
            else
                return true;
        }
        return false;
    }
};

// LOCAL_TEST_BEGIN
#ifdef LOCAL_TEST
int main()
{
    {
        Solution solution;
        vector<int> nums = vector<int>{1, 2, 3, 4, 5};
        bool actual = solution.increasingTriplet(nums);
        bool expected = true;
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        vector<int> nums = vector<int>{5, 4, 3, 2, 1};
        bool actual = solution.increasingTriplet(nums);
        bool expected = false;
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    {
        Solution solution;
        vector<int> nums = vector<int>{2, 1, 5, 0, 4, 6};
        bool actual = solution.increasingTriplet(nums);
        bool expected = true;
        leetcode::expectEqual(actual, expected, "Example 3");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
