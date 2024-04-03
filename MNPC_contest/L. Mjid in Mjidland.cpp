#include <bits/stdc++.h>
using namespace std;
 
 
struct Line {
    mutable long long slope, intercept, precision;
    bool operator<(const Line& other) const { return slope < other.slope; }
    bool operator<(long long x) const { return precision < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
    static const long long inf = LLONG_MAX;
    long long divide(long long a, long long b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool intersect(iterator x, iterator y) {
        if (y == end())
            return x->precision = inf, 0;
        if (x->slope == y->slope)
            x->precision = x->intercept > y->intercept ? inf : -inf;
        else
            x->precision = divide(y->intercept - x->intercept, x->slope - y->slope);
        return x->precision >= y->precision;
    }
    void add(long long slope, long long intercept) {
        auto z = insert({slope, intercept, 0}), y = z++, x = y;
        while (intersect(y, z)) z = erase(z);
        if (x != begin() && intersect(--x, y)) intersect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->precision >= y->precision)
            intersect(x, erase(y));
    }
    long long query(long long x) {
        assert(!empty());
        auto line = *lower_bound(x);
        return line.slope * x + line.intercept;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long queries;
    cin >> queries;
    char operation;
    long long a, b;
    vector<pair<long long, long long>> points;
    vector<long long> answers(1e5 + 1);
    long long max_val = 0;
    LineContainer op;
    for (long long i = 0; i < queries; i++) {
        cin >> operation;
        if (operation == 'A') {
            cin >> a >> b;
            op.add(a, b);
        } else {
            cin >> a;
            cout << op.query(a) << endl;
        }
    }   
}