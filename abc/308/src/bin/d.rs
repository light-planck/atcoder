use proconio::{input, marker::Chars};

const SNUKE: &str = "snuke";
const DIRS: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

struct Pos {
    i: usize,
    j: usize,
    cur: usize,
}

fn main() {
    input! {
        (h, w): (usize, usize),
        s: [Chars; h],
    }

    let mut stack: Vec<Pos> = Vec::from([Pos { i: 0, j: 0, cur: 0 }]);
    let mut seen = vec![vec![false; w]; h];

    while let Some(pos) = stack.pop() {
        let (i, j, cur) = (pos.i, pos.j, pos.cur);
        seen[i][j] = true;

        if i == h - 1 && j == w - 1 && s[i][j] == SNUKE.chars().nth(cur).unwrap() {
            println!("Yes");
            return;
        }

        for (di, dj) in DIRS {
            let (ni, nj) = (i as i32 + di, j as i32 + dj);

            if ni < 0
                || ni >= h as i32
                || nj < 0
                || nj >= w as i32
                || seen[ni as usize][nj as usize]
            {
                continue;
            }

            if s[ni as usize][nj as usize] == SNUKE.chars().nth((cur + 1) % SNUKE.len()).unwrap() {
                stack.push(Pos {
                    i: ni as usize,
                    j: nj as usize,
                    cur: (cur + 1) % SNUKE.len(),
                });
            }
        }
    }

    println!("No");
}
