#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        int size = array.size(), low = 0, high = size - 1;
        vector<int> tmp;
        if (size < 2) {
            return tmp;
        }
        while (high < size && high > low)
        {
            if (array[low] + array[high] == sum)
            {
                
                tmp.push_back(array[low]);
                tmp.push_back(array[high]);
                return tmp;
            }
            else if (array[low] + array[high] > sum)
            {
                high--;
            }
            else if (array[low] + array[high] < sum)
            {
                low++;
            }
        }
        return tmp;
    }
};