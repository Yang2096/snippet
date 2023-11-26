/*
 * @lc app=leetcode.cn id=53 lang=rust
 *
 * [53] 最大子数组和
 */
struct Solution {}
// @lc code=start
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut result = nums[0];
        let mut temp = 0;
        for num in nums.iter() {
            temp += num;
            if temp > result {
                result = temp;
            }
            if temp < 0 {
                temp = 0;
            }
        }
        result
    }
}
// @lc code=end

fn main() {
    println!(
        "{}",
        Solution::max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4])
    );
    println!("{}", Solution::max_sub_array(vec![-1]));
    println!(
        "{}",
        Solution::max_sub_array(vec![5,4,-1,7,8])
    );
}
