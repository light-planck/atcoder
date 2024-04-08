use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        xy: [(i64, i64); n],
    }

    for i in 0..n {
        let (x, y) = xy[i as usize];
        let mut max_dist = 0;
        let mut number = 0;

        for j in 0..n {
            if i == j {
                continue;
            }

            let (x2, y2) = xy[j as usize];
            let dist = (x - x2).pow(2) + (y - y2).pow(2);

            if dist > max_dist {
                max_dist = dist;
                number = j + 1;
            }
        }

        println!("{}", number);
    }
}
