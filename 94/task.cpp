#include <vector>
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int>res;
        helper(res, root);
        return res;
    }
    void helper(std::vector<int>& res, TreeNode *root)
    {
        if(!root)
        {
            return;
        }
        helper(res, root ->left);
        res.push_back(root ->val);
        helper(res, root ->right);
    }
};