#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    void transfer(stack<int> &s1, stack<int> &s2){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    stack<int> input_stack; 
    stack<int> output_stack;
    MyQueue() {
        
    }
    
    void push(int x) {
        input_stack.push(x);
    }
    
    int pop() {
        if(output_stack.empty()){
            if(input_stack.empty()){
                return -1;
            }   
            transfer(input_stack,output_stack);
        }
        int front = output_stack.top();
        output_stack.pop();
        transfer(output_stack,input_stack);
        return front;
    }
    
    int peek() {
        if(output_stack.empty()){
            if(input_stack.empty()){
                return -1;
            }   
            transfer(input_stack,output_stack);
        }
        int front = output_stack.top();
        transfer(output_stack,input_stack);
        return front;
    }
    
    bool empty() {
        if(input_stack.empty() && output_stack.empty()){
            return true;
        }
        return false;
    }
};
