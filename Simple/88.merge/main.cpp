//
//  main.cpp
//  88.merge
//
//  Created by 李雪峰 on 2024/3/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void merge0(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int i = 0;
        while (i < m) {
            nums3.push_back(nums1[i]);
            i++;
        }
        int n2 = 0, n3 = 0;
        for (i = 0; n2 < n && n3 < m; i++) {
            if (nums2[n2] < nums3[n3]) {
                nums1[i] = nums2[n2];
                n2++;
            }else {
                nums1[i] = nums3[n3];
                n3++;
            }
        }
        if (n2 == n) {
            while (i < m + n) {
                nums1[i++] = nums3[n3++];
            }
        }
        if (n3 == m) {
            while (i < m + n) {
                nums1[i++] = nums2[n2++];
            }
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m > 0 && n > 0) {
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            }else {
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            }
        }
        if (m == 0) {
            while (m + n - 1 >= 0) {
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            }
        }
    }
};

int main() {
    vector<int> i1 = {2,5,6,9,11,17,0,0,0,0,0,0,0,0};
    vector<int> i2 = {1,3,6,8,10,19,20,44};
    Solution s;
    s.merge(i1, 6, i2, 8);
    for (int i = 0; i < i1.size(); i++) {
        cout << i1[i];
    }
    return 0;
}
