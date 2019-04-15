#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int* duplication) {
    int d[length];
    for(int i=0; i<length; i++) {
        d[i] = 0;
    }
    for(int i=0; i<length; i++) {
        d[numbers[i]] ++;
        if(d[numbers[i]] > 1) {
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}

int main() {
    int duplication;
    int numbers[5] = {2,1,3,1,4};
    cout << (duplicate(numbers, 5, &duplication) ? "True" : "False") << endl << duplication << endl;
}