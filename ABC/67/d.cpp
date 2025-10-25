#include <bits/stdc++.h>
#include <atcoder/all>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout << (x) << "\n"
#define PQ(x) priority_queue<x>
#define PQR(x) priority_queue<x, vector<x>, greater<x>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n")
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n")
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
int main()
{
    ll n;
    cin >> n;
    vvll t(n, vll(0));
    rep(i, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        t[a].pb(b);
        t[b].pb(a);
    }
    vll route(0);
    auto dfs = [&](auto dfs, ll now, ll par) -> bool
    {
        if (now == n - 1)
        {
            route.pb(now);
            return true;
        }
        for (auto nx : t[now])
        {
            if (nx == par)
                continue;
            if (dfs(dfs, nx, now))
            {
                route.pb(now);
                return true;
            }
        }
        return false;
    };
    dfs(dfs, 0, -1);
    reverse(all(route));
    vll c(n, -1);
    c[0] = 0;
    c[n - 1] = 1;
    rep(i, route.size())
    {
        if ((route.size() - 1) / 2 >= i)
        {
            c[route[i]] = 0;
        }
        else
        {
            c[route[i]] = 1;
        }
    }
    rep(i, route.size())
    {
        queue<ll> que;
        que.push(route[i]);
        while (que.size())
        {
            ll now = que.front();
            que.pop();
            for (auto nx : t[now])
            {
                if (c[nx] == -1)
                {
                    c[nx] = c[route[i]];
                    que.push(nx);
                }
            }
        }
    }
    ll f = 0;
    ll s = 0;
    rep(i, n)
    {
        if (c[i])
            s++;
        else
            f++;
    }
    if (s >= f)
    {
        cout << "Snuke" << endl;
    }
    else
    {
        cout << "Fennec" << endl;
    }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
