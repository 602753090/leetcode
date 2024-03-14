//
//  main.cpp
//  14.longestCommonPrefix
//
//  Created by 李雪峰 on 2024/3/14.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        string prefix = "";
        int i = 0, n = 0;
        while(n < 200) {
            i = 0;
            while(i+1 < strs.size()) {
                if(strs[i] == "") return "";
                if(n >= strs[i].size() || n >= strs[i+1].size()) return prefix;
                if(strs[i][n] == strs[i+1][n]) {
                    i++;
                }else {
                    break;
                }
            }
            if(i+1 != strs.size()) {
                break;
            }else {
                prefix += strs[0][n];
                n++;
            }
        }
        return prefix;
    }
};

int main() {
    while (1) {
        int i;
        cin >> i;
        vector<string> s;
        s.resize(i);
        for(int n = 0; n < i; n++) {
            cin >> s[n];
        }
        Solution solu;
        std::cout << solu.longestCommonPrefix(s) << std::endl;
    }
}

