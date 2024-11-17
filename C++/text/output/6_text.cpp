#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// 函数声明
TreeNode *buildTree(const string &str);
void levelOrderTraversal(TreeNode *root);
void preOrderTraversal(TreeNode *root);
void inOrderTraversal(TreeNode *root);
void postOrderTraversal(TreeNode *root);
void destroyTree(TreeNode *root);

// 构建二叉树
TreeNode *buildTree(const string &str) {
  if (str.empty())
    return nullptr;

  stack<TreeNode *> nodeStack; // 用于存储节点
  TreeNode *root = nullptr;    // 根节点
  TreeNode *current = nullptr; // 当前节点

  for (char c : str) {
    if (isalpha(c)) { // 创建新节点
      current = new TreeNode(c);
      if (root == nullptr) {
        root = current; // 设置根节点
      } else {
        if (!nodeStack.empty()) { // 连接到父节点
          TreeNode *parent = nodeStack.top();
          if (parent->left == nullptr) {
            parent->left = current; // 左子树
          } else {
            parent->right = current; // 右子树
          }
        }
      }
    } else if (c == '(') {
      if (current)
        nodeStack.push(current); // 入栈当前节点
    } else if (c == ')') {
      nodeStack.pop(); // 出栈
    }
    // 逗号不需要处理
  }
  return root; // 返回根节点
}

// 层次遍历
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

// 先序遍历
void preOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  cout << root->val << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// 中序遍历
void inOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  inOrderTraversal(root->left);
  cout << root->val << " ";
  inOrderTraversal(root->right);
}

// 后序遍历
void postOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->val << " ";
}

// 销毁树
void destroyTree(TreeNode *root) {
  if (!root)
    return;
  destroyTree(root->left);
  destroyTree(root->right);
  delete root;
}

// 主函数
int main() {
  string input;
  getline(cin, input); // 例如A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))

  TreeNode *root = buildTree(input); // 构建树

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

  destroyTree(root); // 销毁树
  return 0;
}
