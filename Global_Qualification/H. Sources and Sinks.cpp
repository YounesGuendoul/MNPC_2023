#include <iostream>
#include <vector>
 
using namespace std;
 
using ll = long long;
 
ll dfs(ll node, ll parent, const vector<vector<ll>>& graph, vector<ll>& subtree_leafs) {
    ll leaf_count = 0;
    for (ll neighbor : graph[node]) {
        if (neighbor != parent) {
            leaf_count += dfs(neighbor, node, graph, subtree_leafs);
        }
    }
    subtree_leafs[node] = (leaf_count == 0) ? 1 : leaf_count;
    return subtree_leafs[node];
}
 
int main() {
    int test_cases;
    cin >> test_cases;
 
    while (test_cases--) {
        int num_nodes;
        cin >> num_nodes;
 
        vector<ll> node_weights(num_nodes);
        for (int i = 0; i < num_nodes; i++) {
            cin >> node_weights[i];
        }
 
        vector<vector<ll>> graph(num_nodes, vector<ll>());
 
        for (int i = 0; i < num_nodes - 1; i++) {
            ll u, v;
            cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
 
        vector<ll> subtree_leafs(num_nodes, 0);
        dfs(0, -1, graph, subtree_leafs);
 
        for (int i = 0; i < num_nodes; i++) {
            subtree_leafs[i] *= node_weights[i];
        }
 
        ll total_sum = 0, min_value = 0;
 
        for (int i = 0; i < num_nodes; i++) {
            min_value = min(min_value, subtree_leafs[i]);
            total_sum += subtree_leafs[i];
        }
 
        cout << max(total_sum, total_sum - min_value) << endl;
    }
 
    return 0;
}