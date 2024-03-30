use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i32,
        p:[i32; n],
        q: i32,
        ab: [(i32, i32); q],
    }

    for (a, b) in ab.into_iter() {
        for p in &p {
            if *p == a || *p == b {
                println!("{}", *p);
                break;
            }
        }
    }
}
