// 掘削を終えるごとに、家から水源までの距離を求め、小さいものから掘削
// 岩盤の硬さに応じてpowerを変更
// 岩盤の硬さを記憶しておき、二つの掘削経路
// (→, ↓)　or (↓, →)のうち、コストが最小になるような経路で掘削する
#include <bits/stdc++.h>
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
ll prev_sturdiness = 100;
ll destruct_times = 1;
ll power_bias = 15;
vector<vector<ll>> sturdiness;


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
  sturdiness = vector(n, vector<ll>(n, 0ll));
  init_destruct_times();
  rep(_, w) {
    ll a, b;
    cin >> a >> b;
    water.emplace_back(a, b);
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
    // cerr << "C = " << c << endl;
    // cerr << c << endl;
    exit(0);
  }
}


void destruct(ll y, ll x) {
  if (broken[y][x]) return;

  ll times = 0;
  ll power = prev_sturdiness/destruct_times + power_bias;
  while (not broken[y][x]) {
    respond(y, x, power);
    ++times;
  }
  sturdiness[y][x] = prev_sturdiness = power*times;
}


// 岩盤の硬さの総和が小さい方の経路で掘削する
void move_min_cost(Pos start, Pos goal) {
  // up-down -> left-right
  auto cost0 = [&]() -> ll {
    ll cost = 0;
    auto [Y, X] = start;

    // down/up
    if (start.y < goal.y) {
      for (int y = start.y; y < goal.y; y++) {
        cost += sturdiness[y][X];
      }
    }
    else {
      for (int y = start.y; y > goal.y; y--) {
        cost += sturdiness[y][X];
      }
    }
    Y = goal.y;

    // right/left
    if (start.x < goal.x) {
      for (int x = start.x; x <= goal.x; x++) {
        cost += sturdiness[Y][x];
      }
    }
    else {
      for (int x = start.x; x >= goal.x; x--) {
        cost += sturdiness[Y][x];
      }
    }
    return cost;
  };

  // left-right -> up-down
  auto cost1 = [&]() {
    ll cost = 0;
    auto [Y, X] = start;

    // right/left
    if (start.x < goal.x) {
      for (int x = start.x; x <= goal.x; x++) {
        cost += sturdiness[Y][x];
      }
    }
    else {
      for (int x = start.x; x >= goal.x; x--) {
        cost += sturdiness[Y][x];
      }
    }
    X = goal.x;

    // down/up
    if (start.y < goal.y) {
      for (int y = start.y; y < goal.y; y++) {
        cost += sturdiness[y][X];
      }
    }
    else {
      for (int y = start.y; y > goal.y; y--) {
        cost += sturdiness[y][X];
      }
    }
    return cost;
  };

  if (cost0() < cost1()) {
    // down/up
    if (start.y < goal.y) {
      for (int y = start.y; y < goal.y; y++) {
        destruct(y, start.x);
      }
    }
    else {
      for (int y = start.y; y > goal.y; y--) {
        destruct(y, start.x);
      }
    }

    // right/left
    if (start.x < goal.x) {
      for (int x = start.x; x <= goal.x; x++) {
        destruct(goal.y, x);
      }
    }
    else {
      for (int x = start.x; x >= goal.x; x--) {
        destruct(goal.y, x);
      }
    }
  }
  else {
    // right/left
    if (start.x < goal.x) {
      for (int x = start.x; x <= goal.x; x++) {
        destruct(goal.y, x);
      }
    }
    else {
      for (int x = start.x; x >= goal.x; x--) {
        destruct(goal.y, x);
      }
    }

    // down/up
    if (start.y < goal.y) {
      for (int y = start.y; y < goal.y; y++) {
        destruct(y, start.x);
      }
    }
    else {
      for (int y = start.y; y > goal.y; y--) {
        destruct(y, start.x);
      }
    }
  }
}


void move(const Pos& start, const Pos& goal) {
  cout << "# move from (" << start.y << "," << start.x << ") to (" << goal.y << "," << goal.x << ")" << endl;

  move_min_cost(start, goal);
}


bool check_yx(ll y, ll x) {
  if (y<0 or y>=n) return false;
  if (x<0 or x>=n) return false;
  return true;
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

  // 家i(y, x)からマンハッタン距離がdist以下で最短の水源・水路(ny, nx)を探索
  auto search_water = [&](ll i) -> pair<Pos, ll> {
    Pos to = {water[near_water[i]].y, water[near_water[i]].x};
    ll dist = dist_to_water[i];
    // (y, x)からd以下のマンハッタン距離の点(ny, nx)に水路があるか確認
    for (ll dy = -dist; dy <= dist; ++dy) {
      for (ll dx = -dist; dx <= dist; ++dx) {
        auto [y, x] = house[i];
        ll ny = y+dy; ll nx = x+dx;

        if (abs(dy)+abs(dx) > dist) continue;
        if (not check_yx(ny, nx)) continue;
        if (not broken[ny][nx]) continue;

        if (abs(dy)+abs(dx) < dist) {
          dist = abs(dy) + abs(dx);
          to = {ny, nx};
        }
      }
    }
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
    auto [i, to] = get_house_to_water();
    move(house[i], to);
    rem_house.erase(i);
  }
}


int main() {
  init();
  solve();
  return 0;
}