// CRITICAL CONNECTIONS

int id = 0;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> ids;
vector<int> low;
vector<int> result;
int root = 0;
    void dfs(int at, int from) {
        int cut = 0;
        visited[at] = true;
        ids[at] = low[at] = id++;
        for (auto child : graph[at]) {
            if (child == from)
                continue;
            if (!visited[child]) {
                dfs(child, at);
                low[at] = min(low[at], low[child]);
                if (low[child] >= ids[at]) {
                    cut++;
                    if (at != root || cut > 1)
                        result.push_back(at);
                }
            } else {
                low[at] = min(low[at], ids[child]);
            }
        }
    }

vector<int> Critical_Router(int numRouter, int numLink, vector<vector<int>>& connections) {
    visited = vector<bool>(numRouter, false);
    ids = vector<int>(numRouter, 0);
    low = vector<int>(numRouter, 0);
    graph = vector<vector<int>>(numRouter, vector<int>());

    
    for (auto con : connections) {
        graph[con[0]].push_back(con[1]);
        graph[con[1]].push_back(con[0]);
    }
    
    for (int i = 0; i < numRouter; ++i) {
        if (!visited[i]) {
            root = i;
            dfs(i, i);
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> connections{{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6}, {3, 4}};
    result = Critical_Router(7, 7, connections);
    for (auto ans : result) {
        cout << ans << " ";
    }
    cout << endl;
    result.clear();
    vector<vector<int>> connections1{{0, 1}, {1, 2}, {0, 2}, {2, 3}, {2, 4}, {3, 4}};
    result = Critical_Router(5, 6, connections1);
    for (auto ans : result) {
        cout << ans << " ";
    }
    cout << endl;
    result.clear();
    vector<vector<int>> connections2{{0, 1}, {1, 2}, {0, 2}, {0, 3}, {3, 4}};
    result = Critical_Router(5, 5, connections2);
    for (auto ans : result) {
        cout << ans << " ";
    }
    cout << endl;
    
    return 0;
}