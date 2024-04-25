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

    const DIRS: [(i64, i64); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

    let is_valid_pos =
        |i: i64, j: i64| -> bool { i >= 0 && j >= 0 && i < n as i64 && j < n as i64 };

    let get_nij = |pos: &Pos, dir: usize| -> (i64, i64) {
        let Pos { i, j } = pos;
        let (di, dj) = DIRS[dir];
        (*i as i64 + di, *j as i64 + dj)
    };

    let mut s: Vec<Vec<String>> = vec![vec![String::from(""); n]; n];
    let mut dir = 0;
    let mut seen: i64 = 1;
    let mut pos = Pos { i: 0, j: 0 };

    while seen < (n * n) as i64 {
        let Pos { i, j } = pos;
        s[i][j] = seen.to_string();

        loop {
            let (ni, nj) = get_nij(&pos, dir);

            if is_valid_pos(ni, nj) && s[ni as usize][nj as usize] == "" {
                pos = Pos {
                    i: ni as usize,
                    j: nj as usize,
                };
                break;
            } else {
                dir = (dir + 1) % 4;
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
