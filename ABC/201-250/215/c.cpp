#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = INT_MAX;
const int mod = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  sort(all(s));
  vector<string> t;
  do {
    t.push_back(s);
  } while (next_permutation(all(s)));
  cout << t[k-1] << endl;
  return 0;
}