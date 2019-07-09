/**
 * 题目描述
 * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 * (注意: 在返回值的list中，数组长度大的数组靠前)
 */

#include <vector>;
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    vector<vector<int> > result;
    vector<int> tmp;

   public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        if (root) {
            DFS(root, expectNumber);
        }
        return result;
    }

    void DFS(TreeNode* root, int expectNumber) {
        tmp.push_back(root->val);
        if (root->val == expectNumber && !root->left && !root->right) {
            result.push_back(tmp);
        } else {
            if (root->left) {
                DFS(root->left, expectNumber - root->val);
            }
            if (root->right) {
                DFS(root->right, expectNumber - root->val);
            }
        }
        tmp.pop_back();
    }
};