#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  string s;
  cin >> s;
  string t = s;
  reverse(all(t));

  int cnt1 = 0;
  int cnt2 = 0;
  int n = s.size();

  rep(i, n - 1) {
    if (s[i] == s[i + 1]) {
      cnt1++;
      if (s[i + 1] == '0') s[i + 1] = '1';
      else s[i + 1] = '0';
    }
  }

  rep(i, n - 1) {
    if (t[i] == t[i + 1]) {
      cnt2++;
      if (t[i + 1] == '0') t[i + 1] = '1';
      else t[i + 1] = '0';
    }
  }

  cout << min(cnt1, cnt2) << endl;
  return 0;
}