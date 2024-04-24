class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool leftTree = true;
        bool rightTree = true;

        if (p != nullptr && q != nullptr)
        {
            leftTree = isSameTree(p->left, q->left);
            rightTree = isSameTree(p->right, q->right);
        }
        else if (p != nullptr || q != nullptr)
        {
            return false;
        }
        else if (p == nullptr & q == nullptr)
        {
            return true;
        }

        if (p->val == q->val && leftTree == true && rightTree == true)
        {
            return true;
        }

        return false;
    }
};