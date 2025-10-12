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

//  O(n^2)
class Solution {
public:
    map<int, int> postOrderElementToInOrderIndexMap;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }

        int inOrderIndex = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (postorder[postorder.size() - 1] == inorder[i]) {
                inOrderIndex = i;
            }
        }

        // create new left and right inOrder array
        vector<int> leftInorder(inorder.begin(), inorder.begin() + inOrderIndex);
        vector<int> rightInorder(inorder.begin() + inOrderIndex + 1, inorder.end());

        // create new left and right postOrderArray
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end() - 1);

        TreeNode* leftTree = buildTree(leftInorder, leftPostorder);
        TreeNode* rightTree = buildTree(rightInorder, rightPostorder);
        TreeNode* head = new TreeNode(inorder[inOrderIndex], leftTree, rightTree);

        return head;
    }
};

//  O(n)
class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i; // map value -> index
        }

        postIndex = postorder.size() - 1;
        return helper(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd || postIndex < 0) {
            return nullptr;
        }

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderIndex[rootVal];

        // build right subtree first because postorder is Left -> Right -> Root
        root->right = helper(inorder, postorder, inIndex + 1, inEnd);
        root->left = helper(inorder, postorder, inStart, inIndex - 1);

        return root;
    }
};
