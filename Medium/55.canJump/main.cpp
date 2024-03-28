//
//  main.cpp
//  55.canJump
//
//  Created by 李雪峰 on 2024/3/28.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        if (nums[0] == 0) {
            return false;
        }
        return jump(nums, 0);
    }
    bool jump(vector<int>& nums, int i) {
        int n = i + 1;
        if (i + nums[i] >= nums.size() - 1) {
            return true;
        }
        while (n <= i + nums[i]) {
            if (jump(nums, n)) {
                return true;
            }
            n++;
        }
        return false;
    }
    
    bool canJump1(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int i = 0, max = nums[0];
        while (i < max) {
            i++;
            if (i + nums[i] > max) {
                max = i + nums[i];
            }
            if (max >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> i = {1,0};
    Solution s;
    cout << s.canJump1(i);
    return 0;
}
