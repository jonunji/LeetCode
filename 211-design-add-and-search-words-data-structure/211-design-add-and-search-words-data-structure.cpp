class WordDictionary {
public:
    typedef struct Trie
    {
        Trie* letters[26];
        bool valid;

        Trie() : valid(false), letters{NULL} {}
        Trie(bool val) : valid(val), letters{NULL} {}
    } Trie;

    Trie* trie;

    WordDictionary() 
    {
        trie = new Trie();
    }
    
    void addWord(string word) 
    {
        Trie* node = trie;
        for (char ch : word)
        {
            int curr = ch - 'a';
            if (!node->letters[curr]) node->letters[curr] = new Trie();

            node = node->letters[curr];
        }

        node->valid = true;
    }
    
    bool search(string word) 
    {
        return search(trie, word);
    }

    bool search(Trie* node, string word) 
    {
        for (int j = 0; node && j < word.size(); j++)
        {
            if (word[j] != '.')
                node = node->letters[word[j] - 'a'];
            else 
            {
                for (int i = 0; i < 26; i++)
                    if (node->letters[i])
                        if (search(node->letters[i], word.substr(j+1))) 
                            return true;
                
                return false;
            }
        }

        return node && node->valid;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */