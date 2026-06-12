#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;
            for (int i : v) {
                hash ^= hash * 31 + i;
            }
            return hash;
        }
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHash> mpp;

        for (auto& str : strs) {
            vector<int> freq(26, 0);
            for (char c : str) freq[c - 'a']++;

            mpp[freq].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};