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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return Depth(pRoot) != -1;
    }

    int Depth(TreeNode* pRoot) {
        if(!pRoot) {
            return 0;
        }
        if(Depth(pRoot->left) == -1 || Depth(pRoot->right) == -1) {
            return -1;
        } else {
            int left = Depth(pRoot->left);
            int right = Depth(pRoot->right);
            if(left - right > 1 || right - left > 1) {
                return -1;
            } else {
                return left > right ? 1+left : 1+right;
            }
        }
    }
};