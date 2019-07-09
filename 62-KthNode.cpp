class Solution {
   public:
    TreeNode KthNode(TreeNode root, int k) {
        if (root == null || k == 0) return null;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        int count = 0;
        TreeNode node = root;
        do {
            if (node != null) {
                stack.push(node);
                node = node.left;
            } else {
                node = stack.pop();
                count++;
                if (count == k) return node;
                node = node.right;
            }
        } while (node != null || !stack.isEmpty());
        return null;
    }
};