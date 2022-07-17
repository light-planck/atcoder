#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int CalcScore(string s) {
  // カードの枚数を管理
  vector<int> cards(10);
  for (char c : s) {
    ++cards[c - '0'];
  }

  int score = 0;
  for (int i = 1; i <= 9; ++i) {
    int c = 1;
    rep(j, cards[i]) c *= 10;

    score += i * c;
  }

  return score;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll k;
  cin >> k;

  string s, t;
  cin >> s >> t;

  // 残りのカードの枚数
  vector<ll> cards(10, k);
  cards[0] = 0;
  rep(i, 4) --cards[s[i] - '0'];
  rep(i, 4) --cards[t[i] - '0'];

  // score(s) > score(t)となる場合の数を求める
  // s[4] = a, t[4] = b, 1 <= a, b <= 9として全探索する
  ll win_cnt = 0;
  for (int a = 1; a <= 9; ++a) {
    for (int b = 1; b <= 9; ++b) {
      s[4] = '0' + a;
      t[4] = '0' + b;

      // score(s) <= score(t)の場合はスキップ
      if (CalcScore(s) <= CalcScore(t)) continue;

      // cout << CalcScore(s) << " " << CalcScore(t) << endl;
      if (a == b) {
        win_cnt += cards[a] * (cards[a] - 1);
      }
      else {
        win_cnt += cards[a] * cards[b];
      }
    }
  }

  // 全事象
  ll whole = (9 * k - 8) * (9 * k - 9);

  double ans = (double)win_cnt / whole;
  printf("%.10f\n", ans);
  return 0;
}