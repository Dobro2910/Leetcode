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
    void bfs(TreeNode* root, int treeLevel, vector<vector<int>>& returnArray) {
        if (root == nullptr) {
            return;
        }

        cout << "node val: " << root->val << " at level: " << treeLevel << "\n";

        if (returnArray.size() <= treeLevel) {
            returnArray.push_back({});
        }
        
        if (treeLevel % 2 == 0) {
            returnArray[treeLevel].push_back(root->val);
        } else if (treeLevel % 2 == 1) {
            returnArray[treeLevel].insert(returnArray[treeLevel].begin(), root->val);
        }

        ++treeLevel;

        bfs(root->left, treeLevel, returnArray);
        bfs(root->right, treeLevel, returnArray);

        return;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> returnArray;
        int treeLevel = 0;

        bfs(root, treeLevel, returnArray);

        return returnArray;
    }
};