#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ub --> lb, lb-->ub
//  order_of_key(x) --> no. of elements strictly less than x, returns an integer
//  find_by_order(x) --> returns an iterator to xth element, 0-based indexing.

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
template <class T>
using mxhp = priority_queue<T>;
template <class T>
using mihp = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define ppc(x) __builtin_popcount(x)
#define ppcl(x) __builtin_popcountll(x)
#define lz(x) __builtin_clz(x) // leading zeroes
#define lzl(x) __builtin_clzll(x)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())

#define fr(k, a, b) for (ll k = a; k < b; k++)
#define rfr(k, a, b) for (ll k = a; k >= b; k--)
#define raf(k, container) for (auto &k : container)
#define print(container)                \
    raf(k, container) cout << k << ' '; \
    cout << endl;
#define precise(x, y) cout << fixed << setprecision(y) << x << endl

namespace modop
{
    ll madd(ll a, ll b)
    {
        a = a % mod;
        b = b % mod;
        return (((a + b) % mod) + mod) % mod;
    }
    ll msub(ll a, ll b)
    {
        a = a % mod;
        b = b % mod;
        return (((a - b) % mod) + mod) % mod;
    }
    ll mmul(ll a, ll b)
    {
        a = a % mod;
        b = b % mod;
        return (((a * b) % mod) + mod) % mod;
    }
    ll mpow(ll a, ll b)
    {
        a %= mod;
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = mmul(res, a);
            a = mmul(a, a);
            b >>= 1;
        }
        return res;
    }
    ll minv(ll a) { return mpow(a, mod - 2); } // fermat's little theorem
    ll mdiv(ll a, ll b)
    {
        a = a % mod;
        b = b % mod;
        return (mmul(a, minv(b)) + mod) % mod;
    }
}
using namespace modop;

namespace combop
{
    const int maxN = 3e5 + 7;
    ll fact[maxN + 1], ifact[maxN + 1];
    void computeFact()
    {
        fact[0] = ifact[0] = fact[1] = ifact[1] = 1;
        fr(i, 2, maxN + 1) fact[i] = mmul(fact[i - 1], i);
        ifact[maxN] = minv(fact[maxN]);
        rfr(i, maxN - 1, 2) ifact[i] = mmul(i + 1, ifact[i + 1]);
    }
    ll ncr(ll n, ll r)
    {
        if (n < r)
            return 0;
        if (r == 0)
            return 1;
        return mmul(fact[n], mmul(ifact[n - r], ifact[r]));
    }
}
using namespace combop;

// Common mathematical utility functions
namespace mathop
{
    ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
    ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
    bool isPrime(ll n)
    {
        if (n <= 1)
            return false;
        for (ll i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
}
using namespace mathop;

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ll a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, u, v, w, x, y, z;
string s, t;

void setIO()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/******************************************************* Code Starts **********************************************************/

void solve()
{
}

int main()
{
    setIO();
    //    computeFact();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }

}
