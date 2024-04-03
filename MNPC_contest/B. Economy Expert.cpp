#include <bits/stdc++.h>
using namespace std;
 
map<long long, long long> component_map;
 
void dfs(long long node, vector<bool>& visited, vector<long long> adjacency_list[], long long component_number) {
    if (visited[node])
        return;
    
    component_map[node] = component_number;
    visited[node] = true;
    
    for (long long neighbor : adjacency_list[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjacency_list, component_number);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        long long vertices, edges, queries;
        cin >> vertices >> edges >> queries;
        
        vector<long long> adjacency_list[vertices + 1];
        long long from, to, cost;
        
        for (long long i = 0; i < edges; i++) {
            cin >> from >> to;
            adjacency_list[from].push_back(to);
            adjacency_list[to].push_back(from);
        }
        
        vector<bool> visited(vertices + 1);
        long long component_number = 1;
        
        // Assigning component numbers to the connected components
        for (long long i = 1; i <= vertices; i++) {
            if (!visited[i]) {
                dfs(i, visited, adjacency_list, component_number);
                component_number++;
            }
        }
        
        map<pair<long long, long long>, long long> edge_cost_map;
        long long max_cost = 0, source, destination;
        long long total_cost = 0;
 
        for (long long i = 0; i < queries; i++) {
            cin >> from >> to >> cost;
            source = component_map[from];
            destination = component_map[to];
            
            if (destination < source)
                swap(source, destination);
            
            if (source == destination) {
                total_cost += cost;
            } else {
                edge_cost_map[{source, destination}] += cost;
            }
        }
        
        for (auto edge : edge_cost_map) {
            max_cost = max(max_cost, edge.second);
        }
        
        cout << total_cost + max_cost << endl;
        component_map.clear();
    }
    return 0;
}