class Solution
{
public:
    std::vector<vector<int>> resultVector;
    vector<vector<int>> levelOrder(TreeNode *root, int level = 0)
    {
        if (root == nullptr)
        {
            return resultVector;
        }

        // If this is the first node encountered at the current level
        if (level == resultVector.size())
        {
            resultVector.push_back({});
        }

        resultVector[level].push_back(root->val);

        levelOrder(root->left, ++level);
        levelOrder(root->right, level);

        return resultVector;
    }
};