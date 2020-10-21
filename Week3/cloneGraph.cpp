/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& m) {
        if(node == NULL) 
            return NULL;
        
        if(m.find(node) != m.end()) 
            return m[node];
        
        Node* root = new Node(node->val);
        m[node] = root;
        
        for(Node* ng: node->neighbors)
            root->neighbors.push_back(cloneGraph(ng, m));
        
        return root;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return cloneGraph(node, m);
    }
};