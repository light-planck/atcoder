use proconio::input;

fn main() {
    input! {
        (_, x, y, z): (usize, usize, usize, usize),
    }

    let ans = (x..=y).contains(&z) || (y..=x).contains(&z);
    println!("{}", if ans { "Yes" } else { "No" });
}
