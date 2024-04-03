#include <bits/stdc++.h>
using namespace std;
 
vector<long long> component;
void dfs(int node, vector<long long> adjacency[], vector<bool>& visited){
    if(visited[node])
        return;
    visited[node] = true;
    component.push_back(node);
    for(int neighbor : adjacency[node]){
        if(!visited[neighbor])
            dfs(neighbor, adjacency, visited);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    // Phi Function up to 1e5
    long long max_limit = 1e5;
    vector<long long> phi(max_limit + 1);
    for (long long i = 0; i <= max_limit; i++)
        phi[i] = i;
    for (long long i = 2; i <= max_limit; i++) {
        if (phi[i] == i) {
            for (long long j = i; j <= max_limit; j += i)
                phi[j] -= phi[j] / i;
        }
    }
 
    long long n, m;
    cin >> n >> m;
    vector<long long> values(n + 1);
    vector<bool> visited(n + 1);
    for(long long i = 1; i <= n ; i++){
        cin >> values[i];
    }
    long long u, v;
    vector<long long> adjacency[n + 1];
    for(long long i = 0; i < m ; i++){
        cin >> u >> v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
    map<long long, long long> value_counts;
    long long result = 0;
    for(long long i = 1 ; i <= n ; i++){
        if(!visited[i]){
 
            component.clear();
            value_counts.clear();
            dfs(i, adjacency, visited);
 
            for(long long node : component){
                for(long long j = 1; j*j <= values[node] ; j++){
                    if(values[node] % j == 0){
                        value_counts[j]++;
                        if(j*j != values[node]){
                            value_counts[values[node] / j]++;
                        }
                    }
                }
            }
            for(auto& [gcd, count] : value_counts){
                result += phi[gcd] * (count * (count - 1) / 2);
            }
        }
    }
    cout << result << endl;
}