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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if(!root)
        {
            return 0;
        }
        int val = rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
        return (root->val >= low && root ->val <= high) ? val + root ->val : val; 
    }
};