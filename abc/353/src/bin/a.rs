use proconio::input;

fn main() {
    input! {
        n: usize,
        h: [i32; n],
    }

    let left = h[0];
    for i in 1..n {
        if h[i] > left {
            println!("{}", i + 1);
            return;
        }
    }

    println!("-1");
}
