/*
 * @lc app=leetcode.cn id=2824 lang=rust
 *
 * [2824] 统计和小于目标的下标对数目
 */

struct Solution {}
// @lc code=start
impl Solution {
    pub fn count_pairs(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort_unstable();

        let mut left = 0;
        let mut right = nums.len() - 1;
        let mut result = 0;
        while left < right {
            if nums[left] + nums[right] < target {
                result += right - left;
                left += 1;
            } else {
                right -= 1;
            }
        }
        result as _
    }
}
// @lc code=end

fn main() {
    println!(
        "{}",
        Solution::count_pairs(vec![-6, 2, 5, -2, -7, -1, 3], -2)
    );
    println!(
        "{}",
        Solution::count_pairs(vec![-1,1,2,3,1], 2)
    );
}
