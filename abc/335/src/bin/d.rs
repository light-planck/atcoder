use proconio::{fastout, input};

struct Pos {
    i: usize,
    j: usize,
}

#[fastout]
fn main() {
    input! {
        n: usize,
    }

    let mut s: Vec<Vec<String>> = vec![vec![String::from(""); n]; n];
    let mut dir = 0;
    let dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)];
    let mut seen: i64 = 1;
    let mut pos = Pos { i: 0, j: 0 };

    while seen < n as i64 * n as i64 {
        let Pos { i, j } = pos;
        s[i][j] = seen.to_string();

        loop {
            let (di, dj) = dirs[dir];
            let (ni, nj) = (i as i64 + di, j as i64 + dj);

            if ni < 0
                || nj < 0
                || ni >= n as i64
                || nj >= n as i64
                || s[ni as usize][nj as usize] != ""
            {
                dir = (dir + 1) % 4;
            } else {
                pos = Pos {
                    i: ni as usize,
                    j: nj as usize,
                };
                break;
            }
        }

        seen += 1;
    }

    for row in &s {
        println!(
            "{}",
            row.iter()
                .map(|x| if x != "" {
                    x.to_string()
                } else {
                    "T".to_string()
                })
                .collect::<Vec<String>>()
                .join(" ")
        );
    }
}
