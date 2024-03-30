use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        q: i32,
        queries: [(i32, i32); q],
    }

    let mut a: Vec<i32> = vec![];
    for (t, x) in queries {
        if t == 1 {
            a.push(x);
        } else {
            println!("{}", a[a.len() - x as usize]);
        }
    }
}
