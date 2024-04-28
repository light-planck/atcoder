use proconio::input;

fn main() {
    input! {
        a: [i64; 9],
        b: [i64; 8],
    }

    let ans = (a.into_iter().sum::<i64>() - b.into_iter().sum::<i64>() + 1).max(0);
    println!("{}", ans);
}
