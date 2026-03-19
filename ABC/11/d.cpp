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
#define ld long double
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
#define PQ priority_queue<ll>
#define PQR priority_queue<ll, vector<ll>, greater<ll>>
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
    ll n, d;
    cin >> n >> d;
    ll x, y;
    cin >> x >> y;
    long double k = 1;
    rep(i, n)
    {
        k *= 0.25;
    }
    ld ans = 0;
    if (x % d != 0 || y % d != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    ll a = max(x / d, -1 * x / d);
    ll b = max(y / d, -1 * y / d);
    n -= (a + b);
    if (n < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<long double>> s(1100, vector<long double>(1100));
    s[1][1] = 1.0;
    rep(i, 1100)
    {
        s[i][0] = 1.0;
        s[i][i] = 1.0;
    }
    for (int i = 2; i < 1100; i++)
    {
        for (int j = 1; j < i; j++)
        {
            s[i][j] = (s[i - 1][j - 1] + s[i - 1][j]);
        }
    }
    rep(i, n / 2 + 1)
    {
        ll xc = i;
        ll yc = (n - 2 * i)/2;
        ld res = s[xc][xc];
        res *= s[xc + xc + a][xc];
        res *= s[2 * xc + a + yc][yc];
        res *= s[2 * xc + a + 2 * yc + b][yc + b];
        ans += res * k;
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
