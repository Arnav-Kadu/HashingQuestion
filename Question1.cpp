// हर हर महादेव
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define mod 1000000007
#define cbn cout << endl;
inline void read(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
inline void read(vector<int> &a)
{
    for (auto &x : a)
        cin >> x;
}
inline int ceil(int a, int b)
{
    int ans = a / b;
    if ((b * ans) != a)
        ans += (a < 0) ^ (b > 0);
    return ans;
}
inline int floor(int a, int b)
{
    int ans = a / b;
    if ((b * ans) != a)
        ans -= (a > 0) ^ (b > 0);
    return ans;
}
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

// The question is pretty straight forward but the constraint won't allow direct POWER function in either C++ or Java
// Python i dont think so will face the overflower problem
int binary_expo(int base, int exponent)
{
    int result = 1;
    base %= mod;
    while (exponent)
    {
        if (exponent % 2)
            result = (result * 1LL * base) % mod;
        base = (base * 1LL * base) % mod;
        exponent /= 2;
    }
    return result;
}
/****************************************YAHA HAI ASLI MAAL***************************************/
void solve()
{
    int n, h, k,m;
    cin >> n >> h >> k>>m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp; // also testcases are set such that if anyone uses unordered map without proper optimization there solution will not pass
    for (int i = 0; i < n; i++)
    {
        mp[binary_expo(a[i],h)%m]++;
    }
    int request = 0;
    int available = 0;
    for (int i = 0; i < m; i++)
    {
        if (mp[i] <= k)
        {
            available += k - mp[i];
        }
        else
        {
            request += mp[i] - k;
        }
    }
    if (available < request)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << request << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    w(t)
    {
        solve();
    }
}