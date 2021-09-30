/*
    space   O(nlog(max[i]))
    insert  O(log(max(a[i])))
    lookup  O(log(max(a[i])))    

    initialization : TrieNode *root = getNode()
    insertion: insert(root, x)
    lookup: max_xor(root, y)
*/

const int LEN = 32; 

struct TrieNode {
    TrieNode *next[2];
};
 
TrieNode* get_node() {
    struct TrieNode *new_node =  new TrieNode;
    new_node->next[0] = NULL;
    new_node->next[1] = NULL; 
    return new_node;
}

void insert(TrieNode *root, int x) {
    repr(i, LEN, 0) {
        int bit = ((x >> i) & 1);
        if(root->next[bit] == NULL) {
            root->next[bit] = get_node();
        }
        root = root->next[bit];
    }
}
 
int max_xor(TrieNode *root, int y) {
    int ret = 0;
    repr(i, LEN, 0) {
        int bit = ((y >> i) & 1);
        if(root->next[bit ^ 1] == NULL) {
            root = root->next[bit];
        }
        else {
            ret |= (1LL << i);
            root = root->next[bit ^ 1];
        }
    }
    return ret;
}
