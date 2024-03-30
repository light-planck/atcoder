use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i32,
        mut a: [i32; n],
        st: [(i32, i32); n-1],
    }

    for (i, (s, t)) in st.into_iter().enumerate() {
        if a[i] >= s {
            a[i + 1] += t * (a[i] / s);
            a[i] -= s * (a[i] / s);
        }
    }

    println!("{}", a.last().unwrap());
}
