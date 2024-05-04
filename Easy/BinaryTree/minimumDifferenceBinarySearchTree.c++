class Solution
{
public:
    int minDiff = INT_MAX; // Initialize minDiff to maximum possible value

    int getMinimumDifference(TreeNode *root)
    {
        if (root == nullptr)
        {
            return -1;
        }

        // Traverse left subtree
        if (root->left != nullptr)
        {
            minDiff = std::min(minDiff, root->val - getMaxValue(root->left));
            getMinimumDifference(root->left);
        }

        // Traverse right subtree
        if (root->right != nullptr)
        {
            minDiff = std::min(minDiff, getMinValue(root->right) - root->val);
            getMinimumDifference(root->right);
        }

        return minDiff;
    }

    // Helper function to get the maximum value in a BST
    int getMaxValue(TreeNode *node)
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node->val;
    }

    // Helper function to get the minimum value in a BST
    int getMinValue(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node->val;
    }
};