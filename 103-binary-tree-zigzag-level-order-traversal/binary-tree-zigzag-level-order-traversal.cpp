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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>vec;
        if(root==NULL) return vec;
        queue<TreeNode*>q;
        vec.push_back(vector<int>());
        q.push(root);
        q.push(NULL);
        int i=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                if(i%2==1){
                    reverse(vec[i].begin(),vec[i].end());
                }
               
                
                if(!q.empty()){
                   
                    
                    q.push(NULL);
                    vec.push_back(vector<int>());
                    i++;
                }

            }
            else{
                vec[i].push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return vec;
 
    }
};