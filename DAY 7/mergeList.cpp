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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }

        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* newList = NULL;
        ListNode* newPtr = NULL;

        while(l1 || l2){
            if(l1 && l2){
                if(l1->val<=l2->val){
                    if(newList==NULL){
                        newList = l1;
                        newPtr = l1;
                        l1 = l1->next;
                        continue;
                    }
                    newPtr->next = l1;
                    newPtr = newPtr->next;
                    l1 = l1->next;
                }
                else{
                    if(newList==NULL){
                            newList = l2;
                            newPtr = l2;
                            l2 = l2->next;
                            continue;
                        }
                        newPtr->next = l2;
                        newPtr = newPtr->next;
                        l2 = l2->next;
                } 
            }
            else if(l1){
                newPtr->next = l1;
                l1 = l1->next;
                newPtr = newPtr->next;
            }
            else{
                newPtr->next = l2;
                l2 = l2->next;
                newPtr = newPtr->next;
            }
        }
        return newList;

    }
};