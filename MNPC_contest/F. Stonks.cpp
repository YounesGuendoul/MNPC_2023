#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long num;
    cin >> num;
    multiset<tuple<long long, long long, string>> multi_set;
    map<string, long long> frequency_map, sum_map;
    string name;
    long long type, value;
    for (long long i = 1; i <= num; i++) {
        cin >> type;
        if (type == 1) {
            cin >> name >> value;
            if (frequency_map[name] != 0) {
                multi_set.erase({-frequency_map[name], -sum_map[name], name});
            }
            frequency_map[name]++;
            sum_map[name] += value;
            multi_set.insert({-frequency_map[name], -sum_map[name], name});
        } else {
            cout << get<2>(*(multi_set.begin())) << endl;
        }
    }
}