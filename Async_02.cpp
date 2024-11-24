// Async_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <thread>
#include <iostream>
#include <vector>
#include <future>

template<typename Iterator, typename T>
void for_each_personaly(Iterator begin, Iterator last, T init)
{
    
    int size = std::distance(begin, last);
    if (size < 2)
    {
        std::cout << *begin << std::endl;
    }
    else
    {
        Iterator middle = begin;
        std::advance(middle, size / 2);
        for (auto start{ begin }; begin != middle; begin++)
        {
            std::cout << *begin << " ";
        }
        std::async(for_each_personaly<Iterator, T>, middle, last, init);
    }
    
 
    
   


}
int main()
{
    std::vector<int> numbers{ 1,3,6,7,9,24,65,7 };
    for_each_personaly(numbers.begin(), numbers.end(), 0);
}
