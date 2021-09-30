/*
    space   O(n∗k)
    insert  O(k)
    lookup  O(k)    

    initialization : TrieNode *root = getNode()
    insertion: insert(root, keys[i])
    lookup: search(root, "codeforces")
*/

const int ALPHABET_SIZE = 26;
 
struct TrieNode {
    TrieNode *next[ALPHABET_SIZE];
    bool is_word;
};
 
TrieNode* get_node() {
    struct TrieNode *new_node =  new TrieNode;
 
    new_node->is_word = false;
    
    rep(i, 0, ALPHABET_SIZE - 1) 
        new_node->next[i] = NULL;
 
    return new_node;
}
 
void insert(TrieNode *root, string key) {
    TrieNode *cur = root;
 
    rep(i, 0, sz(key) - 1) {
        int ind = key[i] - 'a';
        if (!cur->next[ind])
            cur->next[ind] = get_node();
 
        cur = cur->next[ind];
    }
 
    cur->is_word = true;
}
 
bool search(TrieNode *root, string key) {
    struct TrieNode *cur = root;
 
    rep(i, 0, sz(key) - 1) {
        int ind = key[i] - 'a';
        if (!cur->next[ind])
            return false;
 
        cur = cur->next[ind];
    }
 
    return (cur->is_word);
}
