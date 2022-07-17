#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// li < lj < lkを満たす(i, j, k)の組を求めたい。
// ソートすればli < li+1が保証される。
// i < j < kとする。
// li, lj, lkが三角形をなすためには
// |li - lj| < lk < li + lj
// を満たさなければならない。
// ソートしてあるため、lj - li < lkは常に成立する。
// ゆえに条件はlk < li + ljのみでよい。
// idx = lower_bound(all(l). li + lj) - l.begin()
// とすれば、lのなかで、li + lj以上を満たす最小のインデックス
// つまり、lidx >= li + ljが
// 返されるので、求める個数は[j + 1, idx)
// 0, 1, ..., i, ..., j, j+1, ..., idx, ..., n - 1
                    //   <  ans    >

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> l(n);
  rep(i, n) cin >> l[i];
  sort(all(l));

  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int idx = lower_bound(all(l), l[i] + l[j]) - l.begin();
      int sum_k = idx - (j + 1);
      cnt += sum_k;
    }
  }

  cout << cnt << "\n";
  return 0;
}