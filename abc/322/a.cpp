#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  string S;
  cin >> S;

  if (S.find("ABC") == string::npos) {
    cout << -1 << '\n';
  } else {
    cout << S.find("ABC") + 1 << '\n';
  }
}
