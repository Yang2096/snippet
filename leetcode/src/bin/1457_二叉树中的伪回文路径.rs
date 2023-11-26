/*
 * @lc app=leetcode.cn id=1457 lang=rust
 *
 * [1457] 二叉树中的伪回文路径
 */

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

struct Solution {}

// @lc code=start

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn visit(root: &Option<Rc<RefCell<TreeNode>>>, count: &mut [i32; 10], result: &mut i32) {
        if let Some(node) = root {
            count[node.borrow().val as usize] += 1;
            if node.borrow().left.is_none() && node.borrow().right.is_none() {
                let mut odd = 0;
                count.iter().for_each(|c| {
                    odd += c % 2;
                });
                *result += (odd <= 1) as i32;
            } else {
                Self::visit(&node.borrow().left, count, result);
                Self::visit(&node.borrow().right, count, result);
            }
            count[node.borrow().val as usize] -= 1;
        }
    }

    pub fn pseudo_palindromic_paths(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut result = 0;
        let mut count = [0; 10];
        Self::visit(&root, &mut count, &mut result);
        result
    }
}
// @lc code=end
fn main() {
    println!("{}", Solution::pseudo_palindromic_paths(None));
}
