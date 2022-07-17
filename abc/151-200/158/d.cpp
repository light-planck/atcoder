#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  string s;
  cin >> s;
  deque<char> dq;
  rep(i, s.size()) dq.push_back(s[i]);
  int q;
  cin >> q;
  bool rev = false;
  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      if (rev) rev = false;
      else rev = true;
    }
    else if (t == 2) {
      int f;
      cin >> f;
      char c;
      cin >> c;

      // 先頭追加
      if (f == 1) {
        // 反転していたら末尾
        if (rev) dq.push_back(c);

        // していないなら先頭
        else dq.push_front(c);
      }

      // 末尾追加
      else if (f == 2) {
        if (rev) dq.push_front(c);
        else dq.push_back(c);
      }
    }
  }
  if (rev) reverse(all(dq));
  for (auto c : dq) cout << c;
  cout << endl;
  return 0;
}