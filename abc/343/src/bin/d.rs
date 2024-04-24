use im_rc::{HashMap, HashSet};
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        (n, t) : (usize, usize),
        ab: [(usize, i64); t],
    }

    let mut points = vec![0; n];
    let mut cnt: HashMap<i64, i64> = HashMap::from(vec![(0, n as i64)]);
    let mut st: HashSet<i64> = HashSet::from(vec![0]);

    for (a, b) in ab.iter() {
        let prev_point = points[a - 1];
        let now_point = prev_point + b;

        cnt[&prev_point] -= 1;
        if cnt[&prev_point] == 0 {
            st.remove(&prev_point);
        }

        cnt.entry(now_point).and_modify(|v| *v += 1).or_insert(1);
        points[a - 1] = now_point;
        st.insert(now_point);

        println!("{}", st.len());
    }
}
