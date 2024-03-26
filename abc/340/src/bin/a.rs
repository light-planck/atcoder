use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        a: i32,
        b: i32,
        d: i32,
    }

    let mut c = a;
    while c <= b {
        print!("{} ", c);
        c += d;
    }
    println!("");
}
