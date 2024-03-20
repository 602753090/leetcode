#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int blank = -1, n = 0;
        while (n < s.size()) {
            if (s[n] == ' ') {
                blank = n;
            }
        }
        if (blank == -1) {
            return s.size();
        }
        return n - blank;
    }
};

int main() {
    string s;
    Solution so;
    cin >> s;
    cout << so.lengthOfLastWord(s);
    return 0;
}