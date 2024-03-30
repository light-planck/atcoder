use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: usize,
        mut a: [i64; n],
        st: [(i64, i64); n-1],
    }

    for (i, (s, t)) in st.into_iter().enumerate() {
        a[i + 1] += a[i] / s * t;
    }

    println!("{}", a.last().unwrap());
}
