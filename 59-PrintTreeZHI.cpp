#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        int layer = 1;
        stack<TreeNode*> s1, s2;
        if (pRoot == nullptr) {
            vector<vector<int>> v;
            return v;
        } else {
            s1.push(pRoot);
            vector<vector<int>> v;
            while (!s1.empty() || !s2.empty()) {
                if (layer % 2) {
                    vector<int> tmp;
                    while (!s1.empty()) {
                        TreeNode* node = s1.top();
                        tmp.push_back(node->val);
                        if (node->left != nullptr) {
                            s2.push(node->left);
                        }
                        if (node->right != nullptr) {
                            s2.push(node->right);
                        }
                        s1.pop();
                    }
                    v.push_back(tmp);
                    layer++;
                } else {
                    vector<int> tmp;
                    while (!s2.empty()) {
                        TreeNode* node = s2.top();
                        tmp.push_back(node->val);
                        if (node->right != nullptr) {
                            s1.push(node->right);
                        }
                        if (node->left != nullptr) {
                            s1.push(node->left);
                        }
                        s2.pop();
                    }
                    v.push_back(tmp);
                    layer++;
                }
            }
            return v;
        }
    }
};