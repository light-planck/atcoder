#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  string t;
  cin >> t;

  auto x = s; auto y = t;
  sort(x.begin(), x.end()); sort(y.begin(), y.end());
  if (x != y) {
    cout << -1 << '\n';
    return 0;
  }

  
  return 0;
}