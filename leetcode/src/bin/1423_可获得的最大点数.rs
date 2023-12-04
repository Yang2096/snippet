/*
 * @lc app=leetcode.cn id=1423 lang=rust
 *
 * [1423] 可获得的最大点数
 */

struct Solution {}
// @lc code=start
impl Solution {
    pub fn max_score(card_points: Vec<i32>, k: i32) -> i32 {
        let n = card_points.len();
        let mut left_sum = vec![0; n + 2];
        let mut right_sum = vec![0; n + 2];
        left_sum[1] = card_points[0];
        right_sum[n] = card_points[n - 1];
        for i in 1..card_points.len() {
            left_sum[i + 1] = card_points[i] + left_sum[i];
            right_sum[n - i] = card_points[n - i - 1] + right_sum[n - i + 1];
        }

        let mut result = 0;
        for i in 0..=k as usize {
            result = result.max(left_sum[i] + right_sum[n + i + 1 - k as usize]);
        }
        result
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::max_score(vec![1, 2, 3, 4, 5, 6, 1], 3));
}
