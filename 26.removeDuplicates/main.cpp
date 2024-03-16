//
//  main.cpp
//  26.removeDuplicates
//
//  Created by 李雪峰 on 2024/3/16.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, n = 0, temp = nums[0];
        while(n < nums.size()) {
            if(nums[n] == temp) {
                n++;
            }else {
                temp = nums[n];
                i++;
                nums[i] = temp;
                n++;
            }
        }
        return i + 1;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int i = s.removeDuplicates(nums);
    return 0;
}
