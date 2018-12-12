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
        return insert_sort(array);
    }

    vector<int> insert_sort(vector<int> &array)
    {
        if ( array.size() < 2)
            return array;
        // don't use unsigned here because later j compared to int 0 will be always true.
        for (int i = 1; i < array.size(); i++)
        {
            int j = i-1;
            auto key = array.at(i);

            while (j >= 0 && array.at(j) > key)
            {
                array.at(j+1) = array.at(j);
                j--;
            }
            array.at(j+1) = key;
        }
        return array;
    }

private:
    void swap(vector<int> array, int a, int b)
    {
        int temp = array.at(a);
        array.at(a) = array.at(b);
        array.at(b) = temp;
    }
};

int main() {
    int arr[] = {5,7,10,9,8,1,3,6,4,2};
    //int arr[] = {0,-1,0,1,1,1,-1,0,0,1,-1,0,1,-1};
    //string arr[] = {"4", "13", "5", "/", "+"};
    auto sol = Solution();
    vector<int> input(arr, arr + sizeof(arr)/sizeof(int));
    for (unsigned i = 0; i < input.size(); i++)
        cout << input.at(i) << ' ';
    cout << endl;
    sol.sort(input);
    for (unsigned i = 0; i < input.size(); i++)
        cout << input.at(i) << ' ';
    cout << endl;
    return 0;
}