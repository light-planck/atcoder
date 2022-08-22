#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string t;
  cin >> t;

  vector<ll> f(26, -1);
  vector<ll> g(26, -1);
  ll n = s.size();
  
  rep(i, n) {
    ll a = s[i] - 'a';
    ll b = t[i] - 'a';
    
    if (f[a] != -1 or g[b] != -1) {
      if (f[a] != b or g[b] != a) {
        cout << "No" << '\n';
        return 0;
      }
    }
    else {
      f[a] = b;
      g[b] = a;
    }
  }

  cout << "Yes" << '\n';
  return 0;
}