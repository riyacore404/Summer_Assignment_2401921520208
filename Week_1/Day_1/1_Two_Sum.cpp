#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0; 
        int h = n - 1;

        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());

        while (l < h) {
            int sum = nums2[l] + nums2[h];
            if (sum == target) break;
            else if (sum > target) h--;
            else l++;
        }

        int i1 = -1, i2 = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == nums2[l] && i1 == -1) i1 = i;
            else if (nums[i] == nums2[h] && i2 == -1) i2 = i;
        }

        return {i1, i2};
    }
};