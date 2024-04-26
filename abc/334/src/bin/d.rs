use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        (n, q): (usize, usize),
        mut r: [i64; n],
        queries: [i64; q],
    }

    r.sort_unstable();

    let cusum: Vec<i64> = r
        .into_iter()
        .scan(0, |acc, x| {
            *acc += x;
            Some(*acc)
        })
        .collect();

    for query in queries {
        let idx = cusum.partition_point(|x| x <= &query);
        println!("{}", idx);
    }
}
