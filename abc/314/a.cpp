#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  string s =
      "3."
      "141592653589793238462643383279502884197169399375105820974944592307816406"
      "2862089986280348253421170679";

  ll N;
  cin >> N;

  cout << s.substr(0, N + 2) << '\n';
}
