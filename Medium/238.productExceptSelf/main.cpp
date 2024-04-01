//
//  main.cpp
//  238.productExceptSelf
//
//  Created by 李雪峰 on 2024/3/30.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        int count[31];
        int temp = 1, neg = 0;
        
        for (int i = 0; i < 31; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            count[abs(nums[i])]++;
            if (nums[i] < 0) {
                neg++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            temp = 1;
            for (int j = 0; j < 31; j++) {
                if (count[j] == 0) {
                    continue;
                }
                if (j == abs(nums[i])) {
                    if (count[j] - 1 == 0) {
                        continue;
                    }
                    temp *= pow(j, (count[j] - 1));
                }else {
                    temp *= pow(j, count[j]);
                }
            }
            if (nums[i] < 0) {
                neg--;
                if (neg % 2 == 0) {
                    ret.push_back(temp);
                }else{
                    ret.push_back(0 - temp);
                }
                neg++;
            }else {
                if (neg % 2 == 0) {
                    ret.push_back(temp);
                }else{
                    ret.push_back(0 - temp);
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {4,3,2,1,2};
    Solution s;
    vector<int> ret = s.productExceptSelf(nums);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }
    return 0;
}

