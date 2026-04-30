#include "../leetcode_test.hpp"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int max_water_amount = 0;

        while (i < j)
        {
            int width = j - i;
            int water_amount = min(height[i], height[j]) * width;

            if (water_amount > max_water_amount)
                max_water_amount = water_amount;

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return max_water_amount;
    }
};

// LOCAL_TEST_BEGIN
#ifdef LOCAL_TEST
int main()
{
    {
        Solution solution;
        vector<int> height = vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7};
        int actual = solution.maxArea(height);
        int expected = 49;
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        vector<int> height = vector<int>{1, 1};
        int actual = solution.maxArea(height);
        int expected = 1;
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
