#include "../leetcode_test.hpp"

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int i = 0;
        int j = nums.size() - 1;
        int maxOps = 0;

        std::sort(nums.begin(), nums.end());

        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                maxOps++;
                i++;
                j--;
            }
            else if (nums[i] + nums[j] < k)
                i++;
            else
                j--;
        }
        return maxOps;
    }
};

// LOCAL_TEST_BEGIN
#ifdef LOCAL_TEST
int main()
{
    {
        Solution solution;
        vector<int> nums = vector<int>{1, 2, 3, 4};
        int k = 5;
        int actual = solution.maxOperations(nums, k);
        int expected = 2;
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        vector<int> nums = vector<int>{3, 1, 3, 4, 3};
        int k = 6;
        int actual = solution.maxOperations(nums, k);
        int expected = 1;
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
