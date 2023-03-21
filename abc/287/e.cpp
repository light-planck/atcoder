#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


ll lcp(string s, string t) {
  ll res = 0;
  ll n = s.size();
  rep(i, n) {
    if (s[i] == t[i]) ++res;
    else break;
  }
  return res;
}


int main() {
  ll n;
  cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  auto t = s;
  sort(t.begin(), t.end());

  vector<ll> ans(n);
  rep(i, n) {
    ll idx = lower_bound(t.begin(), t.end(), s[i]) - t.begin();
    if (idx-1 >= 0) {
      ans[i] = max(ans[i], lcp(s[i], t[idx-1]));
    }
    if (idx+1 < n) {
      ans[i] = max(ans[i], lcp(s[i], t[idx+1]));
    }
  }

  rep(i, n) {
    cout << ans[i] << '\n';
  }
  return 0;
}