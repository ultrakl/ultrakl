#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // vector<int> temp;
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size());
        return nums;
    }
    void quick_sort(vector<int>& nums, int start, int end) {
        if(start >= end - 1)return;
        // int pivot = nums[start + rand() % (end - start)];
        int pivot = nums[start];
        int i = start, j = start, k = end;
        while(i < k) {
            if(nums[i] < pivot) 
                swap(nums[i++], nums[j++]);
            if(nums[i] > pivot) 
                swap(nums[i], nums[--k]);
            else i++; 
        }
        quick_sort(nums, start, j);
        quick_sort(nums, k, end); 
    }
    /* void quick_sort(vector<int>& nums, int start, int end) {
        if(end <= start)return;
        int pos = rand() % (end - start + 1) + start;
        swap(nums[pos], nums[end]);
        int pivot = nums[end], left = start, right = end;//设立right=end防止基准元素左边的值全部小于基准然而最终还要交换
        while(left < right) {
            while(nums[left] <= pivot && left < right) left++;//<=保证最终相遇的元素一定大于基准
            while(nums[right] >= pivot && left < right) right--; //>=保证基准元素在最后交换之前不被挪动
            if(left < right)swap(nums[left], nums[right]);          
        }
        swap(nums[left], nums[end]);
        
        quick_sort(nums, start, left - 1);
        quick_sort(nums, left + 1, end);
    } */
    /* void merge_sort(vector<int>& nums, int start, int end) {
        if(end == start + 1)return;
        // vector<int> temp(end - start);
        int mid = start + ((end - start) >> 1);
        merge_sort(nums, start, mid);
        merge_sort(nums, mid, end);
        merge(nums, start, mid, mid, end, temp);
        // nums.assign()
        for(int i = start; i < end; i++) {
            nums[i] = temp[i];
        }
    }
    void merge(vector<int>& nums, int as, int ae, int bs, int be, vector<int>& temp) {
        int idx = as;
        while(as < ae && bs < be) {
            if(nums[as] < nums[bs]) {
                temp[idx++] = nums[as++];
            }
            else temp[idx++] = nums[bs++];
        }
        for(;as < ae; as++, idx++) temp[idx] = nums[as];
        for(;bs < be; bs++, idx++) temp[idx] = nums[bs];
    } */
};

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        //return isValidBST(root, nullptr, nullptr);
        /* stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;
        while(root != nullptr || !stack.empty()) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(root->val <= inorder) return false;
            inorder = root->val;
            root = root->right;
        }
        return true; */
        return morris(root);
    }
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(root == nullptr)return true;
        
        if(min && root->val <= min->val) return false;
        if(max && root->val >= max->val) return false;
        
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max); 
    }
    bool morris(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        TreeNode* infix = nullptr;
        while(cur != nullptr) {
            if(cur->left == nullptr){
                // cout<<cur->val<<endl;  
                if(infix != nullptr && infix->val >= cur->val){
                    return false; 
                }
                infix = cur;
                cur = cur->right;
            }
            else {
                prev = cur->left;
                while(prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }
                if(prev->right == nullptr) {
                    prev->right = cur;
                    cur = cur->left;
                }
                else {
                    prev->right = nullptr;
                    // cout<<cur->val<<endl;
                    if(infix != nullptr && infix->val >= cur->val) {
                        return false;
                    }
                    infix = cur;
                    cur = cur->right;
                }
            }
        }
        return true;
    }
};

int main() {
    vector vec{5, 2, 3, 1};
    Solution1 s;
    TreeNode* root = new TreeNode(5);
    TreeNode* rootl = new TreeNode(1);
    TreeNode* rootr = new TreeNode(4);
    TreeNode* rootrl = new TreeNode(3);
    TreeNode* rootrr = new TreeNode(6);
    root->left = rootl, root->right = rootr, rootr->left = rootrl, rootr->right = rootrr;
    // TreeNode* root = new TreeNode(5);
    // s.sortArray(vec);
    cout<<s.isValidBST(root);
    return 0;
}