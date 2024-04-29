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

    let ans =
        bfs(&edge, 0).iter().max().unwrap() + bfs(&edge, n1 + n2 - 1).iter().max().unwrap() + 1;
    println!("{}", ans);
}

fn bfs(edge: &Vec<Vec<usize>>, start: usize) -> Vec<i64> {
    let mut que: VecDeque<usize> = VecDeque::from([start]);
    let mut dist: Vec<i64> = vec![-1; edge.len()];
    dist[start] = 0;

    while let Some(v) = que.pop_front() {
        for &u in &edge[v] {
            if dist[u] >= 0 {
                continue;
            }

            dist[u] = dist[v] + 1;
            que.push_back(u);
        }
    }

    dist
}
