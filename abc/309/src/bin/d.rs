use std::collections::VecDeque;

use proconio::{input, marker::Usize1};

fn main() {
    input! {
        (n1, n2, m): (usize, usize, usize),
        ab: [(Usize1, Usize1); m],
    }

    let mut edge: Vec<Vec<usize>> = vec![vec![]; n1 + n2];
    for (a, b) in ab {
        edge[a].push(b);
        edge[b].push(a);
    }

    let dist1 = bfs(&edge, 0);
    let dist2 = bfs(&edge, n1 + n2 - 1);
    let ans = dist1.into_iter().max().unwrap() + dist2.into_iter().max().unwrap() + 1;
    println!("{}", ans);
}

fn bfs(edge: &[Vec<usize>], start: usize) -> Vec<i64> {
    let mut que: VecDeque<usize> = VecDeque::from([start]);
    let mut dist: Vec<i64> = vec![-1; edge.len()];
    dist[start] = 0;

    while let Some(v) = que.pop_front() {
        for &u in &edge[v] {
            if dist[u] != -1 {
                continue;
            }

            dist[u] = dist[v] + 1;
            que.push_back(u);
        }
    }

    dist
}
