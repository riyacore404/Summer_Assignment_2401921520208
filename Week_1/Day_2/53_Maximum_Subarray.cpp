#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // JUST SLIGHTLY BETTER THAN [O(N*N] -- BRUTE FORCE [O(N*N*N)]
        int m = INT_MIN;
        int s = 0;
        for (int i = 0; i < nums.size(); i++){ 
            s += nums[i];
            if (s > m){
                m = s;
            }
            if (s < 0){
                s = 0;
            }
        }
        return m;
    }
};