#include<iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* traverseList(TreeNode* root) {
        if(root == nullptr)return nullptr;
        auto nodel = traverseList(root->left);
        auto noder = traverseList(root->right);
        root->left == nullptr;
        if(nodel == nullptr)root->right = noder;
        else {
            root->right = nodel;
            auto tmp = nodel;
            while(tmp->right) {
                tmp = tmp->right;
            }
            tmp->right = noder;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        traverseList(root);
        return;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    TreeNode* lleft = new TreeNode(4);
    TreeNode* lright = new TreeNode(5);
    root->left = left;
    root->right = right;
    left->left = lleft;
    left->right = lright;
    Solution s;
    s.flatten(root);
}