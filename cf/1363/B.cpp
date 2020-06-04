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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = sz(s);

        vi pre(n + 1);
        pre[0] = 0;
        F0R (i, n)
            pre[i + 1] = pre[i] + (s[i] == '1');
        int ans = n;
        ans = min(ans, pre[n]);
        ans = min(ans, n - pre[n]);
        F0R (i, n) {
            ans = min(ans, pre[i + 1] + (n - i - 1) - (pre[n] - pre[i + 1]));
            ans = min(ans, i + 1 - pre[i + 1] + pre[n] - pre[i + 1]);
        }
        cout << ans << nl;
    }

    return 0;
}
