#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }

        map<Node*, Node*> m;
        Node* head2 = new Node(head->val);
        m[head] = head2;
        Node* temp2 = head2;
        Node* temp = head->next;

        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            temp2->next = newNode;
            temp2 = temp2->next;
            m[temp] = temp2;
            temp = temp->next;
        }

        temp = head;
        temp2 = head2;
        while(temp!=NULL){
            temp2->random = m[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return head2;
    }

};