#include <iostream>
#include <stack>
#include <string>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int elements[MAX_SIZE];
    int added_elements;

public:
    Stack() : added_elements(0) {}

    bool push(int value) {
        if (added_elements >= MAX_SIZE) {
            return false; // Stack overflow
        }
        elements[added_elements++] = value;
        return true;
    }

    bool pop() {
        if (added_elements <= 0) {
            return false; // Stack underflow
        }
        --added_elements;
        return true;
    }

    bool peek(int& value) {
        if (added_elements <= 0) {
            return false; // Stack is empty
        }
        value = elements[added_elements - 1];
        return true;
    }

    bool isEmpty() {
        return added_elements == 0;
    }

    bool isFull() {
        return added_elements == MAX_SIZE;
    }
    std::string reverse_subwords(const std::string& line) {
        std::stack<char> wordStack;
        std::string result;

        for (char c : line) {
            if (c != ' ') {
                // Push non-space characters onto the stack
                wordStack.push(c);
            }
            else {
                // Pop characters from the stack to build reversed subword
                while (!wordStack.empty()) {
                    result += wordStack.top();
                    wordStack.pop();
                }
                result += ' '; // Add space between subwords
            }
        }

        // Process the last subword
        while (!wordStack.empty()) {
            result += wordStack.top();
            wordStack.pop();
        }

        return result;
    }
    int reverse_num(int num) {
        std::stack<int> digitStack;

        // Push each digit of the number onto the stack
        while (num > 0) {
            int digit = num % 10;
            digitStack.push(digit);
            num /= 10;
        }

        int reversedNum = 0;
        int multiplier = 1;

        // Pop digits from the stack and build the reversed number
        while (!digitStack.empty()) {
            reversedNum += digitStack.top() * multiplier;
            digitStack.pop();
            multiplier *= 10;
        }

        return reversedNum;
    }
    class TwoStacks {
    private:
        static const int MAX_SIZE = 100;
        int elements[MAX_SIZE];
        int top1; // Top index of the first stack
        int top2; // Top index of the second stack

    public:
        TwoStacks() : top1(-1), top2(MAX_SIZE) {}

        void push(int stackId, int value) {
            if (top1 + 1 == top2) {
                throw std::overflow_error("Stack overflow");
            }

            if (stackId == 1) {
                elements[++top1] = value; // Push to stack 1
            }
            else if (stackId == 2) {
                elements[--top2] = value; // Push to stack 2
            }
            else {
                throw std::invalid_argument("Invalid stack ID");
            }
        }

    };

    int main() {

        return 0;
    }
};
