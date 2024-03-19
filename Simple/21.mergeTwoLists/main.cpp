//
//  main.cpp
//  21.mergeTwoLists
//
//  Created by 李雪峰 on 2024/3/16.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode node;
        ListNode *L = &node;
        ListNode *flag, *k, *temp;
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }
        if(list1->val > list2->val) {
            flag = list1;
            k = list2;
            L = list2;
        }else {
            flag = list2;
            k = list1;
            L = list1;
        }
        while(k->next != nullptr) {
            if(k->next->val <= flag->val) {
                k = k->next;
            }else {
                temp = k->next;
                k->next = flag;
                flag = temp;
            }
        }
        k->next = flag;
        return L;
    }
};
int main() {
    vector<int> i1 = {2,5,6,9,11,17};
    vector<int> i2 = {1,3,6,8,10,19,20,44};
    ListNode Node1 = ListNode();
    ListNode Node2 = ListNode();
    ListNode *L1 = &Node1;
    ListNode *L2 = &Node2;
    ListNode *temp = L1;
    for(int i = 0; i < i1.size(); i++) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->val = i1[i];
        temp = temp->next;
    }
    temp = L2;
    for(int i = 0; i < i2.size(); i++) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->val = i2[i];
        temp = temp->next;
    }
    Solution s;
    temp = s.mergeTwoLists(L1, L2);
    while(temp != nullptr) {
        cout << temp->val << ' ';
        temp = temp->next;
    }
    return 0;
}
