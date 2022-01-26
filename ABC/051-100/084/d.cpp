#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {

  //nの最大値
  int mx = 100010;

  //エラトステネスの篩
  bitset<100010> prime(0);
  for (int i = 2; i < mx; i++) prime.set(i);
  for (int i = 2; i <= sqrt(double(mx)); i++) {
    if (prime[i]) {

      //iの倍数をふるい落とす
      for (int j = i * 2; j < mx; j += i) {
        prime.reset(j);
      }
    }
  }

  //like 2017 numbers
  vector<int> a(mx);
  for (int i = 0; i < mx; i++) {
    if (prime[i] == 1 && prime[(i + 1) / 2] == 1) a[i] = 1;
  }

  //累積和
  //[l, r) = s[r] - s[l]
  vector<int> s(mx+1);
  rep(i, mx) s[i + 1] = s[i] + a[i];

  //クエリ処理
  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    r++;
    cout << s[r] - s[l] << endl;
  }
  
  return 0;
}