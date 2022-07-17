#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h;
  cin >> h;

  ll cnt = 0;
  ll num = 1;
  while (h > 0) {
    cnt += num;
    num *= 2;
    h /= 2;
  }

  cout << cnt << "\n";
  return 0;
}