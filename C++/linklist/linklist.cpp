#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(const string &str);
void levelOrderTraversal(TreeNode *root);
void preOrderTraversal(TreeNode *root);
void inOrderTraversal(TreeNode *root);
void postOrderTraversal(TreeNode *root);
void destroyTree(TreeNode *root);

TreeNode *buildTree(const string &str) {
  if (str.empty())
    return NULL;

  stack<TreeNode *> nodes;
  TreeNode *root = NULL, *current = NULL;

  for (int i = 0; i < str.length(); ++i) {
    char c = str[i];
    if (c == '(') {
      nodes.push(current);
    } else if (c == ')') {
      if (!nodes.empty()) {
        current = nodes.top();
        nodes.pop();
      }
    } else if (c == ',') {
      // do nothing, just a separator
    } else {
      TreeNode *newNode = new TreeNode(c);

      if (root == NULL) {
        root = newNode; // 第一节点是根
        current = newNode;
      } else {
        if (!nodes.empty()) {
          TreeNode *parent = nodes.top();
          if (parent->left == NULL) {
            parent->left = newNode; // 左子树
          } else {
            parent->right = newNode; // 右子树
          }
        }
        current = newNode; // 更新当前节点
      }
      nodes.push(newNode); // 当前节点入栈，待处理其子节点
    }
  }
  return root;
}

void levelOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop();
    cout << current->val << " ";
    if (current->left)
      q.push(current->left);
    if (current->right)
      q.push(current->right);
  }
}

void preOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  stack<TreeNode *> s;
  s.push(root);

  while (!s.empty()) {
    TreeNode *current = s.top();
    s.pop();
    cout << current->val << " ";
    if (current->right)
      s.push(current->right);
    if (current->left)
      s.push(current->left);
  }
}

void inOrderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  inOrderTraversal(root->left);
  cout << root->val << " ";
  inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  stack<TreeNode *> s;
  TreeNode *lastVisited = NULL;
  TreeNode *current = root;

  while (!s.empty() || current != NULL) {
    if (current != NULL) {
      s.push(current);
      current = current->left;
    } else {
      TreeNode *peekNode = s.top();
      if (peekNode->right != NULL && lastVisited != peekNode->right) {
        current = peekNode->right;
      } else {
        cout << peekNode->val << " ";
        lastVisited = s.top();
        s.pop();
      }
    }
  }
}

void destroyTree(TreeNode *root) {
  if (root == NULL)
    return;
  destroyTree(root->left);
  destroyTree(root->right);
  delete root;
}

int main() {
  string input;

  getline(cin, input);
  TreeNode *root = buildTree(input);
  cout << "二叉树b:" << input << endl;

  cout << "层次遍历序列:";
  levelOrderTraversal(root);
  cout << endl;

  cout << "先序遍历序列:";
  preOrderTraversal(root);
  cout << endl;

  cout << "中序遍历序列:";
  inOrderTraversal(root);
  cout << endl;

  cout << "后序遍历序列:";
  postOrderTraversal(root);
  cout << endl;

  destroyTree(root);

  return 0;
}
