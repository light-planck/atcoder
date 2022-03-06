#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


/*
[題意]
頂点1が根であり、n個の頂点からなる根付き木がある。
以下の2つの条件を満たすように、
n個の頂点一つずつに区間[l, r] (1 <= l <= r)を定める。
そのときのmax(l_1, l_2, ..., l_n, r_1, ..., r_n)が
最小となるようなn個の区間の組み合わせを求めたい。

(1)
頂点iからなる部分木とjからなる部分木が共通部分を持たない場合、
頂点iの区間[l_i, r_i]と頂点jの区間[l_j, r_j]は共通部分を持たない。
ex. (l_i <= r_i) < (l_j <= r_j)

(2)
頂点iからなる部分木が頂点jからなる部分木に含まれるとき
頂点iの区間[l_i, r_i]は頂点jの区間[l_j, r_j]に含まれる。
ex. l_j <= (l_i <= r_i) <= r_j


[考察]
頂点iとjが木の葉であるならば、それらの部分木はそれ自身のみからなるので
s_i and s_j = Noneであるから、頂点iとjの区間は条件(1)を満たさなければ
ならない。
条件を満たしながら、max(l_i, r_i, l_j, r_j)が最小値となる
区間の組み合わせは、どちらの区間もl = rを満たし、区間iと区間jの間が1と
なるような場合である。
ex. l_i = r_i, l_j = r_j, r_i + 1 = l_j

したがって、木の葉の個数をleaf_cntとすると、葉の[l, r]は
[l, r] = [1, 1], ..., [leaf_cnt, leaf_cnt]となる。

葉でない頂点jからなる部分木は葉である頂点jを含む。つまり
s_i (= s_jなのでiとjの区間は条件(2)を満たさなければならない。
よって、jの部分木に含まれるすべての葉のlの最小値をl_min、
rの最大値をr_maxとすれば、l_j = l_min, r_j = r_maxを満たす。

葉の個数をleaf_cnt = 1とし、根から行きがけ順で深さ優先探索する。
頂点に達したら、その区間のlをl = leaf_cntとする。また、
葉に達したら、その区間を[leaf_cnt, leaf_cnt]と定め、++leaf_cntとする。
そして、葉から戻ってきたらr = leaf_cntとする。
*/


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<vector<ll>> g(n);
  rep(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<ll> left(n);
  vector<ll> right(n);

  ll leaf_cnt = 1;

  auto dfs = [&](auto dfs, ll v, ll p) -> void {
    left[v] = leaf_cnt;

    for (auto nv : g[v]) {
      if (nv == p) continue;

      dfs(dfs, nv, v);
    }

    // 葉に達したら葉の個数を更新
    if (g[v].size() == 1 && p != -1) {
      ++leaf_cnt;
    }

    right[v] = leaf_cnt - 1;
  };

  dfs(dfs, 0, -1);
  rep(i, n) cout << left[i] << " " << right[i] << "\n";
  return 0;
}