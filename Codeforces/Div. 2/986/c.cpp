#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    vector<int> f(n + 1), g(n + 2);
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        sum += a[i];
        if (sum >= v) {
            sum = 0;
            f[i]++;
        }
    }
    sum = 0;
    for (int i = n; i >= 1; i--) {
        g[i] = g[i + 1];
        sum += a[i];
        if (sum >= v) {
            sum = 0;
            g[i]++;
        }
    }

    i64 ans = -1;
    for (int i = 0; i <= n; i++) {
        if (i == 0 || f[i] != f[i - 1]) {
            int lo = i + 1, hi = n + 1;
            while (lo < hi) {
                int mi = (lo + hi + 1) >> 1;
                if (g[mi] >= m - f[i]) {
                    lo = mi;
                } else {
                    hi = mi - 1;
                }
            }
            if (g[lo] >= m - f[i]) {
                ans = max(ans, s[lo - 1] - s[i]); // i + 1 .. lo - 1
            }
        }
    }

    for (int i = n + 1; i >= 1; i--) {
        if (i == n + 1 || g[i] != g[i + 1]) {
            int lo = 0, hi = i - 1;
            while (lo < hi) {
                int mi = (lo + hi) >> 1;
                if (f[mi] >= m - g[i]) {
                    hi = mi;
                } else {
                    lo = mi + 1;
                }
            }
            if (f[lo] >= m - g[i]) {
                ans = max(ans, s[i - 1] - s[lo]); // lo + 1 .. i - 1
            }
        }
    }

    cout << ans << '\n';    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*

f[i]: 表示 1 .. i 最多可以满足几个人
g[i]: 表示 i .. n 最多 .. 

1
6 2 1
1 1 10 1 1 10

1
6 2 3
1 1 10 1 1 10

1
6 2 3
10 1 1 10 1 1

*/