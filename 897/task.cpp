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
    TreeNode* increasingBST(TreeNode* root) 
    {
        std::vector<TreeNode*>res;
        helper(res, root);
        res.push_back(nullptr);
        for(int i = 0; i < res.size() - 1; ++i)
        {
            res[i] -> right = res[i + 1];
            res[i] -> left = nullptr;
        }
        return res[0];
    }

    void helper(std::vector<TreeNode*>& res, TreeNode *root)
    {
        if(!root)
        {
            return;
        }
        helper(res, root ->left);
        res.push_back(root);
        helper(res, root ->right);
    }
};