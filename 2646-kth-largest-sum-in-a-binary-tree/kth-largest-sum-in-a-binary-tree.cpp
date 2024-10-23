/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> Q;
        Q.push(root);
        while(Q.size()){
            long long t=Q.size();
            long long sum=0;
            while(t){
                TreeNode* node=Q.front();
                Q.pop();
                sum+=node->val;
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
                t--;
            }
            pq.push(-sum);
            if(pq.size()>k) pq.pop();
        }
        if(pq.size()<k) return -1;
        return abs(pq.top());

        
    }
};