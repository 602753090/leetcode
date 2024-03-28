//
//  main.cpp
//  122.maxProfit
//
//  Created by 李雪峰 on 2024/3/28.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, i = 0;
        while(i + 1 < prices.size()) {
            if (prices[i + 1] > prices[i]) {
                profit += prices[i + 1] - prices[i];
            }
            i++;
        }
        return profit;
    }
};

int main() {
    vector<int> i = {1,2};
    Solution s;
    cout << s.maxProfit(i);
    return 0;
}
