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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> Nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            TreeNode* frontElement=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            Nodes[hd][lvl].push_back(frontElement->val);

            if(frontElement->left){
                q.push(make_pair(frontElement->left,make_pair(hd-1,lvl+1)));
            }
            if(frontElement->right){
                q.push(make_pair(frontElement->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i:Nodes){
            vector<int> temp ;
            for(auto j:i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k:j.second){
                    temp.push_back(k);
                }                
            }
           
            ans.push_back(temp);
        }
        return ans;       
    }
};