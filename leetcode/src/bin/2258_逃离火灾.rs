/*
 * @lc app=leetcode.cn id=2258 lang=rust
 *
 * [2258] 逃离火灾
 */

struct Solution {}
// @lc code=start

const STEPSX: [(i32, i32); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

fn check(grid: &Vec<Vec<i32>>, visit: &mut [Vec<bool>], t: i32) -> bool {
    visit
        .iter_mut()
        .for_each(|line| line.iter_mut().for_each(|v| *v = false));

    let n = grid.len();
    let m = grid[0].len();
    let mut q = std::collections::VecDeque::new();
    q.push_back((0, 0));
    visit[0][0] = true;
    let mut layer = 0;
    while !q.is_empty() {
        let count = q.len();

        for _ in 0..count {
            let (x, y) = q.pop_front().unwrap();
            for step in STEPSX.iter() {
                let xx = x as i32 + step.0;
                let yy = y as i32 + step.1;
                if xx >= 0 && xx < n as i32 && yy >= 0 && yy < m as i32 {
                    let xx = xx as usize;
                    let yy = yy as usize;

                    if grid[xx][yy] < 0
                        || visit[xx][yy]
                        || (grid[xx][yy] != 0 && grid[xx][yy] < layer + t + 1)
                    {
                        continue;
                    }

                    if grid[xx][yy] == layer + t + 1 {
                        if xx == n - 1 && yy == m - 1 {
                            return true;
                        } else {
                            continue;
                        }
                    }

                    if xx == n - 1 && yy == m - 1 {
                        return true;
                    }

                    visit[xx][yy] = true;
                    q.push_back((xx, yy));
                }
            }
        }
        layer += 1;
    }
    false
}

fn binary_search(grid: &Vec<Vec<i32>>) -> i32 {
    let n = grid.len();
    let m = grid[0].len();
    let mut visit = vec![];
    let mut line = vec![];
    line.resize(m, false);
    visit.resize(n, line);

    let mut left = 0;
    let mut right = (n - 1 + m) as i32;

    while left < right {
        let mid = left + (right - left) / 2;
        let ok = check(grid, &mut visit, mid);
        println!("{} {} {} {}", left, right, mid, ok);
        if ok {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    right - 1
}

impl Solution {
    pub fn maximum_minutes(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut q = std::collections::VecDeque::new();
        let n = grid.len();
        let m = grid[0].len();
        let mut fire_map = vec![];
        let mut line = vec![];
        line.resize(m, 0);
        fire_map.resize(n, line);
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == 1 {
                    q.push_back((i, j));
                    fire_map[i][j] = 0;
                } else if grid[i][j] == 2 {
                    fire_map[i][j] = -1;
                }
            }
        }

        let mut layer = 0;
        while !q.is_empty() {
            let mut count = q.len();
            layer += 1;
            while count != 0 {
                let (x, y) = q.pop_front().unwrap();
                count -= 1;
                for step in STEPSX.iter() {
                    let xx = x as i32 + step.0;
                    let yy = y as i32 + step.1;
                    if xx >= 0
                        && xx < n as i32
                        && yy >= 0
                        && yy < m as i32
                        && grid[xx as usize][yy as usize] == 0
                    {
                        fire_map[xx as usize][yy as usize] = layer;
                        q.push_back((xx as usize, yy as usize));
                        grid[xx as usize][yy as usize] = 2;
                    }
                }
            }
        }
        println!("{:?}", fire_map);

        let res = binary_search(&fire_map);
        if res != -1 && fire_map[0][0] == 0 {
            return 1_000_000_000;
        }
        res
    }
}
// @lc code=end

fn main() {
    println!(
        "{}",
        Solution::maximum_minutes(vec![
            vec![0, 2, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 2, 2, 1, 0],
            vec![0, 2, 0, 0, 1, 2, 0],
            vec![0, 0, 2, 2, 2, 0, 2],
            vec![0, 0, 0, 0, 0, 0, 0]
        ])
    )
}
