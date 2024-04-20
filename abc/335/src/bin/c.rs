use proconio::{fastout, input};
use std::collections::VecDeque;

#[fastout]
fn main() {
    input! {
        (n, q): (i64, i64),
    }

    let mut deq: VecDeque<(i64, i64)> =
        VecDeque::from((0..n).map(|i| (i + 1, 0)).collect::<Vec<(i64, i64)>>());

    for _ in 0..q {
        input! {
            t: i64,
        }

        match t {
            1 => {
                input! {
                    c: char,
                }

                let (di, dj) = get_dij(c);
                let (hi, hj) = deq.front().unwrap();

                deq.push_front((hi + di, hj + dj));
                deq.pop_back();
            }
            2 => {
                input! {
                    p: usize,
                }

                let (i, j) = deq[p - 1];
                println!("{} {}", i, j);
            }
            _ => unreachable!(),
        }
    }
}

fn get_dij(c: char) -> (i64, i64) {
    match c {
        'L' => (-1, 0),
        'R' => (1, 0),
        'U' => (0, 1),
        'D' => (0, -1),
        _ => unreachable!(),
    }
}
