use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
    }

    let mut ans = 1;

    for i in 1..1e6 as i64 {
        let x = i * i * i;

        if x > n {
            break;
        }

        if x.to_string() == x.to_string().chars().rev().collect::<String>() {
            ans = x;
        }
    }

    println!("{}", ans);
}
