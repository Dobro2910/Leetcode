/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) 
            return nullptr;  // base case: if there are no elements left, return null (no subtree)

        // the first element in preorder is always the root node
        int rootVal = preorder[0];

        // find where the root node appears in the inorder array
        // everything to the left of this index belongs to the left subtree
        // everything to the right belongs to the right subtree
        int mid = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();

        // split the inorder array into left and right parts based on root index
        vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);
        vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());

        // since preorder = [root][left subtree][right subtree]
        // we know how many nodes belong to the left subtree (leftInorder.size())
        // so we use that to slice preorder accordingly
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());

        // recursively build left and right subtrees
        TreeNode* left = buildTree(leftPreorder, leftInorder);
        TreeNode* right = buildTree(rightPreorder, rightInorder);

        // create the current root node and attach its left and right subtrees
        return new TreeNode(rootVal, left, right);
    }
};