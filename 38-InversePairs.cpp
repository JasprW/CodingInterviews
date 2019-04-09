#include <vector>
using namespace std;
class Solution
{
  public:
    int num = 0;
    int InversePairs(vector<int> data)
    {
        if (data.size() != 0)
        {
            MergeSort(data, 0, data.size() - 1);
        }
        return num;
    }

    void MergeSort(vector<int> data, int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        else
        {
            int mid = (start + end) >> 1;
            MergeSort(data, start, mid);
            MergeSort(data, mid + 1, end);
            Merge(data, start, mid, end);
        }
    }

    void Merge(vector<int> data, int start, int mid, int end)
    {
        int *tmp = new int[end - start + 1];
        int i = start, j = mid + 1, k = 0;
        while (i <= mid && j <= end)
        {
            if (data[i] < data[j])
            {
                tmp[k++] = data[i++];
            }
            else
            {
                tmp[k++] = data[j++];
                num += mid - 1 + 1;
            }
        }
        while (i <= mid)
        {
            tmp[k++] = data[i++];
        }
        while (j <= end)
        {
            tmp[k++] = data[j++];
        }
        for (k = 0; k < (end - start + 1); k++)
        {
            data[start + k] = tmp[k];
        }
    }
};