#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

bool solve(string s) {
  bool ok = false;
  if (s.size() == 1) {
    if (s == "8") ok = true;
    return ok;
  }

  else if (s.size() == 2) {
    int x = stoi(s);
    swap(s[0], s[1]);
    int y = stoi(s);
    if (x % 8 == 0) ok = true;
    if (y % 8 == 0) ok = true;
    return ok;
  }

  else {
    vector<int> dig(10);
    rep(i, s.size()) dig[s[i] - '0']++;
    for (int i = 0; i < 1000; i += 8) {
      if (i < 100) continue;
      vector<int> tmp(10);
      int d = i;
      rep(j, 3) {
        tmp[d % 10]++;
        d /= 10;
      }
      bool ok = true;
      rep(j, 10) if (tmp[j] > dig[j]) ok = false;
      if (ok) return true;
    }
    return false;
  }
}

int main() {
  string s;
  cin >> s;
  if (solve(s)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}