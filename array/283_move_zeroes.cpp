#include <iostream>
#include <vector>
#include "random.h"

#define MINNUM 0
#define MAXNUM 100

class Solution
{
public:
    // Two pointers in same direction
    void moveZeroes(std::vector<int> &nums)
    {
        int i = 0;
        for (auto &num : nums)
        {
            if (num != 0)
            {
                std::swap(nums[i++], num);
            }
        }
    }
};

// Test
int main()
{
    int size = 10;
    std::vector<int> nums{randarray<int>(size)};
    Solution sol;
    sol.moveZeroes(nums);
    for (auto &num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}