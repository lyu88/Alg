#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>


using namespace std;

class Solution
{

public:
    Solution() {};

    vector<int> sort(vector<int> &array)
    {
        if (array.size() < 2)
            return array;
        merge_sort(array, array.begin(), array.end());
        return array;
    }

private:
    vector<int> insert_sort(vector<int> &array)
    {
        // don't use unsigned here because later j compared to int 0 will be always true.
        for (int i = 1; i < array.size(); i++)
        {
            int key = array[i];
            auto j = i - 1;
            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
        return array;
    }

    vector<int> select_sort(vector<int> &array)
    {
        for (auto i = array.begin(); i < array.end(); i++)
        {
            auto index = i;
            int key = *i;
            for (auto j = i + 1; j < array.end(); j++)
            {
                if (*j < key)
                {
                    key = *j;
                    index = j;
                }
            }
            iter_swap(i, index);
        }
        return array;
    }

    void merge_sort(vector<int> &array, vector<int>::iterator left, vector<int>::iterator right)
    {
        if (left < right - 1)
        {
            auto mid = left + (right - left) / 2;
            merge_sort(array, left, mid);
            merge_sort(array, mid, right);
            merge(array, left, right);
        }
    }

    void merge(vector<int> &a, vector<int>::iterator left, vector<int>::iterator right)
    {
        auto mid = left + (right - left) / 2;
        vector<int> b(left, mid);
        vector<int> c(mid, right);
        auto i = left; // be careful about this starting point
        auto j = b.begin();
        auto k = c.begin();
        while (j < b.end() && k < c.end())
        {
            if (*j < *k)
                *i++ = *j++;
            else
                *i++ = *k++;
        }
        while (j < b.end())
            *i++ = *j++;
        while (k < c.end())
            *i++ = *k++;
    }


};

int main() {
    
    //int arr[] = {0,-1,0,1,1,1,-1,0,0,1,-1,0,1,-1};
    //string arr[] = {"4", "13", "5", "/", "+"};
    auto sol = Solution();
    //int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    //vector<int> a2 = { 1,2,3,4,5,6,7,8,9,10 };
    //vector<int> input(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> input = {5,2,1,4,8,6,7,9,10,3};
    
    for (unsigned i = 0; i < input.size(); i++)
        cout << input.at(i) << ' ';
    cout << endl;
    sol.sort(input);
    for (unsigned i = 0; i < (input).size(); i++)
        cout << (input).at(i) << ' ';
    cout << endl;
    getchar();
    return 0;
}