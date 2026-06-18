#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev_smaller(n, -1);
        vector<int> next_smaller(n, n);
        stack<int> st;

        //prev-smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) prev_smaller[i] = st.top();
            st.push(i);
        }

        //next-smaller
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) next_smaller[i] = st.top();
            st.push(i);
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int width = next_smaller[i] - prev_smaller[i] - 1;
            max_area = max(max_area, heights[i] * width);
        }

        return max_area;
    }
};