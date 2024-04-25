class Solution
{
public:
    int maximumPathSum = INT_MIN;
    int maxPathSum(TreeNode *root, int recursion_depth = 0)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int totalRight = max(0, maxPathSum(root->right, recursion_depth + 1));
        int totalLeft = max(0, maxPathSum(root->left, recursion_depth + 1));

        if (root->val >= maximumPathSum)
        {
            maximumPathSum = root->val;
            cout << "1 " << maximumPathSum << "\n";
        }

        if ((totalLeft + totalRight + root->val) >= maximumPathSum)
        {
            maximumPathSum = (totalLeft + totalRight + root->val);
            cout << "2 " << maximumPathSum << "\n";
        }
        else if ((totalLeft + root->val) >= maximumPathSum)
        {
            maximumPathSum = (totalLeft + root->val);
            cout << "3 " << maximumPathSum << "\n";
        }
        else if ((totalRight + root->val) >= maximumPathSum)
        {
            maximumPathSum = (totalRight + root->val);
            cout << "4 " << maximumPathSum << "\n";
        }

        if (recursion_depth != 0)
        {
            return root->val + max(totalLeft, totalRight);
        }

        return maximumPathSum;
    }
};