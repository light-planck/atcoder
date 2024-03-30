use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i32,
    }

    for x in 0..n + 1 {
        for y in 0..n + 1 {
            for z in 0..n + 1 {
                if x + y + z <= n {
                    println!("{} {} {}", x, y, z);
                }
            }
        }
    }
}
