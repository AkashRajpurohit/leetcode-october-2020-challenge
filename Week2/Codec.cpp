/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    char delimiter = ' ';
    
    // PreOrder
    void dfs(TreeNode* root, string& s) {
        if(root == NULL) return;
        
        s.append(to_string(root->val) + delimiter);
        
        dfs(root->left, s);
        dfs(root->right, s);
    }
    
    vector<int> stringToVector(string s) {
        vector<int> res;
        int n = s.size();
        int i = 0;
        string tmp = "";
        
        while(i < n) {
            
            while(i < n && s[i] != delimiter) {
                tmp += s[i];
                i++;
            }
            
            res.push_back(stoi(tmp));
            tmp.erase();
            i++;
        }
        
        return res;
    }
    
    TreeNode* createBST(vector<int> nums, int start, int end) {
        if(start > end) return NULL;
        
        TreeNode* root = new TreeNode(nums[start]);
        
        int index;
        
        for(index = start; index <= end; ++index) {
            if(nums[index] > nums[start]) break;
        }
        
        root->left = createBST(nums, start + 1, index - 1);
        root->right = createBST(nums, index, end);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s = "";
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        vector<int> nums = stringToVector(data);
        
        return createBST(nums, 0, nums.size() - 1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;