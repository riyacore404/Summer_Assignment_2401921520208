#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int n = s.size();
        int l = 0, h = n - 1;

        while (l < h) {
            while (l < h && !isalnum(s[l])) l++;
            while (l < h && !isalnum(s[h])) h--;

            if (s[l] != s[h]) return false;
            l++;
            h--;
        }

        return true;
    }
};