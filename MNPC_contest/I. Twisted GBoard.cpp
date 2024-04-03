#include <bits/stdc++.h>
using namespace std;
 
void dfs(int node, vector<int>& in_degree, pair<int,int> children[], string directions, vector<bool>& visited, vector<int>& value){
	if(visited[node])
		return ;
	visited[node] = true;
	int left_child = children[node].first;
	int right_child = children[node].second;
	value[left_child] += value[node]/2;
	value[right_child] += value[node]/2;
	if(directions[node] == 'L')
		value[left_child] += value[node]%2;
	else
		value[right_child] += value[node]%2;
	in_degree[left_child]--;
	in_degree[right_child]--;
	if(in_degree[right_child] == 0 && !visited[right_child]){
		dfs(right_child, in_degree, children, directions, visited, value);
	}
	if(in_degree[left_child] == 0 && !visited[left_child]){
		dfs(left_child, in_degree, children, directions, visited, value);
	}
}
 
void dfsWithZeroInDegree(int node, vector<int>& in_degree, pair<int,int> children[], vector<bool>& visited, vector<int>& value){
	if(visited[node])
		return ;
	visited[node] = true;
	if(in_degree[node] == 0){
		in_degree[children[node].first]--;
		in_degree[children[node].second]--;
		dfsWithZeroInDegree(node, in_degree, children, visited, value);
	}
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num_nodes, num_pairs;
    cin >> num_nodes >> num_pairs;
    int a, b;
    pair<int,int> children[num_pairs + 2];
    vector<int> in_degree(num_pairs + 2);
    for(int i = 1; i <= num_pairs ; i++){
    	cin >> a >> b;
    	children[i].first  = a;
    	children[i].second = b;
    	in_degree[a]++;
    	in_degree[b]++;
    }
    vector<bool> visited(num_pairs + 2);
    vector<int> value(num_pairs + 2);
    string directions;
    cin >> directions;
    directions = "0" + directions;
    value[1] = num_nodes;
    for(int i = 2; i <= num_pairs ; i++){
    	if(in_degree[i] == 0){
    		dfsWithZeroInDegree(i, in_degree, children, visited, value);
    	}
    }
   	dfs(1, in_degree, children, directions, visited, value);
   	for(int i = 1; i <= num_pairs ; i++){
   		if(value[i]%2 == 1){
   			if(directions[i] == 'L')
   				directions[i] = 'R';
   			else
   				directions[i] = 'L';
   		}
   	}
   	for(int i = 1 ; i < directions.size() ; i++){
   		cout << directions[i];
   	}
   	cout << endl;
}