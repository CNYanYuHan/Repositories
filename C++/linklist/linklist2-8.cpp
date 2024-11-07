#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct HuffmanNode {
  int weight;
  string word;
  HuffmanNode *left, *right;

  HuffmanNode(int weight, string word)
      : weight(weight), word(word), left(nullptr), right(nullptr) {}
};

struct Compare {
  bool operator()(HuffmanNode *l, HuffmanNode *r) {
    return l->weight > r->weight;
  }
};

void generateHuffmanCode(HuffmanNode *root, string str,
                         unordered_map<string, string> &huffmanCodes) {
  if (!root)
    return;
  if (!root->word.empty()) {
    huffmanCodes[root->word] = str;
  }
  generateHuffmanCode(root->left, str + "0", huffmanCodes);
  generateHuffmanCode(root->right, str + "1", huffmanCodes);
}

double calculateAverageSearchLength(HuffmanNode *root, int depth = 0) {
  if (!root)
    return 0;
  if (!root->word.empty())
    return depth * root->weight;
  return calculateAverageSearchLength(root->left, depth + 1) +
         calculateAverageSearchLength(root->right, depth + 1);
}

int main() {
  vector<string> words = {"The", "of", "a",  "to",  "and", "in",  "that", "he",
                          "is",  "at", "on", "for", "His", "are", "be"};
  vector<int> weights(words.size());
  priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> minHeap;

  for (int i = 0; i < words.size(); ++i) {
    cout << "Enter frequency for" << words[i] << ":";
    cin >> weights[i];
    minHeap.push(new HuffmanNode(weights[i], words[i]));
  }

  while (minHeap.size() > 1) {
    HuffmanNode *left = minHeap.top();
    minHeap.pop();
    HuffmanNode *right = minHeap.top();
    HuffmanNode *top = new HuffmanNode(left->weight + right->weight, "");
    top->left = left;
    top->right = right;
    minHeap.push(top);
  }

  HuffmanNode *root = minHeap.top();
  unordered_map<string, string> huffmanCodes;
  generateHuffmanCode(root, "", huffmanCodes);

  cout << "哈夫曼编码:\n";
  for (const string &word : words) {
    cout << word << ": " << huffmanCodes[word] << endl;
  }

  double avgLength = calculateAverageSearchLength(root);
  cout << "平均查找长度:" << avgLength << endl;

  while (!minHeap.empty()) {
    delete minHeap.top();
    minHeap.pop();
  }
  delete root;

  return 0;
}