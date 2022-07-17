#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
ll a, N;
const int kInf = 1e9;
int ans = kInf;

void dfs(ll n, int cnt) {
  if (n == N) {
    ans = min(ans, cnt);
    return;
  }
  else if (n > N) {
    return;
  }

  ++cnt;
  dfs(n * a, cnt);

  if (n >= 10 && n % 10 != 0) {
    string s = to_string(n);
    int len = s.size();

    if (len >= 2) {
      char c = s[len - 1];
      string t = s.substr(0, len - 1);
      t = c + t;
      ll y = stoi(t);
      dfs(y, cnt);
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> a >> N;

  dfs(1, 0);
  if (ans == kInf) cout << -1 << "\n";
  else cout << ans << "\n";
  return 0;
}