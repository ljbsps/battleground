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
struct Node {
    int row, col, val;
    Node() {}
    Node(int row, int col, int val) : row(row), col(col), val(val) {}
};

bool comp(Node a, Node b) {
    if (a.col == b.col) {
        if (a.row == b.row)
            return a.val < b.val;
        else
            return a.row < b.row;
    }
    else return a.col < b.col;
}

int r = 0, c = 0;
vector<Node> vec;

void vertical_traverse(TreeNode* now, int row, int col) {
    vec.push_back(Node(row, col, now->val));
    if (NULL != now->left) {
        vertical_traverse(now->left, row + 1, col - 1);
    }
    if (NULL != now->right) {
        vertical_traverse(now->right, row + 1, col + 1);
    }
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vec.clear();
        vector<vector<int>> answer;
        vertical_traverse(root, 0, 0);
        sort(vec.begin(), vec.end(), comp);

        for (int i = 0; i < vec.size(); i++) {
            vector<int> elem;
            int column = vec[i].col;
            int idx = i;
            while (1) {
                if (idx + 1 == vec.size() || column != vec[idx + 1].col) break;
                idx++;
            }
            for (int range = i; range <= idx; range++) {
                elem.push_back(vec[range].val);
            }
            answer.push_back(elem);
            i = idx;
        }
        return answer;
    }
};