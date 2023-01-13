#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string o;
  cin >> o;

  string e;
  cin >> e;

  ll n = e.size();
  rep(i, n) cout << o[i] << e[i];
  if (o.size() != e.size()) cout << o.back() << '\n';
  return 0;
}