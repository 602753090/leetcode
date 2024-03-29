//
//  main.cpp
//  380.RandomizedSet
//
//  Created by 李雪峰 on 2024/3/29.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RandomizedSet {
private:
    struct Node {
        int val;
        int index;
    };
    vector<Node> hash[10240];
    vector<int> plist;
    vector<int> nlist;
    
public:
    RandomizedSet() {
        srand((unsigned)time(0));
    }
    
    bool insert(int val) {
        int key = abs(val) % 10240;
        Node node;
        node.val = val;
        for (int i = 0; i < hash[key].size(); i++) {
            if (hash[key][i].val == val) {
                return false;
            }
        }
        if (val > 0) {
            node.index = (int)plist.size();
            plist.push_back(val);
        }else {
            node.index = (int)nlist.size();
            nlist.push_back(val);
        }
        hash[key].push_back(node);
        return true;
    }
    
    bool remove(int val) {
        int key = abs(val) % 10240;
        int last;
        vector<Node>::iterator it = hash[key].begin();
        for (int i = 0; i < hash[key].size(); i++, it++) {
            if (hash[key][i].val == val) {
                if (val > 0) {
                    last = plist[(int)plist.size() - 1];
                }else {
                    last = nlist[(int)nlist.size() - 1];
                }
                int key2 = abs(last) % 10240;
                for (int n = 0; n < hash[key2].size(); n++) {
                    if (hash[key2][n].val == last) {
                        hash[key2][n].index = hash[key][i].index;
                    }
                }
                if (val > 0) {
                    swap(plist[hash[key][i].index], plist[(int)plist.size() - 1]);
                    plist.pop_back();
                }else {
                    swap(nlist[hash[key][i].index], nlist[(int)nlist.size() - 1]);
                    nlist.pop_back();
                }
                hash[key].erase(it);
                return true;
            }
        }
        return false;
    }
    
    int getRandom() {
        int sign = rand() % 2;
        int random;
        if (sign == 0) {
            if (plist.size() == 0) {
                random = rand() % nlist.size();
                return nlist[random];
            }
            random = rand() % plist.size();
            return plist[random];
        }else {
            if (nlist.size() == 0) {
                random = rand() % plist.size();
                return plist[random];
            }
            random = rand() % nlist.size();
            return nlist[random];
        }
    }
};

int main() {
    int a = -123, b = 321;
    RandomizedSet s;
    cout << s.insert(a);
    cout << s.remove(b);
    cout << s.getRandom();
    return 0;
}
