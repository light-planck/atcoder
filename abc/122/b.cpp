#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

bool isacgt(string s) {
  bool ok = true;
  rep(i, s.size()) {
    if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T') {
      ok = false;
    }
  }
  if (ok) return true;
  else return false;
}

int main() {
  string s;
  cin >> s;
  int ans = 0;
  int l = s.size();
  for (int i = 0; i < l; i++) {
    for (int j = 1; i + j <= l; j++) {
      string t = s.substr(i, j);
      if (isacgt(t)) {
        ans = max(ans, j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}