/**
Problem Statemet
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center)
**/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool isMirror(TreeNode* t1, TreeNode* t2){
    if(t1==NULL && t2==NULL)return true;
    else if(t1==NULL|| t2==NULL) return false;
    
    return (t1->val==t2->val) && isMirror(t1->left,t2->right) &&isMirror(t1->right,t2->left);
}
int Solution::isSymmetric(TreeNode* A) {
    return isMirror(A,A);
}


