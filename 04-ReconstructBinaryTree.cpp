class Solution {
   public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() != vin.size())
            return NULL;
        else {
            int length = pre.size();
            if (length == 0) return NULL;
            TreeNode *root = new TreeNode(pre[0]);
            int rootIndex;
            for (rootIndex = 0; rootIndex < length; rootIndex++) {
                if (vin[rootIndex] == pre[0]) break;
            }
            if (vin[rootIndex] != pre[0]) {
                return NULL;
            }
            int left = rootIndex;
            int right = length - 1 - rootIndex;
            vector<int> preLeft(left), preRight(right), vinLeft(left),
                vinRight(right);
            for (int i = 0; i < length; i++) {
                if (i < rootIndex) {
                    preLeft[i] = pre[i + 1];
                    vinLeft[i] = vin[i];
                } else if (i > rootIndex) {
                    preRight[i - rootIndex - 1] = pre[i];
                    vinRight[i - rootIndex - 1] = vin[i];
                }
            }
            root->left = reConstructBinaryTree(preLeft, vinLeft);
            root->right = reConstructBinaryTree(preRight, vinRight);
            return root;
        }
    }
};