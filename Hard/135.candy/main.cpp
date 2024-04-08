//
//  main.cpp
//  135.candy
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
    int candy(vector<int>& ratings) {
        int sum = 0, i = 0;
        int temp;
        vector<int> can;
        can.resize(ratings.size(), 1);
        for (i = 0; i < can.size() - 1; i++) {
            if (ratings[i + 1] > ratings[i] && can[i] >= can[i + 1]) {
                can[i + 1] = can[i] + 1;
            }
        }
        for (i = (int)can.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i] && can[i - 1] <= can[i]) {
                can[i - 1] = can[i] + 1;
            }
        }
        for (i = 0; i < can.size(); i++) {
            sum += can[i];
        }
        return sum;
    }
};

int main() {
    vector<int> ratings = {1,6,10,8,7,3,2};
    Solution s;
    cout << s.candy(ratings);
    return 0;
}
