#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string x;
  cin >> x;
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  //a, b, c, ... が新たなアルファベットでは何番目か
  //を示す配列al[]を作成
  int al[26];
  //al[0] : a, al[1] : b, ...
  rep(i, 26) {
    al[x[i] - 'a'] = i;
  }
  
  vector<string> t(n);
  
  //s1, s2, ...の各文字を番号に応じて
  //元のアルファベットに変換し
  //それをt1, t2...などとする
  rep(i, n) {
    int len = s[i].size();
    rep(j, len) {
      //元の順番では何番目か
      int idx = s[i][j] - 'a';
      //新しい番号
      int newidx = al[idx];
      //文字を変換
      char c = newidx + 'a';
      t[i].push_back(c);
    }
  }
  
  //pair<t1, s1>としてソート
  vector<pair<string, string>> p(n);
  rep(i, n) {
    p[i] = make_pair(t[i], s[i]);
  }
  sort(all(p));

  //その順にs1を出力
  for (auto x : p) {
    cout << x.second << endl;
  }
  return 0;
}