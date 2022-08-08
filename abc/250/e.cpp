#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct custom_hash {
  static ll splitmix64(ll x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  ll operator() (ll x) const {
      static const ll FIXED_RANDOM =    
          chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
    }
} rng;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> hash_a(n + 1);
  rep(i, n) {
    set<ll> st;
    if (st.count(a[i])) hash_a[i + 1] = hash_a[i];
    else {
      st.emplace(a[i]);
      hash_a[i + 1] = hash_a[i] ^ rng(a[i]);
    }
  }

  vector<ll> b(n);
  rep(i, n) cin >> b[i];

  vector<ll> hash_b(n + 1);
  rep(i, n) {
    set<ll> st;
    if (st.count(b[i])) hash_b[i + 1] = hash_b[i];
    else {
      st.emplace(b[i]);
      hash_b[i + 1] = hash_b[i] ^ rng(b[i]);
    }
  }

  ll q;
  cin >> q;

  while (q--) {
    ll x, y;
    cin >> x >> y;

    if (hash_a[x] == hash_b[y]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
}