use proconio::input;

fn main() {
    input! {
        n: usize,
        xy: [(usize, i64); n],
    }

    let mut dp: Vec<i64> = vec![0; 2];

    for (x, y) in xy {
        let prev = vec![dp[0], dp[1]];

        if x == 0 {
            dp[0] = (prev[0] + y).max(prev[0]);
            dp[0] = (prev[1] + y).max(prev[0]).max(dp[0]);
            dp[1] = (prev[0] + y).max(prev[1]);
        } else if x == 1 {
            dp[1] = (prev[0] + y).max(prev[1]);
        }
    }

    println!("{}", dp.into_iter().max().unwrap());
}
