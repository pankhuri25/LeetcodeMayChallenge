class TrieNode{
    public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;
    
        TrieNode(char data){
            this->data = data;
            isTerminal = false;
        }
};


class Trie {
    
    TrieNode* root;
    
    void insertWord(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        TrieNode* child;
        if(root->children.find(word[0]) != root->children.end())
            child = root->children[word[0]];
        else
        {
            root->children[word[0]] = new TrieNode(word[0]);
            child = root->children[word[0]];
        }
        insertWord(child, word.substr(1));
    }
    
    int doSearch(TrieNode* root, string word){
        if(word.length() == 0)
        {
            if(root->isTerminal)
                return 1;
            return 0;
        }
        if(root->children.find(word[0])!=root->children.end())
            return doSearch(root->children[word[0]], word.substr(1));
        return -1;
    }
    
public:
    /* Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    
    /* Inserts a word into the trie. */
    void insert(string word) {
        insertWord(root, word);
    }
    
    /* Returns if the word is in the trie. */
    bool search(string word) {
        if(doSearch(root, word) == 1)
            return true;
        return false;
    }
    
    /* Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int res = doSearch(root, prefix);
        if(res>=0)
            return true;
        return false;
    }
};
