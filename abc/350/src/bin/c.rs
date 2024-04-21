use im_rc::HashMap;
use proconio::{fastout, input};
use std::mem::swap;

#[fastout]
fn main() {
    input! {
        n: usize,
        mut a: [i64; n],
    }

    let mut pos: HashMap<i64, usize> = HashMap::from(
        a.iter()
            .enumerate()
            .map(|(i, &x)| (x, i))
            .collect::<Vec<_>>(),
    );
    let mut ans: Vec<(usize, usize)> = vec![];

    for target in 1..=n as i64 {
        let mut i = *pos.get(&target).unwrap();
        let mut j = (target - 1) as usize;

        if i == j {
            continue;
        }

        if i >= j {
            swap(&mut i, &mut j);
        }

        ans.push((i + 1, j + 1));
        a.swap(i, j);
        pos.insert(a[i], i);
        pos.insert(a[j], j);
    }

    println!("{}", ans.len());
    for (i, j) in ans {
        println!("{} {}", i, j);
    }
}
