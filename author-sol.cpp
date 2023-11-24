#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n, vector<int>());
    vector<int> rem(n, 0);
    vector<int> layer(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        rem[u]++;
        rem[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (rem[i] == 1) {
            q.push(i);
            layer[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (rem[v] != 1) {
                rem[v]--;
                if (rem[v] == 1) {
                    layer[v] = layer[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (layer[i] > k);
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
