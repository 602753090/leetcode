//
//  main.cpp
//  28.strStr
//
//  Created by 李雪峰 on 2024/3/19.
//

#include <iostream>
#include <string>
using namespace std;

// 简单题暂且不使用KMP算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) {
            return -1;
        }
        int h = 0, n = 0;
        while(h < haystack.size() && n < needle.size()) {
            if(haystack[h] == needle[n]) {
                h++;
                n++;
            }else {
                h = h - n + 1;
                n = 0;
            }
        }
        if(n == needle.size()) {
            return h - (int)needle.size();
        }
        return -1;
    }
};

int main() {
    Solution s;
    string s1, s2;
    cin >> s1 >> s2;
    cout << s.strStr(s1, s2);
    return 0;
}
