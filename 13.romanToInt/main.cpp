//
//  main.cpp
//  leetcode
//
//  Created by 李雪峰 on 2024/3/8.
//

#include <iostream>
#include <stdio.h>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        int num = 0;
        int i = 0, flag = 1;
        int sub[16];
        while (s[i] != '\0') {
            if (s[i] == 'M') {
                sub[i] = 1000;
            }
            if (s[i] == 'D') {
                sub[i] = 500;
            }
            if (s[i] == 'C') {
                sub[i] = 100;
            }
            if (s[i] == 'L') {
                sub[i] = 50;
            }
            if (s[i] == 'X') {
                sub[i] = 10;
            }
            if (s[i] == 'V') {
                sub[i] = 5;
            }
            if (s[i] == 'I') {
                sub[i] = 1;
            }
            i++;
        }
        sub[i] = 0;
        while (sub[flag] != 0) {
            if (sub[flag - 1] >= sub[flag]) {
                num += sub[flag - 1];
            }else {
                num -= sub[flag - 1];
            }
            flag++;
        }
        num += sub[flag - 1];
        return num;
    }
};

int main() {
    while (1) {
        std::string input;
        std::cin >> input;
        Solution solu;
        std::cout << solu.romanToInt(input) << std::endl;
    }
}
