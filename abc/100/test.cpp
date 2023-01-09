#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  auto count = [](ll x) {
      ll res = 0;
      while (x%100 == 0) {
        ++res;
        x /= 100;
      }

      if (x) return 0ll;
      else return res;
    };

  cout << count(1000) << '\n';
  return 0;
}