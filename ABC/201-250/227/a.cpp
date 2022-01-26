#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, k, a;
  cin >> n >> k >> a;

  int now = a;
  while (k > 0) {
    k--;
    if (k == 0) {
      cout << now << endl;
      return 0;
    }
    now++;
    if (now > n) now = 1;
  }
  
  cout << now << endl;
  return 0;
}