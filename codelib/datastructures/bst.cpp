#pragma once
struct Vertex {
  int val;
  Vertex *left;
  Vertex *right;
  Vertex(int n) {
    val = n;
    left = NULL;
    right = NULL;
  }
};

struct BST {
  Vertex *root;
  Vertex* addVertex(Vertex *root, int n) {
    int leftdepth, rightdepth;
    if (root == NULL) {
      return new Vertex(n);
    }
    if (root->val < n) {
      root->left = addVertex(root->left, n);
      C++;
    } else if (root->val > n) {
      root->right = addVertex(root->right, n);
    }
    return root;
  }
};

