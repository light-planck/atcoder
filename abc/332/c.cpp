#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

struct TShirts {
  ll numbers;
  ll remaining;

  TShirts() : numbers(0), remaining(0) {}

  void purchase(ll n = 1) {
    numbers += n;
    remaining += n;
  }
  void use() { --remaining; }
  void clean() { remaining = numbers; }
};

int main() {
  ll N, M;
  cin >> N >> M;

  string S;
  cin >> S;

  TShirts t_shirts;
  t_shirts.purchase(M);

  TShirts t_shirts_with_logo;

  for (auto c : S) {
    if (c == '0') {
      t_shirts.clean();
      t_shirts_with_logo.clean();
    } else if (c == '1') {
      if (t_shirts.remaining > 0) {
        t_shirts.use();
      } else if (t_shirts_with_logo.remaining > 0) {
        t_shirts_with_logo.use();
      } else {
        t_shirts_with_logo.purchase();
        t_shirts_with_logo.use();
      }
    } else {
      if (t_shirts_with_logo.remaining > 0) {
        t_shirts_with_logo.use();
      } else {
        t_shirts_with_logo.purchase();
        t_shirts_with_logo.use();
      }
    }
  }

  cout << t_shirts_with_logo.numbers << '\n';
}
