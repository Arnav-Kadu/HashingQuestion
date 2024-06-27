// हर हर महादेव
#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define ll long long int
#define int long long
#define ld long double
#define mp make_pair
#define loop(a, b, i) for (int i = a; i < b; i++)
#define loop1(a, b, i) for (int i = a; i > b; i--)
#define For(i, n) loop(0, n, i)
#define Fori(i, n) loop1(n, -1, i)
#define w(t) \
int t;\
cin >> t;\
while (t--)
#define mod 1000000007
#define cbn cout << endl;
#define len(a) a.size()
#define pb push_back
#define vi vector<int>
#define vit vector<int>::iterator
#define viit vector<int>::iterator
#define pii pair<int, int>
#define PI 3.1415926535897932384626
#define vll vector<int>
#define vvll vector<vll>
#define fast
#define dsort(a) sort(a, a + n, greater<int>())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) (int)a.size()
#define vpi vector<pair<int, int>> // make_pair(x,y);
#define ma map<int, int>
#define ss second
#define ff first
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
/****************************************YAHA HAI ASLI MAAL***************************************/
int base1 = 304933, base2 = 4395853, p1 = 1e9 + 7, p2 = 1e9 + 9;
vector<int>pow1(5005),pow2(5005);
void solve()
{
    int n;
    cin >> n;
    vector<int>a(5005);
    map<pair<int,int>,int>m,checker[5005];
    int z=n;
    int i=0;
    while(z--){
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        if(!m.count({x,y})){
            m[{x,y}]=m.size();
        }
        a[i]=m[{x,y}];
        i++;
    }
    int ans = 0;
        for (int i = 0; i < n; ++i) {
            long long hsh1 = 0, hsh2 = 0;
            for (int j = i; j < n; ++j) {
                hsh1 = (hsh1 + pow1[a[j]]) % p1;
                hsh2 = (hsh2 + pow2[a[j]]) % p2;
                ans += checker[j-i][{hsh1,hsh2}];
                ++checker[j-i][{hsh1,hsh2}];
            }
        }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fast
    
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < 5005; ++i) {
        pow1[i] = (pow1[i-1] * base1) % p1;
        pow2[i] = (pow2[i-1] * base2) % p2;
    }
    w(t)
    {
        solve();
    }
}
