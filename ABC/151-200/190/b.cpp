#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, s, d;
  cin >> n >> s >> d;
  bool can = false;

  rep(i, n){
    int x, y;
    cin >> x >> y;
    if (x < s && y > d){
      can = true;
    }
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}