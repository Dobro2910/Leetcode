class Solution
{
public:
    std::vector<int> sortedVector;
    int kthSmallest(TreeNode *root, int k, int level = 0)
    {
        if (root == nullptr)
        {
            return -1;
        }

        int left;
        int right;
        left = kthSmallest(root->left, k, level + 1);
        sortedVector.push_back(root->val);
        right = kthSmallest(root->right, k, level + 1);

        if (level != 0)
        {
            return root->val;
        }

        return sortedVector[k - 1];
    }
};