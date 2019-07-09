/**
 * 题目描述
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */

#include <vector>;
using namespace std;

class Solution {
   public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        res.clear();
        int row = matrix.size();        //行数
        int collor = matrix[0].size();  //列数
        //计算打印的圈数
        int circle = ((row < collor ? row : collor) - 1) / 2 + 1;  //圈数
        for (int i = 0; i < circle; i++) {
            //从左向右打印
            for (int j = i; j < collor - i; j++) res.push_back(matrix[i][j]);
            //从上往下的每一列数据
            for (int k = i + 1; k < row - i; k++)
                res.push_back(matrix[k][collor - 1 - i]);
            //判断是否会重复打印(从右向左的每行数据)
            for (int m = collor - i - 2; (m >= i) && (row - i - 1 != i); m--)
                res.push_back(matrix[row - i - 1][m]);
            //判断是否会重复打印(从下往上的每一列数据)
            for (int n = row - i - 2; (n > i) && (collor - i - 1 != i); n--)
                res.push_back(matrix[n][i]);
        }
        return res;
    }
};