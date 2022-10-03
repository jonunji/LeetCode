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
public:
    Node* cloneGraph(Node* node) 
    {
        if (!node) return NULL;
        
        unordered_map<int, Node*> clones;
        queue<Node*> q;
        
        Node* copy = new Node(node->val);
        clones[node->val] = copy;
        
        q.push(node);
        while (!q.empty())
        {
            Node* curr = q.front();
            
            for (Node* n : curr->neighbors)
            {
                Node* nextCopy;
                
                if (clones.count(n->val) == 0)
                {
                    clones[n->val] = new Node(n->val);
                    q.push(n);
                }
                
                clones[curr->val]->neighbors.push_back(clones[n->val]);
            }
            
            q.pop();
        }
        
        return copy;
    }
};