//
//  main.cpp
//  121.maxProfit
//
//  Created by 李雪峰 on 2024/3/26.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    //暴力法，超时
    int maxProfit0(vector<int>& prices) {
        int profit = 0, i = 0, j = 0, p = 0;
        while (i < prices.size()) {
            for (j = i; j < prices.size(); j++) {
                p = prices[j] - prices[i];
                if (p > profit) {
                    profit = p;
                }
            }
            i++;
        }
        return profit;
    }
    
    //递归
    int maxProfit1(vector<int>& prices) {
        int a = 0, b = (int)prices.size() - 1;
        return profit(prices, a, b);
    }
    int profit(vector<int>& prices, int a, int b) {
        int n = a;
        int max = 0, min = 100000;
        int i_max = 0, i_min = 0;
        while (n <= b) {
            if (prices[n] >= max) {
                max = prices[n];
                i_max = n;
            }
            if (prices[n] <= min) {
                min = prices[n];
                i_min = n;
            }
            n++;
        }
        if (i_max > i_min) {
            return prices[i_max] - prices[i_min];
        }
        if (i_max == i_min) {
            return 0;
        }
        int profit0 = 0, profit1 = profit(prices, i_max + 1, i_min - 1), profit2 = 0;
        for (n = a; n <= i_max; n++) {
            if (prices[i_max] - prices[n] > profit0) {
                profit0 = prices[i_max] - prices[n];
            }
        }
        for (n = i_min; n <= b; n++) {
            if (prices[n] - prices[i_min] > profit2) {
                profit2 = prices[n] - prices[i_min];
            }
        }
        if (profit0 > profit1) {
            if (profit0 > profit2) {
                return profit0;
            }
            return profit2;
        }
        if (profit1 > profit2) {
            return profit1;
        }
        return profit2;
    }
    
    //双指针
    int maxProfit2(vector<int>& prices) {
        int profit = 0, i = 0, buy = 0;
        while(i + 1 < prices.size()) {
            if (prices[i + 1] <= prices[i]) {
                if (prices[i] - prices[buy] > profit) {
                    profit = prices[i] - prices[buy];
                }
                i++;
                if (prices[i] < prices[buy]) {
                    buy = i;
                }
            }else {
                i++;
                if (prices[i] - prices[buy] > profit) {
                    profit = prices[i] - prices[buy];
                }
            }
        }
        return profit;
    }
    
    
    int maxProfit3(vector<int>& prices) {
        int min = prices[0], profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            }else {
                if (prices[i] - min > profit) {
                    profit = prices[i] - min;
                }
            }
        }
        return profit;
    }
};

int main() {
    vector<int> i = {1,2};
    Solution s;
    cout << s.maxProfit2(i);
    return 0;
}

