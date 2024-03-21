//
//  main.cpp
//  66.plusOne
//
//  Created by 李雪峰 on 2024/3/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = (int)digits.size() - 1;
        vector<int>::iterator it;
        it = digits.begin();
        while (n >= 0) {
            digits[n]++;
            if (digits[n] == 10) {
                digits[n] = 0;
                if (n == 0) {
                    digits.insert(it, 1);
                }
                n--;
            }else {
                return digits;
            }
        }
        return digits;
    }
};

int main() {
    int i, n;
    vector<int> v;
    Solution so;
    for (n = 5; n > 0; n--) {
        cin >> i;
        v.push_back(i);
    }
    v = so.plusOne(v);
    while (n < v.size()) {
        cout << v[n];
        n++;
    }
    return 0;
}
