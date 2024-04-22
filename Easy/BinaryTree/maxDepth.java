package Easy.BinaryTree;

public class maxDepth {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftTree = maxDepth(root.left);
        int rightTree = maxDepth(root.right);
        return Math.max(leftTree, rightTree) + 1;
    }
}
