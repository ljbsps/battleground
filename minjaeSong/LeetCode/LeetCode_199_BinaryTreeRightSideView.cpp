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

vector<vector<int>> ans;
queue<TreeNode*> q;

void find(TreeNode* root){
    vector<int> row;
    while(!q.empty()){
        row.clear();
        int qSize = q.size();
        for(int i=0;i<qSize;i++){
            TreeNode* now = q.front();
            q.pop();
            if(now->left!=NULL){
                q.push(now->left);
            }
            if(now->right!=NULL){
                q.push(now->right);
            }
            row.push_back(now->val);
        }
        ans.push_back(row);
    }
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if(nullptr==root) return answer;
        ans.clear();
        q.push(root);
        find(root);
        for(int i=0;i<ans.size();i++){
            answer.push_back(ans[i][ans[i].size()-1]);
        }
        return answer;
    }
};