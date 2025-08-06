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
bool check(map<char, int> m)
{
    for (auto p : m)
    {
        if (p.second >= 2)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    map<char, int> m;
    if (s.size() == 2)
    {
        if (s[0] == s[1])
        {
            cout << "1 2" << endl;
        }
        else
        {
            cout << "-1 -1" << endl;
        }
        return 0;
    }
    else
    {
        m[s[0]]++;
        m[s[1]]++;
        for (int i = 0; i < (int)s.size() - 2; i++)
        {
            m[s[i + 2]]++;
            if (check(m))
            {
                cout << i + 1 << " " << i + 3 << endl;
                return 0;
            }
            m[s[i]]--;
        }
    }
    cout << "-1 -1" << endl;
}

/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
