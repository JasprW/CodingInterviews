#include <vector>
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        for (int i=0; i<size; i++) {
            if (!(array[i] % 2)) {
                for(int j=i+1; j<size; j++) {
                    if (array[j] % 2) {
                        int temp = array[j];
                        for (int t=j-1; t>=i; t--) {
                            array[t+1] = array[t];
                        }
                        array[i] = temp;
                        i++;
                    }
                }
            }
        }
    }
};