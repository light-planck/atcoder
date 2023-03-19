#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string t;
  cin >> t;

  ll n = t.size();
  ll m = s.size();

  vector<bool> pre(n+1);
  pre[0] = true;
  rep(i, n) {
    if (not pre[i]) continue;

    if ((s[i]==t[i]) or (s[i]=='?' or t[i]=='?')) pre[i + 1] = true;
  }

  vector<bool> suf(n+1);
  suf[0] = true;
  rep(i, n) {
    if (not suf[i]) continue;

    if ((s[m-1-i]==t[n-1-i]) or (s[m-1-i]=='?' or t[n-1-i]=='?')) suf[i + 1] = true;
  }

  rep(x, n+1) {
    if (pre[x] and suf[n-x]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}