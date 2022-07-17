#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string s, t;
  cin >> s >> t;
  int len = s.size();
  bool can = false;

  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }

  for (int i = 0; i < len-1; i++) {
    string u = s;
      swap(u[i], u[i + 1]);
      if (u == t) can = true;
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}