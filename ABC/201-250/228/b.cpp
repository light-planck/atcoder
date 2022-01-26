#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, x;
  cin >> n >> x;
  x--;
  
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }

  vector<bool> b(n, false);

  int i = x;
  do {
    b[i] = true;
    i = a[i];
  } while (!b[i]);

  int cnt = 0;
  rep(i, n) if (b[i]) cnt++;
  cout << cnt << endl;
  return 0;
}