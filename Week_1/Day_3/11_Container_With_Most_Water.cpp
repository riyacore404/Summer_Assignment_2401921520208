#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, h = n - 1;
        int maxi = INT_MIN;

        while (l < h) {
            int vol = min(height[h],height[l]) * (h - l);
            maxi = max(maxi, vol);
            if (height[l] > height[h]) h--;
            else l++;
        }
        
        return maxi;
    }
};