#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int x;
  cin >> x;
  if (x < 40) cout << 40 - x << endl;
  else if (x < 70) cout << 70 - x << endl;
  else if (x < 90) cout << 90 - x << endl;
  else cout << "expert" << endl;
  return 0;
}