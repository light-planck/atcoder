#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

// 素因数分解
vector<int> calpfact(int n) {
  vector<int> prime;
  if (n == 1) return prime;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    prime.push_back(i);
    if (n / i != i && n / i != i) prime.push_back(n / i);
  }
  sort(all(prime));

  if (prime.size() == 0) {
    prime.push_back(n);
    return prime;
  }
  else return prime;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // s[1] ~ s[m]
  // s[i]がaの約数に含まれるときfalse、そうでないときtrue
  vector<bool> s(m+1, true);
  s[0] = false;

  // 1 ~ mまでで確認した素因数
  vector<bool> flag(m+1, true);

  for (int i = 0; i < n; i++) {

    // 素因数取得
    vector<int> pfact = calpfact(a[i]);

    // 取得した素因数の倍数のsをfalse
    for (auto p : pfact) {
      if (flag[p]) {
        for (int q = p; q <= m; q += p) {
          s[q] = false;

          // 確認した素因数をfalse
          flag[q] = false;
        }
      }
    }
  }

  int cnt = 0;
  for (int i = 1; i <= m; i++) if(s[i]) cnt++;
  cout << cnt << endl;
  for (int i = 1; i <= m; i++) if(s[i]) cout << i << endl;
  return 0;
}