#include <stack>;
using namespace std;

class Solution
{
public:
    void push(int node) {
        /**
         * stack1作为中转， stack2作为存储
         * 存入时先将stack2中所有元素弹出并依次push进stack1
         * 将node push进stack2
         * 将stack1中所有元素依次pop出并push进stack2
         */
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack2.push(node);
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    int pop() {
        /**
         * stack2为存储，因此pop时仅需将stack2中依次pop即可
         */
        if (stack2.empty()) {
            return NULL;
        }
        else {
            int out = stack2.top();
            stack2.pop();
            return out;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};