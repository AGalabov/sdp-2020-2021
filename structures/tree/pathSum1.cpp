#include <iostream>
 
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    bool hasPathSumAcc(TreeNode* currNode, int sum, int acc) {
        if(!currNode)
        {
            return false;
        }
        if(currNode->left == nullptr && currNode->right == nullptr) {
            return sum == acc + currNode->val;
        }

        if(hasPathSumAcc(currNode->left, sum, acc+currNode->val)) {
            return true;
        }
        return hasPathSumAcc(currNode->right, sum, acc+currNode->val);
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSumAcc(root, sum, 0);
    }
};
