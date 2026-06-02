#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto& x : nums) {
            mpp[x]++;
            if (mpp[x] > 1) return true; 
        }
        return false;
    }
};