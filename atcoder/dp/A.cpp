#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vi h(n);
    F0R (i, n) cin >> h[i];
    vi dp(n, 2e9);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    FOR (i, 2, n - 1) {
        dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    }
    cout << dp[n - 1] << endl;

    return 0;
}
