#include "../leetcode_test.hpp"

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int altitude = 0;
        int maxAltitude = 0;

        for (int x : gain)
        {
            altitude += x;
            maxAltitude = std::max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};

// LOCAL_TEST_BEGIN
#ifdef LOCAL_TEST
int main()
{
    {
        Solution solution;
        vector<int> gain = vector<int>{-5, 1, 5, 0, -7};
        int actual = solution.largestAltitude(gain);
        int expected = 1;
        leetcode::expectEqual(actual, expected, "Example 1");
    }

    {
        Solution solution;
        vector<int> gain = vector<int>{-4, -3, -2, -1, 4, 3, 2};
        int actual = solution.largestAltitude(gain);
        int expected = 0;
        leetcode::expectEqual(actual, expected, "Example 2");
    }

    leetcode::printTestsPassed();
    return 0;
}
#endif
// LOCAL_TEST_END
