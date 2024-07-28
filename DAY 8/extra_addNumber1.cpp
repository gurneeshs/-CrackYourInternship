#include <bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* cur = NULL;
        int car = 0;
        int sm = 0;
        int digit = 0;

        while(temp1 || temp2 || car){
            if(!temp1 && !temp2 && car){
                ListNode* newNode = new ListNode(car);
                cur->next = newNode;
                cur = cur->next;
                break;
            }
            if(temp1 && !temp2){
                sm = temp1->val + car;
                digit = sm%10;
                car = sm/10;
                temp1->val = digit;
                cur =temp1;
                temp1 = temp1->next;
                continue;
            }
            if(!temp1 && temp2){
                sm = temp2->val + car;
                digit = sm%10;
                car = sm/10;
                temp2->val = digit;
                cur->next = temp2;
                cur = cur->next;
                temp2 = temp2->next;
                continue;
            }

            sm = temp1->val + temp2->val + car;
            digit = sm%10;
            car = sm/10;
            temp1->val = digit;
            cur =temp1;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return l1;
    }
};