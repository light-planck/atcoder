#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  vector<string> s(3);
  rep(i, 3) cin >> s[i];

  // sに含まれる文字のsetとcharsを作成
  set<char> st;
  vector<char> chars;
  rep(i, 3) {
    for (auto c : s[i]) {
      if (st.count(c)) continue;

      st.insert(c);
      chars.emplace_back(c);
    }
  }

  // 出現する文字が11種類ならば数字の0~9の10種類を超えてしまう
  if (st.size() >= 11) {
    cout << "UNSOLVABLE" << "\n";
    return 0;
  }

  // next_permutationで数字と文字の対応関係を作成
  vector<ll> perm(10);
  iota(rng(perm), 0);

  do {
    ll len_char = chars.size();

    // 文字と数字の対応関係を求める
    map<char, ll> char_num;
    rep(i, len_char) char_num[chars[i]] = perm[i];

    // sを数字の文字列tに変換
    vector<string> t(3);
    bool ng = false;
    rep(i, 3) {
      ll j = 0;
      string tmp;

      for (auto c : s[i]) {
        ll num = char_num[c];
        if (j == 0 and num == 0) ng = true;

        tmp += '0' + num;

        ++j;
      }

      t[i] = tmp;
    }

    // 先頭に0がつくときは飛ばす
    if (ng) continue;

    vector<ll> n(3);
    rep(i, 3) n[i] = stoll(t[i]);

    // それをもとにn1 + n2 = n3か判定
    if (n[0] + n[1] == n[2]) {
      rep(i, 3) cout << n[i] << "\n";
      return 0;
    }

  } while (next_permutation(rng(perm)));

  // 見つからなければng
  cout << "UNSOLVABLE" << "\n";
  return 0;
}