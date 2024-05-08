use proconio::input;

fn main() {
    input! {
        n: usize,
        ab: [(i64, i64); n],
    }

    let mut ans = 0;
    let a_sum = ab.iter().map(|(a, _)| a).sum::<i64>();

    for (a, b) in ab {
        ans = ans.max(a_sum - a + b);
    }

    println!("{}", ans);
}
