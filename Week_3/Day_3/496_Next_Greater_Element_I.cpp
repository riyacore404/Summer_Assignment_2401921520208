#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        vector<int> next_greater(n, -1);
        vector<int> ans;
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();
            if (!st.empty()) next_greater[i] = st.top();
            st.push(nums2[i]);
        }

        unordered_map<int,int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums2[i]] = next_greater[i];
        }

        for (int i : nums1) {
            ans.push_back(mpp[i]);
        }
        
        return ans;
    }
};