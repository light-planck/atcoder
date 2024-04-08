use im_rc::HashSet;
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        a: [i64; n],
        m: i64,
        b: [i64; m],
        l: i64,
        c: [i64; l],
        q: i64,
        x: [i64; q],
    }

    let mut st: HashSet<i64> = HashSet::new();
    for i in 0..n {
        for j in 0..m {
            for k in 0..l {
                let (i, j, k) = (i as usize, j as usize, k as usize);
                st.insert(a[i] + b[j] + c[k]);
            }
        }
    }

    for x in x {
        match st.contains(&x) {
            true => println!("Yes"),
            false => println!("No"),
        }
    }
}
