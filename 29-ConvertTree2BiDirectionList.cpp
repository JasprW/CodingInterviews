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
    TreeNode* Convert(TreeNode* root)
    {
        if(!root) return nullptr;
        if(!root -> left && !root -> right) {
            return root;
        }
        TreeNode* left = Convert(root -> left);
        TreeNode* p = left;
        while(p && p -> right) {
            p = p -> right;
        }
        if(p) {
            p -> right = root;
            root -> left = p;
        }
        TreeNode* right = Convert(root -> right);
        if(right) {
            right -> left = root;
            root -> right = right;
        }
        return left ? left : root;
    }
};