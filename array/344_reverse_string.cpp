#include <iostream>
#include <vector>

class Solution
{
public:
    // Two pointers in opposite direction
    void reverseString(std::vector<char> &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            std::swap(s[i++], s[j--]);
        }
    }
};

// Simple test
int main()
{
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    sol.reverseString(s);
    for (auto c : s)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return 0;
}
