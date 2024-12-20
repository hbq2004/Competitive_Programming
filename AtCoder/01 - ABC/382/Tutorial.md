# AtCoder Beginner Contest 382

[Problems](https://atcoder.jp/contests/abc382/tasks) 

[CLIST - Problems Rating Contributions](https://clist.by/problems/?resource=93&contest=55077887) 

> 参考题解：
>
> - [Official - Blog](https://atcoder.jp/contests/abc382/editorial) 
> - [清北学堂信息学 - A ~ G - Video - Bilibili](https://www.bilibili.com/video/BV16AzZYeEGN/) 
> - [RegenFallen - A ~ D - Video - Bilibili](https://www.bilibili.com/video/BV1TAzpYmEcC/) 


E 的概率与期望 DP 比 F 线段树 还难。


## A. 



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    string S;
    cin >> N >> D >> S;

    int cnt = count(S.begin(), S.end(), '@');

    cout << N - cnt + min(cnt, D) << '\n';

    return 0;
}
```

## B. 



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    string S;
    cin >> N >> D >> S;

    int cnt = count(S.begin(), S.end(), '@');

    cnt -= min(cnt, D);

    if (cnt == 0) {
        cout << string(N, '.') << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (S[i] == '@') {
            if (cnt > 0) {
                cnt -= 1;
                cout << '@'; 
            } else {
                cout << string(N - i, '.') << '\n';
                return 0;
            }
        } else {
            cout << S[i];
        }
    }
    cout << '\n';

    return 0;
}
```

## C. 



```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int K = 2E5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> id(K + 1, -1);
    
    int cur = K;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a; 
        for (; cur >= a; cur--) {
            id[cur] = i;
        }
    }

    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        cout << id[b] << '\n';
    }

    return 0;
}
```

## D. 


```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> ans;
    vector<int> temp;
    auto dfs = [&](auto self, int u, int pre) -> void {
        if ((M - (pre + 10) + 1 + 9) / 10 < N - u) {
            return;
        }
        if (u == N) {
            ans.push_back(temp);
            return;
        }
        for (int i = pre + 10; i <= M; i++) {
            temp.push_back(i);
            self(self, u + 1, i);
            temp.pop_back();
        }
    };

    dfs(dfs, 0, -9);

    cout << ans.size() << '\n';
    for (auto v : ans) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}
```

## E. 

概率与期望 DP。


```cpp

```


## F. 

> Description：
>
> 给定一个 $H \times W$ 的矩阵，有 $N$ 个单杠放在矩阵中，第 $i$ 个单杠的属性可以描述为 $(R_i, C_i, L_i)$，表示第 $i$ 个单杠的左端点在 $(R_i, C_i)$，且向右延申 $L_i$ 格。
>
> 模拟**俄罗斯方块**的最终状态，具体来说，**依次考虑** $1 \sim N$ 个单杠，如果第 $i$ 个单杠不在最后一行，且其正下方区域没有任何其它单杠，那么该单杠落到下一行。


数据结构模拟题。

```cpp

```

## G. 



```cpp

```