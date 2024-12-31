#include <iostream>
#include <vector>

// Two pointers in same direction (Fast-Slow Pointers Approach)
int solution(std::vector<int> &a)
{
    int i = 0, j = 1;
    while (j < a.size())
    {
        if (a[i] != a[j])
        {
            i++;
            a[i] = a[j];
        }
        j++;
    }
    return i + 1;
}

// Simple test
int main()
{
    std::vector<int> a = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6};
    int len = solution(a);
    for (int i = 0; i < len; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}