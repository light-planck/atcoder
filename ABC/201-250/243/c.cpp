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

  int n;
  cin >> n;

  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  string s;
  cin >> s;

  bool collision = false;
  map<int, char> mp;
  rep(i, n) {
    if (mp.count(y[i])) {
      if (mp[y[i]] != s[i]) {
        collision = true;
      }
    }
    else {
      mp[y[i]] = s[i];
    }
  }

  if (collision) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}