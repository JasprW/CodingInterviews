#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    : val(x), left(NULL), right(NULL)
    {
    }

    //
    static void PreOrder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        cout <<root->val;
        PreOrder(root->left);
        PreOrder(root->right);
    }

    static void InOrder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        InOrder(root->left);
        cout <<root->val;
        InOrder(root->right);
    }

 };

class Solution
{
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        /**
         * 思路：使用递归法，先提取根节点，然后寻找左右子树
         * 将左右子树的前序、中序分别提出，然后对子树递归算法
         * 终止条件：子树遍历长度为0
         **/
        
        if(pre.size() != vin.size()) {
            return NULL;    //前中序长度不等，返回NULL
        } 
        else{
            int length = pre.size();
            // Reminder: 长度为0时结束
            if (length == 0) {
                return NULL;
            }
            TreeNode* root = new TreeNode(pre[0]);
            int index;
            for(index = 0; index < length; index++) {
                if(vin[index] != pre[0]) break;
            }
            if(vin[index] != pre[0]) {
                return NULL;        //中序找不到根节点，返回NULL
            }
            int left = index;
            int right = length - 1 - index;
            vector<int> preLeft(left), preRight(right), vinLeft(left), vinRight(right);
            for(int i =0; i < length; i++) {
                if (i < index) {
                    preLeft[i] = pre[i+1];
                    vinLeft[i] = vin[i];
                }
                else if(i > index) {
                    preRight[i - index - 1] = pre[i];
                    vinRight[i - index - 1] = vin[i];
                }
            }
            root -> left = reConstructBinaryTree(preLeft, vinLeft);
            root -> right = reConstructBinaryTree(preRight, vinRight);
            return root;
        }
    }
}