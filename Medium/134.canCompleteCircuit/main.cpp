//
//  main.cpp
//  134.canCompleteCircuit
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 1) {
            if (gas[0] >= cost[0]) {
                return 0;
            } else {
                return -1;
            }
        }
        int i = 0, fuel = 0;
        int n;
        while (i < gas.size()) {
            fuel = 0;
            n = i;
            fuel += gas[n];
            if (fuel >= cost[n]) {
                fuel -= cost[n];
                n++;
                n %= (int)gas.size();
            } else {
                i++;
                continue;
            }
            while (n != i) {
                fuel += gas[n];
                if (fuel >= cost[n]) {
                    fuel -= cost[n];
                    n++;
                    n %= (int)gas.size();
                } else {
                    break;
                }
            }
            if (n == i) {
                return i;
            } else {
                if (n + 1 > i) {
                    i = n + 1;
                } else {
                    return -1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost);
    return 0;
}
