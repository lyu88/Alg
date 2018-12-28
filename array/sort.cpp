#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>


using namespace std;

class Solution
{

public:
    Solution() {}

    vector<int> sort(vector<int> &array)
    {
        if (array.size() < 2)
            return array;
        return *merge_sort(array);
    }

    vector<int> insert_sort(vector<int> &array)
    {
        // don't use unsigned here because later j compared to int 0 will be always true.
        for (auto i = array.begin() + 1; i < array.end(); i++)
        {
            int key = *i;
            auto j = i-1;
            while (j >= array.begin() && *j > key)
            {
                *(j+1) = *j;
                j--;
            }
            *(j+1) = key;
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

    

    

private:
    vector<int>* merge_sort(vector<int> array, vector<int>::iterator left, vector<int>::iterator right)
    {
        if (left < right -1)
        {
            auto mid = left + (right-left) / 2;
            auto leftArray = merge_sort(array, left, mid);
            auto rightArray = merge_sort(array, mid, right);
            return merge(*leftArray, *rightArray);
        }
    }

    vector<int>* merge(vector<int> a, vector<int> b)
    {
        vector<int>* ret = new vector<int>;
        auto i = a.begin();
        auto j = b.begin();
        while (i < a.end() && j < b.end())
        {
            if (*i < *j)
                (*ret).push_back(*(i++));
            else
                (*ret).push_back(*(j++));
        }
        while (i < a.end())
            (*ret).push_back(*(i++));
        while (j < b.end())
            (*ret).push_back(*(j++));
        return ret;
    }


};

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10 };
    //int arr[] = {0,-1,0,1,1,1,-1,0,0,1,-1,0,1,-1};
    //string arr[] = {"4", "13", "5", "/", "+"};
    auto sol = Solution();
    vector<int> input(arr, arr + sizeof(arr)/sizeof(int));
    vector<int> a2 = {1,2,3,4,5,6,7,8,9,10};
    for (unsigned i = 0; i < input.size(); i++)
        cout << input.at(i) << ' ';
    cout << endl;
    auto output = sol.merge(input, a2);
    for (unsigned i = 0; i < (*output).size(); i++)
        cout << (*output).at(i) << ' ';
    cout << endl;
    return 0;
}