#include <iostream>
#include <vector>

class Solution
{
public:
    // Brute force
    int maxArea_1(std::vector<int> &height)
    {
        int res = 0;
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int minHeight = std::min(height[i], height[j]);
                res = std::max(res, minHeight * (j - i));
            }
        }
        return res;
    }
    // Two pointers in opposite direction
    int maxArea_2(std::vector<int> &height)
    {
        int i = 0, j = height.size() - 1, res = 0;
        while (i < j)
        {
            int minHeight = std::min(height[i], height[j]);
            res = std::max(res, minHeight * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};

// Simple test
int main()
{
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    if (sol.maxArea_1(height) == sol.maxArea_2(height))
    {
        std::cout << sol.maxArea_1(height) << std::endl;
        return 0;
    }
    return -1;
}