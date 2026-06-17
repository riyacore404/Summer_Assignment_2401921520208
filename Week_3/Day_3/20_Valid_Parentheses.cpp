#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size(), i = 0;
        while (i < n) {
            while (i < n && (s[i]=='(' || s[i]=='[' || s[i]=='{')) {
                st.push(s[i]);
                i++;
            } 
            while (i < n && (s[i]==')' || s[i]==']' || s[i]=='}')) {
                if (st.empty()) return false;
                char o = st.top(), c = s[i];
                if (o=='(' && c==')' || o=='[' && c==']' || o=='{' && c=='}') {
                    st.pop();
                } 
                else return false;
                i++;
            }
        }
        return st.empty();
    }
};