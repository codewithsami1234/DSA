#include <stack>

class MyQueue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

    void shiftStacks() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {
        // Constructor
    }
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        shiftStacks();
        int val = outputStack.top();
        outputStack.pop();
        return val;
    }
    
    int peek() {
        shiftStacks();
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty(); // use () here
    }
};
