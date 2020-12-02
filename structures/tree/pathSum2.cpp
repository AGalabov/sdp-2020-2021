/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    // TODO: Pass by refference
    vector<vector<int>> result;
    void pathSumAcc(TreeNode* currNode, int sum, vector<int> currPath, int acc) {
        if(!currNode)
        {
            return;
        }
        if(currNode->left == nullptr && currNode->right == nullptr) {
            if(sum == acc + currNode->val) {
                currPath.push_back(currNode->val);
                result.push_back(currPath);
            }
            return;
        }
        
        currPath.push_back(currNode -> val);
        pathSumAcc(currNode->left, sum, currPath, acc+currNode->val);
        pathSumAcc(currNode->right, sum, currPath, acc+currNode->val);
        currPath.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        pathSumAcc(root, sum, path, 0); 
        return result;
    }
};