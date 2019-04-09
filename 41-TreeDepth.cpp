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
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) {
            return 0;
        } else {
            int left = TreeDepth(pRoot->left);
            int right = TreeDepth(pRoot->right);
            return left > right ? 1+left : 1+right;
        }
    }
};