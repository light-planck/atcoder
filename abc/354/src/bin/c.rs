use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        ac: [(i64, i64); n],
    }

    let mut aci = ac
        .into_iter()
        .enumerate()
        .map(|(i, (a, c))| (i, a, c))
        .collect::<Vec<_>>();
    aci.sort_by(
        |&(_, a1, c1), &(_, a2, c2)| {
            if a1 != a2 {
                a1.cmp(&a2)
            } else {
                c2.cmp(&c1)
            }
        },
    );

    println!("{:?}", aci);

    let mut ans = vec![];
    for i in 0..n - 1 {
        let (i1, a1, c1) = aci[i];
        let (_, a2, c2) = aci[i + 1];

        if a1 >= a2 || c1 >= c2 {
            ans.push(i1 + 1);
        }
    }
    ans.push(n);
    ans.sort_unstable();

    println!("{}", ans.len());
    println!("{}", ans.iter().join(" "));
}
