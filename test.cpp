#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> v;
    if (n > 1)
    {
        k = k % n;
        for (int i = n - k; i < n; i++)
            v.push_back(nums[i]);
        for (int i = 0; i < n - k; i++)
            v.push_back(nums[i]);
        nums = v;
        v.clear();
        v.shrink_to_fit();
    }
}

int main()
{
    int n, k, temp;
    cin >> n >> k;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    rotate(nums, k);
    
    for(int i = 0; i < nums.size(); i++){
        cout << nums.at(i) << " "; 
    }

    cout << endl;
}