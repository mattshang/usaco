#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }
void pr(bool x) { cout << (x ? "true" : "false"); }

template <typename T1, typename T2>
void pr(const pair<T1, T2>& p) {
    pr("{ "); pr(p.first); pr(", "); pr(p.second); pr(" }");
}

template <typename T> 
void pr(T& v) {
    cout << "{";
    bool f = true; for (const auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x);
    cout << "}";
}

void pd() { cout << "]" << endl; }

template <typename T, typename... U>
void pd(T first, U... rest) {
    pr(first); if (sizeof...(rest)) cout << ", "; pd(rest...);
}

#ifdef TESTING
#define dbg(x...) cout << "[" << #x << "] = [", pd(x)
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;
        vector<int> a(n); for (int& x : a) cin >> x;

        vector<ll> pre(n + 1);
        pre[0] = 0;
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + a[i];
        int idx = 0;
        if (pre[n] <= s) {
            idx = 0;
        } else {
            int mx = 0;
            int j = -1;
            for (int i = 0; i < n; i++) {
                mx = max(mx, a[i]);
                if (pre[i + 1] - mx > s) {
                    j = i;
                    break;
                }
            }
            if (j == -1) j = n;
            mx = 0;
            for (int i = 0; i < j; i++) {
                if (a[i] > mx) {
                    mx = a[i];
                    idx = i + 1;
                }
            }
        }
        cout << idx << endl;
    }

    return 0;
}
