use im_rc::HashSet;
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        k: i64,
        a: [i64; n],
    }

    let mut st: HashSet<i64> = HashSet::new();
    for a in a {
        if 1 <= a && a <= k {
            st.insert(a);
        }
    }

    let sub = st.into_iter().sum::<i64>();
    let ans = k * (k + 1) / 2 - sub;

    println!("{}", ans);
}
