#include "../leetcode_test.hpp"
#include <numeric>

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sumLeft = 0;
        int sumRight = std::accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            sumRight -= nums[i];

            if (sumLeft == sumRight)
                return i;

            sumLeft += nums[i];
        }

        return -1;
    }
};

// LOCAL_TEST_BEGIN
#ifdef LOCAL_TEST
int main()
{
    {
        Solution solution;
        vector<int> nums = vector<int>{1, 7, 3, 6, 5, 6};
        int actual = solution.pivotIndex(nums);
        int expected = 3;
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        vector<int> nums = vector<int>{1, 2, 3};
        int actual = solution.pivotIndex(nums);
        int expected = -1;
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    {
        Solution solution;
        vector<int> nums = vector<int>{2, 1, -1};
        int actual = solution.pivotIndex(nums);
        int expected = 0;
        leetcode::expectEqual(actual, expected, "Example 3");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
