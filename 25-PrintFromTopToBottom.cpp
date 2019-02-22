/**
 * 题目描述
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 */

#include <vector>;
#include <queue>;
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if (!root)  {
            return result;
        } else {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                if(q.front() -> left) {
                    q.push(q.front() -> left);
                }
                if(q.front() -> right) {
                    q.push(q.front() -> right);
                }
                result.push_back(q.front() -> val);
                q.pop();
            }
            return result;
        }
    }
};