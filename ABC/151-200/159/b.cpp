#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  string res = s;
  reverse(res.begin(), res.end());
  string t = s.substr(0, (s.size() - 1) / 2);
  string ret = t;
  reverse(ret.begin(), ret.end());
  string u = s.substr((s.size() + 3) / 2 - 1);
  string reu = u;
  reverse(reu.begin(), reu.end());
  bool ans = true;

  if (res != s) ans = false;
  if (ret != t) ans = false;
  if (reu != u) ans = false;
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}