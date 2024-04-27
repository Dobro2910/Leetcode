class Solution
{
public:
    std::vector<double> returnVector;
    std::vector<int> count;

    std::vector<double> averageOfLevels(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        // Initialize vectors to store sum and count of nodes at each level
        returnVector.clear();
        count.clear();

        // Call helper function to calculate sum and count of nodes at each level
        calculateSumAndCount(root, 0);

        // Calculate average of nodes at each level
        std::vector<double> averages;
        for (int i = 0; i < returnVector.size(); ++i)
        {
            averages.push_back(returnVector[i] / count[i]);
        }

        return averages;
    }

    // Helper function to calculate sum and count of nodes at each level
    void calculateSumAndCount(TreeNode *root, int level)
    {
        if (root == nullptr)
        {
            return;
        }

        // If this is the first node encountered at the current level
        if (level == returnVector.size())
        {
            returnVector.push_back(0);
            count.push_back(0);
        }

        // Update sum and count for the current level
        returnVector[level] += root->val;
        count[level]++;

        // Recursively calculate sum and count for left and right subtrees
        calculateSumAndCount(root->left, level + 1);
        calculateSumAndCount(root->right, level + 1);
    }
};