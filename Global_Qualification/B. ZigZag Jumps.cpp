#include <iostream>
#include <vector>
#include <map>
 
struct MyComparator {
    bool operator()(const int& a, const int& b) const {
        return a <= b;
    }
};
 
int main(){
    int n, result = 1; std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) std::cin >> vec[i];
    std::vector<int> odd(n), even(n);
    odd[n - 1] = even[n - 1] = 1;
    std::map<int, int, MyComparator> map;
    map[vec[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        auto hi = map.lower_bound(vec[i]), lo = map.upper_bound(vec[i]);
        if (hi != map.end()) odd[i] = even[hi->second];
        if (lo != map.begin()) even[i] = odd[(--lo)->second];
        if (odd[i]) result++;
        map[vec[i]] = i;
    }
    std::cout << result << std::endl;
    return 0;
}