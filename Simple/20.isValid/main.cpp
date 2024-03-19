//
//  main.cpp
//  20.isValid
//
//  Created by 李雪峰 on 2024/3/15.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                v.push_back(s[i]);
            }else {
                if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                    if(v.size() == 0) {
                        return false;
                    }
                    if(v.back() == '(' && s[i] == ')') {
                        v.pop_back();
                        continue;
                    }
                    if(v.back() == '[' && s[i] == ']') {
                        v.pop_back();
                        continue;
                    }
                    if(v.back() == '{' && s[i] == '}') {
                        v.pop_back();
                        continue;
                    }else {
                        return false;
                    }
                }
            }
        }
        if(v.size() == 0) {
            return true;
        }else {
            return false;
        }
    }
};

int main() {
    while (1) {
        string input;
        cin >> input;
        Solution solu;
        if(solu.isValid(input)) {
            cout << "true" << endl;
        }else {
            cout << "false" << endl;
        }
    }
}
