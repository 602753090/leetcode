//
//  main.cpp
//  169.majorityElement
//
//  Created by 李雪峰 on 2024/3/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement0(vector<int>& nums) {
        struct index {
            int num;
            int count;
            index(int a, int b) : num(a), count(b) {}
        };
        vector<index> table;
        int n = 0, i = 0;
        bool flag = false;
        while (n < nums.size()) {
            flag = false;
            i = 0;
            while (i < table.size()) {
                if (table[i].num == nums[n]) {
                    table[i].count++;
                    if (table[i].count > nums.size() / 2) {
                        return table[i].num;
                    }
                    flag = true;
                    break;
                }
                i++;
            }
            if (!flag) {
                index newindex(nums[n], 1);
                table.push_back(newindex);
            }
            n++;
        }
        return table[i].num;
    }
    
    //摩尔投票法
    int majorityElement(vector<int>& nums) {
        int ret = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (ret == nums[i]) {
                count++;
            }
            if (ret != nums[i]) {
                count--;
            }
            if (count == 0) {
                ret = nums[i + 1];
                count++;
                i++;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> i = {5,3,3,4,3};
    Solution s;
    cout << s.majorityElement(i);
    return 0;
}
