#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.size();
        int n = s.size();
        if (m > n) return {};

        vector<int> freq(26, 0);
        vector<int> ans;

        for (char c : p) freq[c - 'a']++;

        int c = m;
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a']-- > 0) c--;
            if (i >= m && freq[s[i - m] - 'a']++ >= 0) c++;
            if (c == 0) ans.push_back(i - m + 1);
        }

        return ans;
    }
};