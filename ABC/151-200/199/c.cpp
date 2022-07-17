#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;

  string prev = s.substr(0, n);
  string next = s.substr(n);

  rep(i, q) {
    int t, a, b;
    cin >> t >> a >> b;
    a--; b--;

    if (t == 1) {
      if (b <= n-1) swap(prev[a], prev[b]);
      else if (a >= n) swap(next[a-n], next[b-n]);
      else swap(prev[a], next[b-n]);
    }
    if (t == 2) swap(prev, next);
  }

  cout << prev + next << endl;
  return 0;
}