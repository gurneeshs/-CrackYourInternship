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
    int getDecimalValue(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head->val;
        }
        ListNode* temp = head;
        int ans=0;
        int bit = 0;
        while(temp!=NULL){
            ans = ans<<1;
            bit = temp->val;
            temp = temp->next;
            ans = ans|bit;
        }
        return ans;

    }
};