#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        // int i = 0, cnt = 0;
        // while(i< data.size() && data[i] != k) {
        //     i++;
        // }
        // while(i< data.size() && data[i] == k) {
        //     cnt ++;
        //     i++;
        // }
        // return cnt;

        int len = data.size();
        if(len == 0) {
            return 0;
        }
        int first = FindFirstK(data, 0, len-1, k);
        int last = FindLastK(data, 0, len-1, k);
        if(first!=-1 && last != -1) {
            return last-first+1;
        } else {
            return 0;
        }
    }

    int FindFirstK(vector<int> data, int start, int end, int k) {
        if(start > end) {
            return -1;
        } 
        int mid = (start + end) >> 1 ;
        if(data[mid] < k) {
            return FindFirstK(data, mid+1, end, k);
        } else if(data[mid] > k) {
            return FindFirstK(data, start, mid-1, k);
        } else if (mid >= 1 && data[mid-1] == k) {
            return FindFirstK(data, start, mid-1, k);
        } else {
            return mid;
        }
    }

    int FindLastK(vector<int> data, int start, int end, int k) {
        if(start > end) {
            return -1;
        } 
        int mid = (start + end) >> 1 ;
        if(data[mid] < k) {
            return FindLastK(data, mid+1, end, k);
        } else if(data[mid] > k) {
            return FindLastK(data, start, mid-1, k);
        } else if (mid+1 < data.size() && data[mid+1] == k) {
            return FindLastK(data, mid+1, end, k);
        } else {
            return mid;
        }
    }
};