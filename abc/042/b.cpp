#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, l;
  cin >> n >> l;

  vector<string> s(n);
  rep(i, n) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());

  string ans = "";
  rep(i, n) ans += s[i];
  cout << ans << '\n';
  return 0;
}