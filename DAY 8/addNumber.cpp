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
    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            fwd = curr->next;
            curr->next = prev;

            prev = curr;
            curr = fwd;
        }
        head = prev;
        return head;
    }
    ListNode* solve(ListNode* Num1, ListNode* Num2){
        Num1 = reverse(Num1);
        Num2 = reverse(Num2);

        ListNode* temp1 = Num1;
        ListNode* temp2 = Num2;
        int car = 0;
        int sm = 0;
        int digit=0;

        while(temp1!=NULL && temp2!=NULL){
            sm = temp1->val + temp2->val+car;
            digit = sm%10;
            car = sm/10;
            temp1->val = digit;
            if(temp1->next==NULL && car>0){
                ListNode* newNode = new ListNode(car);
                temp1->next = newNode;
                newNode->next = NULL;
                temp1=NULL;
                break;
            }
            temp1 =temp1->next;
            temp2 =temp2->next;
        }
        while(temp1!=NULL){
            sm = temp1->val+car;
            digit = sm%10;
            car = sm/10;
            temp1->val = digit;
            if(car>0 && temp1->next==NULL){
                ListNode* newNode = new ListNode(car);
                temp1->next = newNode;
                newNode->next = NULL;
                break;
            }
            temp1 = temp1->next;
        }
        Num1 = reverse(Num1);
        return Num1;
    }
public:
    ListNode* addTwoNumbers(ListNode* Num1, ListNode* Num2) {
        if(!Num1){
           return Num2;
        }
        if(!Num2){
            return Num1;
        }
        int len1 = 0;
        int len2 = 0;

        ListNode* temp1 = Num1;
        ListNode* temp2 = Num2;

        while(temp1!=NULL){
            len1++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            len2++;
            temp2 = temp2->next;
        }

        if(len1>=len2){
            return solve(Num1,Num2);
        }
        else{
            return solve(Num2, Num1);
        } 
    }
};