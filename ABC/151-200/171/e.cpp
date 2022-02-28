#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a[i];
  
  int s = 0;
  rep(i, n) s ^= a[i];

  rep(i, n) {
    int x = s ^ a[i];
    cout << x << "\n";
  }
  return 0;
}