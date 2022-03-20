#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


/*
楽しさが正の数のとき乗ればよい。

kが十分大きいとき、
アトラクションiの楽しさは
ai, ai-1, ai-2, ..., 2, 1
の値を取りうるので


ex.
楽しさ: (3, 8, 5)
3, 2, 1
8, 7, 6, 5, 4, 3, 2, 1
5, 4, 3, 2, 1
この数をすべて合わせて昇順に並び替えて、
大きい数からk個選べばよい。
*/


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];


  return 0;
}