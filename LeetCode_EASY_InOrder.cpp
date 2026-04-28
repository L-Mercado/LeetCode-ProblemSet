// leet Code Problem 94. Binary Tree Inorder Traversal | This program traverses a predetermined binary tree "inorder" and then prints the resulting order of the elements. 
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* current = root;
        
        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }
            
           
            current = stack.top();
            stack.pop();
            result.push_back(current->val);
            
            current = current->right;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
  
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    
    cout << "Tree:\n    4\n   / \\\n  2   6\n / \\ / \\\n1  3 5 7\n" << endl;
    
    vector<int> result = sol.inorderTraversal(root);
    
    cout << "Inorder Count: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
}
