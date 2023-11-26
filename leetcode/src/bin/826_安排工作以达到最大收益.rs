/*
 * @lc app=leetcode.cn id=826 lang=rust
 *
 * [826] 安排工作以达到最大收益
 */

struct Solution {}

// @lc code=start
impl Solution {
    fn binary_search(work: &[(i32, i32)], w: i32) -> i32 {
        let mut left = 0;
        let mut right = work.len();
        while left < right {
            let mid = left + (right - left) / 2;
            if work[mid].0 <= w {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if right == 0 {
            0
        } else {
            work[right].1
        }
    }

    pub fn max_profit_assignment(difficulty: Vec<i32>, profit: Vec<i32>, worker: Vec<i32>) -> i32 {
        let mut work: Vec<_> = difficulty.into_iter().zip(profit.into_iter()).collect();

        work.sort_unstable_by_key(|w| w.0);

        let mut max_profit = 0;
        work.iter_mut().for_each(|w| {
            max_profit = std::cmp::max(max_profit, w.1);
            w.1 = max_profit;
        });

        let mut result = 0;
        for w in worker.iter() {
            result += Self::binary_search(&work, *w);
        }
        result
    }
}
// @lc code=end

fn main() {
    println!(
        "{}",
        Solution::max_profit_assignment(
            vec![2, 4, 6, 8, 10],
            vec![10, 20, 30, 40, 50],
            vec![4, 5, 6, 7]
        )
    );
    println!(
        "{}",
        Solution::max_profit_assignment(vec![85, 47, 57], vec![24, 66, 99], vec![40, 25, 25])
    );
}
