//
//  main.cpp
//  274.hIndex
//
//  Created by 李雪峰 on 2024/3/29.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int count[1001];
        int i = 0, max = 0;
        for (i = 0; i < 1001; i++) {
            count[i] = 0;
        }
        for (i = 0; i < citations.size(); i++) {
            count[citations[i]]++;
            if (citations[i] > max) {
                max = citations[i];
            }
        }
        for (i = max - 1; count[i + 1] < i + 1; i--) {
            count[i] += count[i + 1];
        }
        return i + 1;
    }
};

int main() {
    vector<int> i = {0,2,1000};
    Solution s;
    cout << s.hIndex(i);
    return 0;
}
