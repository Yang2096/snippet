/*
 * @lc app=leetcode.cn id=689 lang=rust
 *
 * [689] 三个无重叠子数组的最大和
 */

struct Solution {}

// @lc code=start
impl Solution {
    pub fn max_sum_of_three_subarrays(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut nums_sum = vec![0; nums.len() + 1];
        for (i, num) in nums.iter().enumerate() {
            nums_sum[i + 1] = num + nums_sum[i];
        }
        let k = k as usize;

        let mut result = vec![0; 3];
        let mut dp = vec![vec![(0, 0); nums.len() + 1]; 4];

        for j in 1..=3 {
            for i in j * k..nums_sum.len() {
                if nums_sum[i] - nums_sum[i - k] + dp[j - 1][i - k].0 > dp[j][i - 1].0 {
                    dp[j][i] = (nums_sum[i] - nums_sum[i - k] + dp[j - 1][i - k].0, i);
                } else {
                    dp[j][i] = dp[j][i - 1];
                }
            }
        }
        // println!("{:?}", dp);

        let mut temp = 0;
        for i in 3 * k..nums_sum.len() {
            if dp[3][i].0 > temp {
                temp = dp[3][i].0;
                result[2] = i as i32;
            }
        }
        for j in (1..=2).rev() {
            result[j - 1] = dp[j][result[j] as usize - k].1 as i32;
        }
        result.iter_mut().for_each(|res| *res -= k as i32);

        result
    }
}
// @lc code=end

fn main() {
    println!(
        "{:?}",
        Solution::max_sum_of_three_subarrays(vec![1, 2, 1, 2, 6, 7, 5, 1], 2)
    );
    println!(
        "{:?}",
        Solution::max_sum_of_three_subarrays(vec![1, 2, 1, 2, 1, 2, 1, 2, 1], 2)
    )
}
