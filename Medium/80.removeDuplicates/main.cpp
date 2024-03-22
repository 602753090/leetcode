//
//  main.cpp
//  80.removeDuplicates
//
//  Created by 李雪峰 on 2024/3/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates0(vector<int>& nums) {
        int i = 0, n = 0;
        int flag = nums[i];
        vector<int>::iterator it;
        it = nums.begin();
        while (i < nums.size()) {
            if (nums[i] == flag) {
                if (n < 2) {
                    n++;
                    i++;
                    it++;
                }else {
                    nums.erase(it);
                }
            }else {
                flag = nums[i];
                n = 0;
            }
        }
        return i;
    }
    
    int removeDuplicates(vector<int>& nums, int numOfDup) {
        int i = 0, j = numOfDup;
        if (nums.size() <= numOfDup) {
            return (int)nums.size();
        }
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                nums[i + numOfDup] = nums[j];
                i++;
            }
            j++;
        }
        return i + numOfDup;
    }
};

int main() {
    vector<int> i = {2,5,6,9,9,9,11,17,17,17,17,17,17,19,19,19};
    Solution s;
    s.removeDuplicates(i, 2);
    for (int n = 0; n < i.size(); n++) {
        cout << i[n] << ' ';
    }
    return 0;
}
