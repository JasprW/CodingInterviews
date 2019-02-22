/**
 * 题目描述
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot) {
            return;
        }
        // 递归调换左右子树指针
        TreeNode* left = pRoot -> left, * right = pRoot -> right;
        pRoot -> left = right;
        pRoot -> right = left;
        Mirror(pRoot -> left);
        Mirror(pRoot -> right);
    }
};