// 家から水源までの距離が近い座標を3つ記憶
// その中からcostが最小となるような水源まで掘削
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <queue>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct Pos {
  ll y, x;
  Pos(ll y=0, ll x=0) : y(y), x(x) {}
};


ll n, w, k, c;
vector<Pos> water;
vector<Pos> house;

ll total_cost = 0;
vector<vector<bool>> broken;
vector<vector<bool>> is_water;
vector<vector<ll>> sturdiness;
ll prev_sturdiness = 100;
ll destruct_times = 1;
ll power_bias = 15;
ll num_candidates = 3;
ll weight_dist = 50;


Pos idx2pos(ll i) {
  ll y = i/n;
  ll x = i%n;
  return Pos{y, x};
}
ll pos2idx(Pos pos) {
  return n*pos.y + pos.x;
}


// 1,2,4,8,16,32,64,128
void init_destruct_times() {
  if (c == 1) destruct_times = 20;  // ok
  if (c == 2) destruct_times = 10;  // ok
  if (c == 4) destruct_times = 7;  // ok
  if (c == 8) destruct_times = 6;  // ok
  if (c == 16) destruct_times = 6;  // ok
  if (c == 32) destruct_times = 4;  // ok
  if (c == 64) destruct_times = 3;  // ok
  if (c == 128) destruct_times = 2;  // ok
}


void init() {
  cin >> n >> w >> k >> c;
  broken = vector(n, vector<bool>(n, false));
  is_water = vector(n, vector<bool>(n, false));
  sturdiness = vector(n, vector<ll>(n, 0ll));
  init_destruct_times();
  rep(_, w) {
    ll a, b;
    cin >> a >> b;
    water.emplace_back(a, b);
    is_water[a][b] = true;
  }
  rep(_, k) {
    ll a, b;
    cin >> a >> b;
    house.emplace_back(a, b);
  }
}


void respond(ll y, ll x, ll power) {
  total_cost += power + c;
  cout << y << " " << x << " " << power << endl;
  ll r;
  cin >> r;
  if (r == -1) {
    cerr << "invalid: y=" << y << " x=" << x << endl;
    exit(1);
  }
  if (r == 0) return;
  if (r == 1) {
    broken[y][x] = true;
  }
  if (r == 2) {
    broken[y][x] = true;
    exit(0);
  }
}


bool check_yx(ll y, ll x) {
  if (y<0 or y>=n) return false;
  if (x<0 or x>=n) return false;
  return true;
}


void destruct(ll y, ll x, bool test=false) {
  if (broken[y][x]) return;
  if (not check_yx(y, x)) {
    cout << "# error: destruct function" << endl;
    cout << "# invalid position: y = " << y << ", x = " << x << endl;
  }

  ll times = 0;
  ll power = prev_sturdiness/destruct_times + power_bias;
  if (test) power = weight_dist;
  while (not broken[y][x]) {
    respond(y, x, power);
    ++times;
  }
  sturdiness[y][x] = prev_sturdiness = power*times;
}


void move(Pos start, Pos goal) {
  cout << "# move from (" << start.y << "," << start.x << ") to (" << goal.y << "," << goal.x << ")" << endl;

  // down/up
  if (start.y < goal.y) {
    for (int y = start.y; y < goal.y; y++) {
      destruct(y, start.x);
      is_water[y][start.x] = true;
    }
  } else {
    for (int y = start.y; y > goal.y; y--) {
      destruct(y, start.x);
      is_water[y][start.x] = true;
    }
  }

  // right/left
  if (start.x < goal.x) {
    for (int x = start.x; x <= goal.x; x++) {
      destruct(goal.y, x);
      is_water[goal.y][x] = true;
    }
  } else {
    for (int x = start.x; x >= goal.x; x--) {
      destruct(goal.y, x);
      is_water[goal.y][x] = true;
    }
  }
}


void solve() {
  vector<ll> near_water(k);  // 家とのマンハッタン距離が最小をとる水源のidx
  vector<ll> dist_to_water(k);  // 家から水源までのマンハッタン距離の最小値

  // 各家から各水源までの最小のマンハッタン距離を求める
  rep(i, k) {
    ll dist = 1ll << 60;
    ll water_idx = 0;
    rep(j, w) {
      ll d = abs(house[i].y - water[j].y) + abs(house[i].x - water[j].x);
      if (d < dist) {
        dist = d;
        water_idx = j;
      }
    }
    near_water[i] = water_idx;
    dist_to_water[i] = dist;
  }

  // 家i(y, x)からマンハッタン距離がdist以下で最短の水源・水路(ny, nx)を指定したサイズ分探索
  auto search_water = [&](ll hi) -> pair<Pos, ll> {
    // (水源までの距離dist, 水源のidx)を指定したサイズまで記憶
    vector<pair<ll, ll>> candidates;

    auto push = [&](ll d, ll idx) {
      candidates.emplace_back(d, idx);
      sort(candidates.begin(), candidates.end());
      while ((ll)candidates.size() > num_candidates) {
        candidates.pop_back();
      }
    };

    auto get_syx = [&](Pos to) -> pair<ll, ll> {
      cout << "# compare cost" << endl;
      auto [y, x] = house[hi];
      if (not broken[(to.y+y) / 2][x]) destruct((to.y+y) / 2, x, true);
      if (not broken[to.y][(to.x+x) / 2]) destruct(to.y, (to.x+x) / 2, true);
      ll sy = sturdiness[(to.y+y) / 2][x]; ll sx = sturdiness[to.y][(to.x+x) / 2];
      return {sy, sx};
    };

    auto calculate_min_cost = [&]() -> pair<ll, Pos> {
      ll min_cost = 1ll << 60;
      ll idx = 0;
      for (auto [dist, i] : candidates) {
        auto [y, x] = house[hi];
        auto [sy, sx] = get_syx(idx2pos(i));
        ll cost = weight_dist*dist + sx+sy;
        if (cost < min_cost) {
          min_cost = cost;
          idx = i;
        }
      }
      return pair<ll, Pos>{min_cost, idx2pos(idx)};
    };

    push(dist_to_water[hi], pos2idx(Pos{water[near_water[hi]].y, water[near_water[hi]].x}));  // 家から最短の水源を設定

    // (y, x)からd以下のマンハッタン距離の点(ny, nx)に水路があるか確認
    for (ll dy = -dist_to_water[hi]; dy <= dist_to_water[hi]; ++dy) {
      for (ll dx = -dist_to_water[hi]; dx <= dist_to_water[hi]; ++dx) {
        auto [y, x] = house[hi];
        ll ny = y+dy; ll nx = x+dx;
        ll d = abs(dy)+abs(dx);

        if (d > dist_to_water[hi]) continue;
        if (not check_yx(ny, nx)) continue;
        if (not is_water[ny][nx]) continue;

        push(d, pos2idx(Pos{ny, nx}));
      }
    }

    ll dist; Pos to;
    tie(dist, to) = calculate_min_cost();
    return {to, dist};
  };

  unordered_set<ll> rem_house;
  rep(i, k) rem_house.emplace(i);

  auto get_house_to_water = [&]() -> pair<ll, Pos> {
    vector<pair<ll, ll>> dist_from;
    vector<Pos> from_to(k);
    rep(i, k) {
      if (not rem_house.count(i)) continue;
      auto [to, dist] = search_water(i);
      dist_from.emplace_back(dist, i);
      from_to[i] = to;
    }
    sort(dist_from.begin(), dist_from.end());
    auto [_, i] = dist_from[0];
    Pos to = from_to[i];
    return {i, to};
  };

  while (not rem_house.empty()) {
    ll i = 0; Pos to;
    tie(i, to) = get_house_to_water();
    move(house[i], to);
    rem_house.erase(i);
  }
}


int main() {
  init();
  solve();
  return 0;
}