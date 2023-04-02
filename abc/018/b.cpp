#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


string Slice(string& s, ll l, ll r) {
  if (r-l < 0 or r-l > (ll)s.size()) return "";
  return s.substr(l, r-l);
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  ll n;
  cin >> n;

  rep(i, n) {
    ll l, r;
    cin >> l >> r;
    --l; --r;

    string rev = Slice(s, l, r+1);
    reverse(rev.begin(), rev.end());

    s = Slice(s, 0, l) + rev + Slice(s, r+1, (ll)s.size());
  }

  cout << s << '\n';
  return 0;
}