//
//  main.cpp
//  35.searchInsert
//
//  Created by 李雪峰 on 2024/3/19.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int tail = (int)nums.size(), head = 0;
        int mid = (head + tail) / 2;
        while(head != mid) {
            if(target > nums[mid]) {
                head = mid;
                mid = (head + tail) / 2;
            }
            if(target < nums[mid]) {
                tail = mid;
                mid = (head + tail) / 2;
            }
            if(target == nums[mid]) {
                return mid;
            }
        }
        if(target < nums[mid]) {
            return mid;
        }
        if(target > nums[mid]){
            return mid + 1;
        }
        return mid;
    }
};

int main() {
    vector<int> nums = {1,3,4,5,6,8,9,10,13,16};
    int i = 0;
    Solution s;
    cin >> i;
    cout << s.searchInsert(nums, i);
    return 0;
}
