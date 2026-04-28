// Leet Code Problem 101. Symmetric Tree | This program determines whether the predetermined trees mirrors themselves or not.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root || isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* l, TreeNode* r) {
        return !l && !r ? true : (l && r && l->val == r->val &&
            isMirror(l->left, r->right) && isMirror(l->right, r->left));
    }
};

int main() {
    Solution sol;


    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(4);
    t1->right->left = new TreeNode(4);
    t1->right->right = new TreeNode(3);

    cout << "Example 1 (Tree 1):\nInput: 1 2 2 3 4 4 3\nTree:\n        1\n       / \\\n      2   2\n     / \\ / \\\n    3  4 4  3\nDoes it mirror itself?: "
        << (sol.isSymmetric(t1) ? "true" : "false") << "\n\n";

    
    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(2);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(5);

    cout << "Example 2 (Tree 2):\nInput: 1 2 2 Null 4 Null 5\nTree:\n        1\n       / \\\n      2   2\n       \\   \\\n        4   5\nDoes it mirror itself?: "
        << (sol.isSymmetric(t2) ? "true" : "false") << endl;

    return 0;
}