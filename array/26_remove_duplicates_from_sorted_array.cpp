#include <iostream>
#include <vector>

class Solution
{
public:
    // Two pointers in same direction
    int removeDuplicates(std::vector<int> &nums)
    {
        int i = 0, j = 1;
        while (j < nums.size())
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};

// Simple test
int main()
{
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6};
    Solution sol;
    int len = sol.removeDuplicates(nums);
    for (int i = 0; i < len; i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    return 0;
}