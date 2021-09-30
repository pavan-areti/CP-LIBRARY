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
    rep(i, 0, sz(key) - 1) {
        int ind = key[i] - 'a';
        if (!root->next[ind])
            root->next[ind] = get_node();
 
        root = root->next[ind];
    }
 
    root->is_word = true;
}
 
bool search(TrieNode *root, string key) {
    rep(i, 0, sz(key) - 1) {
        int ind = key[i] - 'a';
        if (!root->next[ind])
            return false;
 
        root = root->next[ind];
    }
 
    return (root->is_word);
}
