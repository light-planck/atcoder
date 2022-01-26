#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

ll h, w, k;
void colorw(vector<string>& tmp, int j) {
  rep(i, h) {
    tmp[i][j] = '.';
  }
}

void colorh(vector<string>& tmp, int i) {
  rep(j, w) {
    tmp[i][j] = '.';
  }
}

int count_black(vector<string>& tmp) {
  int res = 0;
  rep(i, h) rep(j, w) if (tmp[i][j] == '#') ++res;
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  ll cnt = 0;
  for (int ibit = 0; ibit < (1 << h); ++ibit) {
    for (int jbit = 0; jbit < (1 << w); ++jbit) {
      vector<string> tmp = s;

      // j列の黒を塗りつぶす
      for (int j = 0; j < w; ++j) {
        if (jbit & (1 << j)) {
          colorw(tmp, j);
        }
      }

      // i行の黒を塗りつぶす
      for (int i = 0; i < h; ++i) {
        if (ibit & (1 << i)) {
          colorh(tmp, i);
        }
      }

      // 黒の個数をカウント
      int sum = count_black(tmp);

      if (sum == k) ++cnt;
    }
  }

  cout << cnt << "\n";
  return 0;
}