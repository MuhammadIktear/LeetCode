class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> v;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();
                if (current) {
                    v.push_back(current->val);
                    q.push(current->left);
                    q.push(current->right);
                } else {
                    v.push_back(INT_MIN);
                }
            }
            int start = 0;
            int end = v.size() - 1;
            while (start < end) {
                if (v[start] != v[end])
                    return false;
                start++;
                end--;
            }
        }
        return true;
    }
};