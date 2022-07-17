#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n), x(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin>> q[i];
  rep(i, n) x[i] = i + 1;
  int a, b;

  //x[n] = 1, 2, ... nを順列全列挙する
  //そのうちx = p or qとなるidxを探す
  int idx = 1;
  do {
    bool samep = true;
    bool sameq = true;
    rep(i, n) {
      if (x[i] != p[i]) samep = false;
      if (x[i] != q[i]) sameq = false;
    }
    if (samep) a = idx;
    if (sameq) b = idx;
    idx++;
  } while (next_permutation(all(x)));

  cout << abs(b - a) << endl;
  return 0;
}