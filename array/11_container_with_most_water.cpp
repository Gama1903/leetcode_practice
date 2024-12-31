#include <iostream>
#include <vector>

// Brute force
int solution_1(std::vector<int> &height)
{
    int maxArea = 0;
    for (int i = 0; i < height.size() - 1; i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int minHeight = std::min(height[i], height[j]);
            maxArea = std::max(maxArea, minHeight * (j - i));
        }
    }
    return maxArea;
}

// Two pointers in opposite direction
int solution_2(std::vector<int> &height)
{
    int i = 0, j = height.size() - 1, maxArea = 0;
    while (i < j)
    {
        int minHeight = std::min(height[i], height[j]);
        maxArea = std::max(maxArea, minHeight * (j - i));
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxArea;
}

// Simple test
int main()
{
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    if (solution_1(height) == solution_2(height))
    {
        std::cout << solution_1(height) << std::endl;
        return 0;
    }
    return -1;
}