class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        // Flatten the left subtree
        flatten(root->left);

        // Flatten the right subtree
        flatten(root->right);

        // Store the right subtree
        TreeNode *temp = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = nullptr;

        // Find the rightmost node and attach the stored right subtree
        TreeNode *current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        current->right = temp;
    }
};