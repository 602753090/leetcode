//
//  main.cpp
//  27.removeElement
//
//  Created by 李雪峰 on 2024/3/17.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = (int)nums.size() - 1;
        int i = 0;
        while(i <= last) {
            if(nums[i] == val) {
                swap(nums[i], nums[last]);
                last--;
            }else {
                i++;
            }
        }
        return last + 1;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int i = s.removeElement(nums, 2);
    cout << i;
    return 0;
}

