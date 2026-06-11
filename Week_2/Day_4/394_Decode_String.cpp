#include <vector>
#include <string>
using namespace std;

class Solution {
    string decode(string &s, int &i) {
        string ans = "";
        int n = s.size();

        while (i < n && s[i] != ']') {
            if (isdigit(s[i])) {
                int d = 0;

                while (i < n && isdigit(s[i])) {
                    d = d * 10 + (s[i] - '0');
                    i++;
                }
                i++;

                string temp = decode(s, i);
                i++;

                while (d--) ans += temp;
            } else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    } 
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};