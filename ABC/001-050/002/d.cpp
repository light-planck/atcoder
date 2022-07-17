#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> xy(m);
  rep(i, m) cin >> xy[i].first >> xy[i].second;

  //n人の議員を派閥に選ぶか選ばないかで2^n通りある
  for (int bit = 0; bit < (1 << n); bit++) {
    // a
  }
  return 0;
}

/*
n = 4, bit = 0101のとき、0と2番目の人が知り合い
xy = (0, 1), (1, 2)のとき、(0, 2)は知り合いとなる
*/