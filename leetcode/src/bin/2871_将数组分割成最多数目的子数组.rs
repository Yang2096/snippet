/*
 * @lc app=leetcode.cn id=2871 lang=rust
 *
 * [2871] 将数组分割成最多数目的子数组
 */
struct Solution {}
// @lc code=start
impl Solution {
    pub fn max_subarrays(nums: Vec<i32>) -> i32 {
        let mut result = 0;
        let mut temp = -1;
        nums.iter().for_each(|num| {
            temp &= num;
            if temp == 0 {
                result += 1;
                temp = -1;
            }
        });
        result.max(1)
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::max_subarrays(vec![1, 0, 2, 0, 1, 2]));
    println!("{}", Solution::max_subarrays(vec![5, 7, 1, 3]));
    println!("{}", Solution::max_subarrays(vec![22, 21, 29, 22]));
}
