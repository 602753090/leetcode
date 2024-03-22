//
//  main.cpp
//  189.rotate
//
//  Created by 李雪峰 on 2024/3/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate0(vector<int>& nums, int k) {
        int len = (int)nums.size();
        k = k % len;
        int n = len - k;
        int i = 0;
        vector<int> sup = nums;
        while (n < len) {
            nums[i++] = sup[n++];
        }
        n = 0;
        while (i < len) {
            nums[i++] = sup[n++];
        }
    }
    
    void mirror(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void rotate1(vector<int>& nums, int k) {
        int len = (int)nums.size();
        k = k % len;
        int n = len - k;
        mirror(nums, 0, n - 1);
        mirror(nums, n, len - 1);
        mirror(nums, 0, len - 1);
    }
};

int main() {
    vector<int> i = {5,3,3,4,3,3,2,1};
    Solution s;
    s.rotate1(i, 38);
    for (int n = 0; n < i.size(); n++) {
        cout << i[n];
    }
    return 0;
}
