#include <iostream>

using namespace std;

bool isSymmetric(TreeNode *rootA, TreeNode *rootB) {
    if (rootA == NULL && rootB == NULL)
        return true;
    else if (rootA == NULL || rootB == NULL)
        return false;
    if (rootA->val != rootB->val)
        return false;
    return isSymmetric(rootA->left, rootB->right) && isSymmetric(rootA->right, rootB->left);
}

bool isSymmetric(TreeNode *root) {
    if (!root)
        return true;
    return isSymmetric(root->left, root->right);
}
