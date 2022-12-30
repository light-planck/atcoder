#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;
  vector<char> c(n);
  rep(i, n) cin >> c[i];

  string s = "";
  rep(i, n) s += c[i];
  
  if (stoll(s) % 4 == 0) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}