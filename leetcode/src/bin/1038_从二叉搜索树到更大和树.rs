/*
 * @lc app=leetcode.cn id=1038 lang=rust
 *
 * [1038] 从二叉搜索树到更大和树
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

fn visit(root: &mut Option<Rc<RefCell<TreeNode>>>, bigger: &mut i32) {
    if let Some(root) = root {
        visit(&mut root.borrow_mut().right, bigger);
        *bigger += root.borrow().val;
        root.borrow_mut().val = *bigger;
        visit(&mut root.borrow_mut().left, bigger);
    }
}

impl Solution {
    pub fn bst_to_gst(mut root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        visit(&mut root, &mut 0);
        root
    }
}
// @lc code=end
fn main() {}
