#include <iostream>
#include <vector>

// Brute force
int solution_1(std::vector<int> &height)
{
    int res = 0;
    for (int i = 1; i < height.size() - 1; i++)
    {
        int leftMax = 0, rightMax = 0;
        for (int j = i; j >= 0; j--)
        {
            leftMax = std::max(leftMax, height[j]);
        }
        for (int j = i; j < height.size(); j++)
        {
            rightMax = std::max(rightMax, height[j]);
        }
        res += std::min(leftMax, rightMax) - height[i];
    }
    return res;
}

int solution_2(std::vector<int> &height)
{
    int i = 0, j = 1, res = 0;
    if (height.size() == 0)
        return 0;
    while (i < height.size() - 2)
    {
        int barNum = 0;
        while (j < height.size() && height[j] < height[i])
        {
            barNum += height[j++];
        }
        if (j == height.size())
        {
            i++;
            j = i + 1;
        }
        else
        {
            res += (j - i - 1) * height[i] - barNum;
            i = j;
            j = i + 1;
        }
    }
    return res;
}

int solution_3(std::vector<int> &height)
{
    int i = 0, j = height.size() - 1, res = 0;
    while (j - i > 1)
    {
        int k;
        int curArea = 0;
        if (height[i] < height[j])
        {
            k = i + 1;
            while (height[k] < height[i])
            {
                curArea -= height[k++];
            }
            curArea += (k - i - 1) * height[i];
            res += curArea;
            i = k;
        }
        else
        {
            k = j - 1;
            while (height[k] < height[j])
            {
                curArea -= height[k--];
            }
            curArea += (j - k - 1) * height[k];
            res += curArea;
            j = k;
        }
    }
    return res;
}

// Simple test
int main()
{
    std::vector<int> height = {4, 2, 3};
    int res1 = solution_1(height);
    std::cout << res1 << std::endl;
    int res2 = solution_2(height);
    std::cout << res2 << std::endl;
    int res3 = solution_3(height);
    std::cout << res3 << std::endl;

    return 0;
}