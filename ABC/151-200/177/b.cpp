#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s, t;
  cin >> s >> t;
  int ans = 0;
  for (int i = 0; i <= s.size() - t.size(); i++){
    int cnt = 0;
    string u = s.substr(i, t.size());
    for (int j = 0; j < u.size(); j++){
      if (u[j] == t[j]) cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << t.size() - ans << endl;
}