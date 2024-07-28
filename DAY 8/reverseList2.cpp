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
    void solve(ListNode* &head, ListNode* leftPrev, ListNode* left, ListNode* right){
        
        ListNode* rightNext = right->next;
        
        ListNode* prev = NULL;
        ListNode* fwd;
        ListNode* curr = left;
        // cout<<curr->val;

        while(curr!=rightNext){
            fwd = curr->next;
            curr->next = prev;

            prev = curr;
            curr = fwd;
        }
        left->next = rightNext;
        cout<<prev->val;
        if(leftPrev){
            leftPrev->next = prev;
            return;
        }
        head = prev;
        cout<<head->val;
        // return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(head==NULL){
        return head;
       } 

       ListNode* temp = head;
       ListNode* leftPtr = NULL;
       ListNode* rightPtr = NULL;
       ListNode* leftPrev = NULL;

        int i = 1;
        while (i < left) {
            temp = temp->next;
            i++;
        }
        leftPtr = temp;
        while (i < right) {
            temp = temp->next;
            i++;
        }
        rightPtr = temp;
       temp = head;
       

       if(leftPtr==rightPtr || (!leftPtr && !rightPtr)){
        return head;
       }
       while(temp!=leftPtr){
         if(temp->next==leftPtr){
            leftPrev = temp;
            break;
         }
         temp = temp->next;
       }
       cout<<leftPtr->val<<" "<<rightPtr->val;
        solve(head,leftPrev,leftPtr,rightPtr);
        cout<<head->val;
       return head;
    }
};