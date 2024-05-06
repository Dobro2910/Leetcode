#include <vector>

class Solution
{
public:
    void inOrderTreeTraversal(TreeNode *root, int k, vector<int> &sortedVector)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrderTreeTraversal(root->left, k, sortedVector);
        sortedVector.push_back(root->val);
        inOrderTreeTraversal(root->right, k, sortedVector);

        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        std::vector<int> sortedVector;

        inOrderTreeTraversal(root, k, sortedVector);

        return sortedVector[k - 1];
    }
};