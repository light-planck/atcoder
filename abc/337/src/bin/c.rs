use std::collections::VecDeque;

use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: usize,
        a: [i64; n],
    }

    let mut edge: Vec<Vec<usize>> = vec![vec![]; n];
    let mut start = 0;
    for (i, a) in a.into_iter().enumerate() {
        if a == -1 {
            start = i;
        } else {
            edge[(a - 1) as usize].push(i);
        }
    }

    let mut b: Vec<usize> = vec![];
    let mut deq = VecDeque::new();
    deq.push_back(start);

    while let Some(v) = deq.pop_front() {
        b.push(v + 1);

        for to in &edge[v] {
            deq.push_back(*to);
        }
    }

    let ans = b
        .into_iter()
        .map(|v| v.to_string())
        .collect::<Vec<_>>()
        .join(" ");
    println!("{}", ans);
}
