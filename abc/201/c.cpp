#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  int ans = 0;

  for (int i = 0; i < 10000; i++) {

    //iの各桁ごとにどんな数字が存在することを示す配列
    vector<bool> b(10, false);
    int n = i;
    rep(i, 4) {
      int d = n % 10;
      b[d] = true;
      n /= 10;
    }

    bool ok = true;
    rep(i, 10) {
      if (s[i] == 'o' && b[i] == false) ok = false;
      if (s[i] == 'x' && b[i] == true) ok = false;
    }
    if (ok) ans++;
  }

  cout << ans << endl;
  return 0;
}