#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, q;
  string str;
  cin >> n >> q;
  cin >> str;

  // 累積和
  vector<int> s(n+1);
  rep(i, n - 1) {
    if (str[i] == 'A' && str[i + 1] == 'C') s[i + 1] = s[i] + 1;
    else s[i + 1] = s[i];
  }

  // クエリ
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout << s[r] - s[l] << endl;
  }
  return 0;
}