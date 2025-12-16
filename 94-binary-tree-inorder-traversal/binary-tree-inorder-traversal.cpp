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
    /*Revursive traversal
    void solve(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    */
   
public:
    vector<int> inorderTraversal(TreeNode* root) {
        /*
        vector<int> ans;
        solve(root,ans);
        return ans;
        */

      //Iterative Solution
       /* 
       stack<TreeNode*> st;
       stack<bool> visited;
       vector<int> ans;
       if(root==NULL){
        return ans;
       }
       st.push(root);
       visited.push(0);
       while(!st.empty()){
        TreeNode* temp=st.top();
        st.pop();
        bool flag=visited.top();
        visited.pop();
        if(!flag){
            if(temp->right){
                st.push(temp->right);
                visited.push(0);
            }
            st.push(temp);
            visited.push(1);
            if(temp->left){
                st.push(temp->left);
                visited.push(0);
            }
        }
        else{
            ans.push_back(temp->val);
        }

       }
       return ans;
       */
       /*
       //Moris Traversal
       vector<int> ans;
       TreeNode* current=root;
       while(current!=NULL){
        if(current->left==NULL){
            ans.push_back(current->val);
            current=current->right;
        }
        else{
            TreeNode* pred=current->left;
            while(pred->right && pred->right!=current){
                pred=pred->right;

            }
            if(pred->right==NULL){
                pred->right=current;
                current=current->left;
            }
            else{
                pred->right=NULL;
                ans.push_back(current->val);
                current=current->right;
            }
        }
       }
       
       return ans;
       */
       //morris traversal
       vector<int>ans;
       TreeNode* curr=root;
       while(curr!=NULL){
       if(curr->left==NULL){
        ans.push_back(curr->val);
        curr=curr->right;
       }
       else{
        TreeNode* pred=curr->left;
        while(pred->right!=NULL && pred->right!=curr){
            pred=pred->right;
        }
        if(pred->right==NULL){
            pred->right=curr;
            curr=curr->left;
        }
        else{
            pred->right=NULL;
            ans.push_back(curr->val);
            curr=curr->right;
        }
       }
       }
       return ans;

       



        
        
    }
};