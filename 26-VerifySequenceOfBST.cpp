/**
 * 题目描述
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */

#include <vector>;
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> s) {
        int len = s.size();
        if (len == 0)
            return false;
        if (len < 2) 
            return true;
        int rootVal = s[len-1];
        int i = 0;
        while (i < len && s[i] < rootVal) {
                i++;
        }
        for(int j = i; j < len; j++) {
            if (s[j] < rootVal) {
                return false;
            }
        }
        vector<int> left, right;
        for (int k = 0; k < i; k++) {
            left.push_back(s[k]);
        }
        for (int k = i; k < len - 1; k++) {
            right.push_back(s[k]);
        }
        if (left.size()&& right.size()){
            return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
        } else if (left.size()) {
            return VerifySquenceOfBST(left);
        } else if (right.size()){
            return VerifySquenceOfBST(right);
        }
        return false;
    }
};