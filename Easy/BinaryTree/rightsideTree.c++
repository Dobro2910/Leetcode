class Solution
{
public:
    std::vector<int> finalResultVector;
    vector<int> rightSideView(TreeNode *root, int count = 0)
    {
        if (root == nullptr)
        {
            return {};
        }

        if (count >= finalResultVector.size())
        {
            finalResultVector.push_back(root->val);
        }

        // Recursive call for right subtree
        rightSideView(root->right, count + 1);

        // Recursive call for left subtree
        rightSideView(root->left, count + 1);

        return finalResultVector;
    }
};