use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i32,
        xy: [(i32, i32); n],
    }

    let (x, y): (Vec<i32>, Vec<i32>) = xy.into_iter().unzip();

    let diff = x.iter().sum::<i32>() - y.iter().sum::<i32>();
    if diff > 0 {
        println!("Takahashi");
    } else if diff < 0 {
        println!("Aoki");
    } else {
        println!("Draw");
    }
}
