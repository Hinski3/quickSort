#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define yn (solve() : "YES" ? "NO")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int,null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

ll podziel(vector<ll> &v, ll l, ll r){
    ll pivot = v[(l + r) / 2];
    l--, r++;

    while(1){
        while(v[++l] < pivot);
        while(v[--r] < pivot);

        if(l >= r) break;
        swap(v[l], v[r]);
    }

    return r;
}

void sortowanie(vector<ll> &v, ll l, ll r){
    if(l >= r) return;
    ll mid = podziel(v, l, r);

    sortowanie(v, l, mid);
    sortowanie(v, mid + 1, r);
}

int main(){
    io;

    //wczytywanie
    int n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sortowanie(v, 0, n - 1);
    for(auto u: v) cout << u << ' ';
    cout << endl;
}
