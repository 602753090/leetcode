//
//  main.cpp
//  42.trap
//
//  Created by 李雪峰 on 2024/4/1.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }
        int ans = 0, a = 0, b = (int)height.size() - 1;
        int count = 2;
        int i;
        while (count > 1) {
            count = 0;
            while (height[a] == 0) {
                height[a] = -1;
                a++;
                if (a > b) {
                    return ans;
                }
            }
            while (height[b] == 0) {
                height[b] = -1;
                b--;
            }
            for (i = a; i <= b; i++) {
                if (height[i] == 0) {
                    ans++;
                } else if (height[i] != -1) {
                    height[i]--;
                    count++;
                }
            }
        }
        return ans;
    }
    
    int trap1(vector<int> height) {
        if (height.size() <= 2) {
            return 0;
        }
        int ans = 0, max = 0;
        int i = 0;
        int last = (int)height.size() - 1;
        int a, b;
        
        while (height[i] <= height[i + 1]) {
            i++;
            if (i == last) {
                break;
            }
        }
        a = i;
        i = last;
        
        while (height[i] < height[i - 1]) {
            i--;
            if (i == 0) {
                break;
            }
        }
        b = i;
        
        for (i = a; i <= b; i++) {
            ans -= height[i];
            if (height[i] >= height[max]) {
                max = i;
            }
        }
        ans += height[max];
        int left = max + 1, right = b, tempMax;
        while (left <= right) {
            tempMax = Max(height, left, right);
            ans += height[tempMax] * (tempMax - left + 1);
            left = tempMax + 1;
        }
        left = a;
        right = max - 1;
        while (right >= left) {
            tempMax = Max(height, left, right);
            ans += height[tempMax] * (right - tempMax + 1);
            right = tempMax - 1;
        }
        return ans;
    }
    int Max(vector<int> height, int left, int right) {
        int max = left;
        for (int i = left; i <= right; i++) {
            if (height[i] > height[max]) {
                max = i;
            }
        }
        return max;
    }
};

int main() {
    vector<int> height = {5,5,5,2,5,1,5,2};
    Solution s;
    cout << s.trap1(height);
    return 0;
}
