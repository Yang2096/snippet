/*
 * @lc app=leetcode.cn id=2304 lang=rust
 *
 * [2304] 网格中的最小路径代价
 */

struct Solution {}
// @lc code=start
impl Solution {
    pub fn min_path_cost(grid: Vec<Vec<i32>>, move_cost: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp = vec![grid[0].clone(), vec![0; n]];
        for i in 1..m {
            for j in 0..n {
                let mut min_path = i32::MAX;
                for k in 0..n {
                    min_path =
                        min_path.min(dp[(i - 1) % 2][k] + move_cost[grid[i - 1][k] as usize][j]);
                }
                dp[i % 2][j] = grid[i][j] + min_path;
            }
        }
        dp[(m + 1) % 2].iter().min().unwrap().to_owned()
    }
}
// @lc code=end

fn main() {
    println!(
        "{}",
        Solution::min_path_cost(
            vec![vec![5, 1, 2], vec![4, 0, 3]],
            vec![
                vec![12, 10, 15],
                vec![20, 23, 8],
                vec![21, 7, 1],
                vec![8, 1, 13],
                vec![9, 10, 25],
                vec![5, 3, 2]
            ]
        )
    )
}
