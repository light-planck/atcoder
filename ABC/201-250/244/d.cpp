#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;


/*
(r, g, b)からどれか2つを選び、奇数回だけ交換(互換)した場合、奇置換になる。
逆に偶数回互換すると偶置換になる。
奇置換：(g, r, b), (b, g, r), (r, b, g)
偶置換：(r, g, b), (g, b, r), (b, r, g)
*/


// sが(r, g, b)の偶置換かどうか
bool is_even(string s) {
  return s == "R G B" || s == "G B R" || s == "B R G";
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  getline(cin, s);

  string t;
  getline(cin, t);

  if (is_even(s) == is_even(t)) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}