use proconio::input;

fn main() {
    input! {
        (n, k): (usize, usize),
        a: [usize; n],
    }

    let mut ans = 0;
    let mut now = 0;
    for a in a {
        if a + now <= k {
            now += a;
        } else {
            now = a;
            ans += 1;
        }
    }

    println!("{}", ans + 1);
}
