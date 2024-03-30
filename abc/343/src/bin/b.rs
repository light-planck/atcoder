use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i32,
        a: [[i32; n]; n],
    }

    for row in a {
        for (idx, &ai) in row.iter().enumerate() {
            if ai == 1 {
                print!("{} ", idx + 1);
            }
        }
        println!();
    }
}
