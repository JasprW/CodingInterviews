#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool IsContinuous(vector<int> numbers) {
        if (numbers.size() == 5) {
            int max = 0, min = 14;
            int d[14];
            for (int i = 0; i < 14; i++) {
                d[i] = 0;
            }
            for (int i = 0; i < 5; i++) {
                if (numbers[i] == 0) {
                    continue;
                } else {
                    d[numbers[i]]++;
                    if (d[numbers[i]] > 1) {
                        return false;
                    }
                    if (numbers[i] < min) {
                        min = numbers[i];
                    }
                    if (numbers[i] > max) {
                        max = numbers[i];
                    }
                }
            }
            if (max - min < 5) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

int main() {
    vector<int> v = {1, 3, 2, 5, 4};
    cout << IsContinuous(v);
}