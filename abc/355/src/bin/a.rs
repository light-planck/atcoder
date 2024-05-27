use im_rc::HashSet;
use proconio::input;

fn main() {
    input! {
        (a, b): (i32, i32),
    }

    let mut st: HashSet<i32> = (1..=3).collect();
    st.remove(&a);
    st.remove(&b);

    let ans = if st.len() == 1 {
        st.into_iter().next().unwrap()
    } else {
        -1
    };

    println!("{}", ans);
}
