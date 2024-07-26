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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL && headB==NULL){
            return NULL;
        }

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while(ptr1!=ptr2){
            if(ptr1==NULL){
                ptr1 = headB;
            }
            else{
                ptr1 = ptr1->next;
            }
            if(ptr2==NULL){
                ptr2 = headA;
            }
            else{
                ptr2 = ptr2->next;
            }
        }
        return ptr2;
    }
};