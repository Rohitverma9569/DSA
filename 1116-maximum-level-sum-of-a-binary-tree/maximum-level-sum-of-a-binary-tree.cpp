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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>vec;
        if(root==NULL){
            return 0;
        }
        q.push(root);
        q.push(NULL);
        vec.push_back(0);
        int i=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                    vec.push_back(0);
                    i++;
                }

            }else{
                vec[i]+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        int ans=0;
        int maxElement=INT_MIN;
        for(int i=0;i<vec.size();i++){
            if(vec[i]>maxElement){
                ans=i+1;
                maxElement=vec[i];
            }
        } 
        return ans;   
        
    }
};