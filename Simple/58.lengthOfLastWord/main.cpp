//
//  main.cpp
//  58.lengthOfLastWord
//
//  Created by 李雪峰 on 2024/3/20.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, n = (int)s.size() - 1;
        while (s[n] == ' ') {
            n--;
        }
        while (n >= 0 && s[n] != ' ') {
            len++;
            n--;
        }
        return len;
    }
};

int main() {
    string s;
    Solution so;
    getline(cin, s);
    cout << so.lengthOfLastWord(s);
    return 0;
}


