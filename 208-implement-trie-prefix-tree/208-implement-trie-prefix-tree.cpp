class Trie {
public:
    
    typedef struct TrieNode
    {
        TrieNode* letters[26];
        int count;
        TrieNode() : count(0), letters{NULL} {}
        TrieNode(char ch) : count(0), letters{NULL} {}
    } TrieNode;
    
    TrieNode* trie;
    
    Trie() 
    {
        trie = new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode* curr = trie;
        
        for (char ch : word)
        {
            if (!curr->letters[ch - 'a'])
                curr->letters[ch - 'a'] = new TrieNode(ch);
                
            curr = curr->letters[ch - 'a'];
        }
        
        curr->count++;
    }
    
    bool search(string word) 
    {
        TrieNode* curr = trie;  
        for (char ch : word)
        {
            if (!curr->letters[ch - 'a']) return false;
            
            curr = curr->letters[ch - 'a'];
        }
        
        return curr->count != 0;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* curr = trie;  
        for (char ch : prefix)
        {
            if (!curr->letters[ch - 'a']) return false;
            
            curr = curr->letters[ch - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */