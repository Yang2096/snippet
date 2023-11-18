/*
 * @lc app=leetcode.cn id=2736 lang=rust
 *
 * [2736] 最大和查询
 * 单调栈 二分查找
 */
struct Solution {}
// @lc code=start
impl Solution {
    pub fn maximum_sum_queries(
        nums1: Vec<i32>,
        nums2: Vec<i32>,
        queries: Vec<Vec<i32>>,
    ) -> Vec<i32> {
        let n = nums1.len();
        let m = queries.len();

        let mut result = vec![-1; m];

        let mut xvec = vec![];
        xvec.reserve(n);
        for i in 0..n {
            xvec.push((nums1[i], nums2[i]));
        }

        let mut queries: Vec<_> = queries.iter().enumerate().collect();

        xvec.sort_unstable_by(|a, b| a.0.cmp(&b.0));
        queries.sort_unstable_by(|a, b| b.1[0].cmp(&a.1[0]));

        let mut xy = vec![];
        let mut index = (n - 1) as i32;

        for query in queries.iter() {
            let (qx, qy) = (query.1[0], query.1[1]);
            while index >= 0 {
                let (x, y) = xvec[index as usize];
                if x < qx {
                    break;
                }
                index -= 1;
                // 单调栈
                while let Some((y1, xy1)) = xy.last() {
                    if *y1 < y {
                        if *xy1 <= x + y {
                            xy.pop();
                        } else {
                            xy.push((y, x + y));
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if xy.is_empty() {
                    xy.push((y, x + y));
                }
            }

            // 二分查找
            let p = xy.partition_point(|input| input.0 < qy);
            if p != xy.len() {
                result[query.0] = xy[p].1;
            }
        }

        result
    }
}
// @lc code=end
fn main() {
    println!(
        "{:?}",
        Solution::maximum_sum_queries(
            vec![4, 3, 1, 2],
            vec![2, 4, 9, 5],
            vec![vec![4, 1], vec![1, 3], vec![2, 5]]
        )
    );
}
