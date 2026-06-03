#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int r = 0;
        while (r < n && nums[r] < 0) r++;
        int l = r - 1;

        vector<int> ans;
        while (l >= 0 && r < n) {
            if (nums[r] <= abs(nums[l])) {
                ans.push_back(nums[r] * nums[r]); r++;
            } else {
                ans.push_back(nums[l] * nums[l]); l--;
            }
        }

        while (l >= 0) { ans.push_back(nums[l] * nums[l]); l--; }
        while (r < n) { ans.push_back(nums[r] * nums[r]); r++; }

        return ans;
    }
};