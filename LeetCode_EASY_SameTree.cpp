// leet Code Problem 100. Same Tree | This program shows the results of a comparison between 2 predetermined trees, determining if they are the same or not. The first example shows a match, while the second doesn't
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution sol;

   
    TreeNode* p1 = new TreeNode(7);
    p1->left = new TreeNode(6);
    p1->right = new TreeNode(8);

    TreeNode* q1 = new TreeNode(7);
    q1->left = new TreeNode(6);
    q1->right = new TreeNode(8);
    
    cout << "Example 1 (Same): " << endl;
    cout << "Tree 1:   7" << endl;
    cout << "         / \\" << endl;
    cout << "        6   8" << endl;
    cout << "\nTree 2:   7" << endl;
    cout << "         / \\" << endl;
    cout << "        6   8" << endl;
    cout << "\nDo They Match?: " << (sol.isSameTree(p1, q1) ? "true" : "false") << endl;
    cout << "" << endl;

   
    TreeNode* p2 = new TreeNode(4);
    p2->left = new TreeNode(1);
    p2->right = new TreeNode(5);

    TreeNode* q2 = new TreeNode(4);
    q2->left = new TreeNode(1);
    q2->right = new TreeNode(6);

    cout << "Example 2 (Different): " << endl;
    cout << "\nTree 1:   4" << endl;
    cout << "         / \\" << endl;
    cout << "        1   5" << endl;
    cout << "\nTree 2:   4" << endl;
    cout << "         / \\" << endl;
    cout << "        1   6" << endl;
    cout << "\nDo They Match?: " << (sol.isSameTree(p2, q2) ? "true" : "false") << endl;


    return 0;
}