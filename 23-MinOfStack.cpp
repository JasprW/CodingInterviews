#include <stack>;
using namespace std;

class Solution {
public:
    void push(int value) {
        if (realS.empty()) {
            realS.push(value);
            minS.push(value);
        } else {
            if (value <= minS.top()) {
                realS.push(value);
                minS.push(value);
            } else {
                realS.push(value);
            }
        } 
    }
    void pop() {
        if(minS.top() == realS.top()) {
            minS.pop();
            realS.pop();
        } else {
            realS.pop();
        }
    }
    int top() {
        return realS.top();
    }
    int min() {
        return minS.top();
    }
private:
    stack<int> minS;
    stack<int> realS;
};