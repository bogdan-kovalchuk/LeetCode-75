#include "../leetcode_test.hpp"

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; ++i)
        {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            result[i] *= suffix;
            suffix *= nums[i];
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
        vector<int> nums = vector<int>{1, 2, 3, 4};
        vector<int> actual = solution.productExceptSelf(nums);
        vector<int> expected = vector<int>{24, 12, 8, 6};
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        vector<int> nums = vector<int>{-1, 1, 0, -3, 3};
        vector<int> actual = solution.productExceptSelf(nums);
        vector<int> expected = vector<int>{0, 0, 9, 0, 0};
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
