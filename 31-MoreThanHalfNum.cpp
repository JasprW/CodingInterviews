#include <map>;
#include <vector>;
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(!len) return 0;
        map<int, int> num;
        for (int i = 0; i < len; i++) {
            map<int, int>::iterator itr = num.find(numbers[i]);
            if(itr != num.end()) {
                itr -> second ++;
            } else {
                num.insert(std::pair<int, int>(numbers[i], 1));
            }
        }
        map<int, int>::iterator itr = num.begin();
        while(itr != num.end()) {
            if(itr -> second > (len / 2)) {
                return itr -> first;
            }
            itr++;
        }
        return 0;
    }
};