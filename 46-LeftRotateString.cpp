#include <string>
#include <iostream>
using namespace std;

string LeftRotateString(string str, int n) {
    if(str.size() <= 1) {
        return str;
    }
    string result = str;
    for (int i=0; i<n; i++) {
        char tmp = result[0];
        result = result.substr(1);
        result.push_back(tmp);
    }
    return result;
}

int main() {
    LeftRotateString("abcdefg", 2);
}