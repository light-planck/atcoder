#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int q;
  cin >> q;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  ll s = 0;

  rep(i, q) {
    int p;
    cin >> p;
    ll x;

    if (p == 3) {
      x = que.top();
      que.pop();
      cout << x + s << endl;
    }
    else if (p == 1) {
      cin >> x;
      que.push(x - s);
    }
    else if (p == 2) {
      cin >> x;
      s += x;
    }
  }
  return 0;
}