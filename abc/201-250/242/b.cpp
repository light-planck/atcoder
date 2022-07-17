#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  string ans = "";
  map<char, int> mp;
  rep(i, s.size()) {
    ++mp[s[i]];
  }

  for (auto x : mp) {
    char c = x.first;
    int n = x.second;

    rep(i, n) ans += c;
  }

  cout << ans << "\n";
  return 0;
}