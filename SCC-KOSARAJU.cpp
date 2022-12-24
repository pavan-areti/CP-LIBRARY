struct SCC {
    int n, m;

    struct Node {
        vector<int> adj;
        vector<int> rev_adj;
    };

    vector<Node> g;
    stack<int> S;
    vector<bool> visited;

    vector<int> component;
    map<int, vector<int>> components;
    int numComponents;
    vector<vector<int>> kernel;

    SCC(int n, int m, const vector<vector<int>> &g) {
        this->n = n;
        this->m = m;
        this->numComponents = 0;

        this->g.resize(n + 1);
        for(int i = 1; i <= n; i ++) {
            for(auto v : g[i]) {
                this->g[i].adj.push_back(v);                
                this->g[v].rev_adj.push_back(i);                
            }
        }
        this->visited.resize(n + 1);
        this->component.resize(n + 1);
    }

    void dfs_1(int x) {
        visited[x] = true;
        for(int i = 0; i < g[x].adj.size(); i++) {
            if(!visited[g[x].adj[i]]) dfs_1(g[x].adj[i]);
        }
        S.push(x);
    }

    void dfs_2(int x) {
        component[x] = numComponents;
        components[numComponents].push_back(x);
        visited[x] = true;
        for(int i = 0; i < g[x].rev_adj.size(); i++) {
            if (!visited[g[x].rev_adj[i]]) dfs_2(g[x].rev_adj[i]);
        }
    }

    void Kosaraju() {
        for(int i = 1; i <= n; i++)
            if (!visited[i]) dfs_1(i);

        for(int i = 1; i <= n; i++)
            visited[i] = false;

        while(!S.empty()) {
            int v = S.top();
            S.pop();
            if(!visited[v]) {
                numComponents++;
                dfs_2(v);
            }
        }
    }    

    void createKernelDAG() {
        kernel.resize(numComponents + 1);
        for(auto &[comp_id, nodes] : components) {
            for(int u : nodes) {
                for(int v : g[u].adj) {
                    if(component[u] != component[v]) {
                        kernel[comp_id].push_back(component[v]);
                    }
                }
            }
        }        
    }
};
