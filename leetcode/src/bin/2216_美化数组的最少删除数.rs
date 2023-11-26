/*
 * @lc app=leetcode.cn id=2216 lang=rust
 *
 * [2216] 美化数组的最少删除数
 */

struct Solution {}
// @lc code=start
impl Solution {
    pub fn min_deletion(nums: Vec<i32>) -> i32 {
        let mut current = nums[0];
        let mut deleted = 0usize;
        (1..nums.len()).for_each(|i| {
            let num = nums[i];
            if num == current {
                if (i - deleted) % 2 == 1 {
                    deleted += 1;
                }
            } else {
                current = num;
            }
        });
        if (nums.len() - deleted) % 2 == 1 {
            deleted += 1;
        }
        deleted as i32
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::min_deletion(vec![1, 1, 2, 2, 3, 3]));
    println!("{}", Solution::min_deletion(vec![1, 1, 2, 3, 5]));
}
