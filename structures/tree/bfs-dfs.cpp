#include <iostream>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
    ~TreeNode();
};

TreeNode::~TreeNode()
{
    std::cout << "Deleting for: " << this->val;
    delete this->left;
    delete this->right;
}

void DFS(TreeNode* t)
{
    std::stack<TreeNode*> stack;
    stack.push(t);

    while(!stack.empty())
    {
        TreeNode* curr = stack.top();
        stack.pop();

        std::cout << curr->val << " -> ";

        if(!curr->left && !curr->right)
        {
            continue;
        }

        stack.push(curr->right);
        stack.push(curr->left);
    }
}


void BFS(TreeNode* t)
{
    std::queue<TreeNode*> stack;
    stack.push(t);

    while(!stack.empty())
    {
        TreeNode* curr = stack.front();
        stack.pop();

        std::cout << curr->val << " -> ";

        if(!curr->left && !curr->right)
        {
            continue;
        }

        stack.push(curr->left);
        stack.push(curr->right);
    }
}

int main()
{
    TreeNode* t = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3, t, t2);
    TreeNode* t41 = new TreeNode(41);
    TreeNode* t42 = new TreeNode(42);
    TreeNode* t4 = new TreeNode(4, t41, t42);
    TreeNode* t5 = new TreeNode(5, t3, t4);

    std::cout << "\n ==== DFS: ";
    DFS(t5);

    std::cout << "\n ==== BFS: ";
    BFS(t5);

    delete t5;

    return 0;
}