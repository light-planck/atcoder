#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;

int main() {
  vector<string> s(4);
  rep(i, 4) cin >> s.at(i);
  vector<string> d = {"H", "2B", "3B", "HR"};
  bool ans = false;

  ans = s.at(0) != s.at(1) && s.at(0) != s.at(2) && s.at(0) != s.at(3)
  && s.at(1) != s.at(2) && s.at(1) != s.at(3) && s.at(2) != s.at(3);

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}