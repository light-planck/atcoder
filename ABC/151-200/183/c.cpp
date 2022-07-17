#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, k;
  cin >> n >> k;
  int time[n][n];
  rep(i,n)rep(j,n) cin >> time[i][j];

  // 都市1, 2, ..., n-1
  vector<int> city;
  for (int i = 1; i < n; i++) city.push_back(i);
  int cnt = 0;

  do {
    int sum = 0;
    int now = 0;

    for (int i = 0; i < n-1; i++) {
      sum += time[now][city[i]];
      now = city[i];
    }

    sum += time[now][0];

    if (sum == k) cnt++;
  } while (next_permutation(all(city)));

  cout << cnt << endl;
  return 0;
}