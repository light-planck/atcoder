#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;
  for (int k = 0; k <= 26; k++) {
    string tmp = s;
    rep(i, s.size()) {
      tmp[i] = 'a' + (s[i] - 'a' + k) % 26;
    }
    if (tmp == t) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}