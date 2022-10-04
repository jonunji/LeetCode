class Solution {
public:
    vector<int> rank, par;
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        rank = vector<int>(edges.size() + 1, 1);
        par = vector<int>(edges.size() + 1);
        
        for (int i = 0; i < edges.size(); i++) par[i] = i;
        
        for (auto const &e : edges)
            if (!Union(e[0], e[1])) return e;
        
        return {};
    }
    
private:
    
    // gets the parent of the given node.
    int find(int x)
    {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    
    bool Union(int x, int y)
    {
        int xP = find(x), yP = find(y);
        
        // same parent, so we cant combine and thus adding another edge is redundant.
        if (xP == yP) return false; 
        
        // uses rank to ensure we dont have skewed trees.
        if (rank[xP] > rank[yP]) par[yP] = par[xP];
        else if (rank[yP] > rank[xP]) par[xP] = par[yP];
        else par[xP] = yP, rank[yP]++;
        
        return true;
    }
};