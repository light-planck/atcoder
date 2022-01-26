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
  int n = s.size();

  map<int, int> mp;
  rep(i, n) mp[(s[i] - '0') % 3]++;

  int sum = 0;
  rep(i, 3) sum += mp[i] * i;

  int ans = inf;

  rep(i1, 3)rep(i2, 3) {

    // 消す個数が文字列の長さ以上
    // 1, 2の消す回数がs[1], s[2]より大きいときスキップ
    if (i1 + i2 >= n || i1 > mp[1] || i2 > mp[2]) continue;

    int ns = sum;
    ns -= i1;
    ns -= i2 * 2;
    if (ns % 3 == 0) ans = min(ans, i1 + i2);
  }
  
  if (ans == inf) ans = -1;
  cout << ans << endl;
  return 0;
}

/*
　s[i] % 3の値の個数をmp[0~2]でカウントする。そしてその総和sumを取る。s[0]となる
ようなものは関係なくて、s[1], s[2]となるようなものを消す最小の回数を求める。
　s[1], s[2]を消す回数は0~2回であり、それらの組み合わせを試す。
*/