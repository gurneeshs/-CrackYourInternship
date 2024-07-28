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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode;

        while(curr!=NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* middle = middleNode(head);

        ListNode* temp = head;
        while(temp->next!=middle){
            temp=temp->next;
        }
        temp->next = reverseList(middle);
        middle = temp->next;
        temp=head;
        ListNode* temp2 = middle;

        while(temp!=middle && temp2!=NULL){
            if(temp->val!=temp2->val){
                return false;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        return true;
    }
};