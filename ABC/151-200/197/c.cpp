#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  vector<int> a(n);
  cin >> n;
  rep(i, n) cin >> a[i];
  int ans = 1 << 30;

  //a[n-1], a[n-2], ... a[0]から空でない連続した区間に分ける
  //n個の要素の間に仕切りを入れるか入れないかの2 ^ n-1通りある
  //3, 2 | 1, 0のときbit = 010
  for (int bit = 0; bit < (1 << n - 1); bit++) {

    //xor
    int bxor = 0;

    //区間内ビットor
    int tmp = 0;

    //n桁のビット列でビットが立っているものを検知
    for (int i = 0; i < n; i++) {
      tmp |= a[i];

      //i桁のビットが立っているとき
      //そこで区間が区切られる
      if (bit & (1 << i)) {
        
        //区間内ビットorにxorをとる
        bxor ^= tmp;
        tmp = 0;
      }
    }

    //xor
    //区間の端の分もxorをとる必要がある
    //4, 3 | 2 | 1のときのtmp(4, 3)のxorを取る必要がある
    bxor ^= tmp;
    ans = min(ans, bxor);
  }

  cout << ans << endl;
  return 0;
}