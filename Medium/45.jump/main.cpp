//
//  main.cpp
//  45.jump
//
//  Created by 李雪峰 on 2024/3/28.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int i = 0, max = nums[0], n = 0, step = 0, temp = 0;
        while (max < nums.size() - 1) {
            if (i <= step + nums[step]) {
                if (i + nums[i] > max) {
                    max = i + nums[i];
                    if (max >= nums.size() - 1) {
                        step = temp;
                        n++;
                    }
                    temp = i;
                }
                i++;
            }else {
                step = temp;
                n++;
            }
        }
        return n + 1;
    }
};

int main() {
    vector<int> i = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    Solution s;
    cout << s.jump(i);
    return 0;
}

