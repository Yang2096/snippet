/*
 * @lc app=leetcode.cn id=1254 lang=rust
 *
 * [1254] 统计封闭岛屿的数目
 */

struct Solution {}
// @lc code=start
impl Solution {
    fn check(grid: &Vec<Vec<i32>>, visit: &mut [Vec<bool>], i: i32, j: i32) -> bool {
        visit[i as usize][j as usize] = true;
        let n = grid.len();
        let m = grid[0].len();
        let mut q = std::collections::VecDeque::new();
        q.push_back((i, j));

        let mut reached = false;
        while !q.is_empty() {
            let (x, y) = q.pop_front().unwrap();
            for (i, j) in [(-1, 0), (1, 0), (0, -1), (0, 1)] {
                let xx = x + i;
                let yy = y + j;
                if xx < 0 || xx == n as i32 || yy < 0 || yy == m as i32 {
                    reached = true;
                    continue;
                }
                if grid[xx as usize][yy as usize] == 0 && !visit[xx as usize][yy as usize] {
                    visit[xx as usize][yy as usize] = true;
                    q.push_back((xx, yy));
                }
            }
        }
        reached
    }
    pub fn closed_island(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut visit = vec![vec![false; m]; n];

        let mut result = 0;
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == 0
                    && !visit[i][j]
                    && !Self::check(&grid, &mut visit, i as i32, j as i32)
                {
                    result += 1;
                }
            }
        }
        result
    }
}
// @lc code=end

fn main() {
    println!(
        "{}",
        Solution::closed_island(vec![
            vec![1, 1, 1, 1, 1, 1, 1, 0],
            vec![1, 0, 0, 0, 0, 1, 1, 0],
            vec![1, 0, 1, 0, 1, 1, 1, 0],
            vec![1, 0, 0, 0, 0, 1, 0, 1],
            vec![1, 1, 1, 1, 1, 1, 1, 0],
        ])
    );
}
