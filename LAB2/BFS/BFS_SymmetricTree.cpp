class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*, TreeNode*)> checkSymmetry = [&](TreeNode* leftSubtree, TreeNode* rightSubtree) -> bool {
            if (!leftSubtree && !rightSubtree) return true;
          
            if (!leftSubtree || !rightSubtree || leftSubtree->val != rightSubtree->val) return false;

            return checkSymmetry(leftSubtree->left, rightSubtree->right) && 
                   checkSymmetry(leftSubtree->right, rightSubtree->left);
        };
      
        return checkSymmetry(root, root);
    }
};