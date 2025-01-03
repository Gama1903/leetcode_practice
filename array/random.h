#pragma once

#include <random>
#include <vector>
#include <iostream>
#include <type_traits>

#define MINNUM 0
#define MAXNUM 100

// random device
thread_local std::random_device rd{};

// random number generator
thread_local std::mt19937 gen{rd()};

template <typename T>
T rand(T min = MINNUM, T max = MAXNUM)
{
    if constexpr (std::is_same<T, int>::value)
    {
        std::uniform_int_distribution<int> dis{min, max};
        return dis(gen);
    }
    else if constexpr (std::is_same<T, float>::value)
    {
        std::uniform_real_distribution<float> dis{min, max};
        return dis(gen);
    }
    else if constexpr (std::is_same<T, double>::value)
    {
        std::uniform_real_distribution<double> dis{min, max};
        return dis(gen);
    }
    else
    {
        static_assert(false, "Type not supported");
        return 0;
    }
}

// random array generator
template <typename T>
std::vector<T> randarray(int size, int min = MINNUM, int max = MAXNUM)
{
    std::vector<T> arr{};
    arr.reserve(size);
    if constexpr (std::is_same<T, int>::value)
    {
        for (int i = 0; i < size; i++)
        {
            arr.push_back(rand<int>(min, max));
        }
    }
    else if constexpr (std::is_same<T, float>::value)
    {
        for (int i = 0; i < size; i++)
        {
            arr.push_back(rand<float>(min, max));
        }
    }
    else if constexpr (std::is_same<T, double>::value)
    {
        for (int i = 0; i < size; i++)
        {
            arr.push_back(rand<double>(min, max));
        }
    }
    else
    {
        static_assert(false, "Type not supported");
    }
    return arr;
}