以下是一个简单的C++ 程序示例，用于实现单链表的各种基本操作。首先，我们创建`linklist
    .cpp`文件来定义单链表的数据结构和相关操作。
```cpp
// linklist.cpp
#include <iostream>
    // 定义单链表的元素类型为 char
    typedef char ElemType;
// 定义单链表节点结构体
struct ListNode {
  ElemType data;  // 数据域
  ListNode *next; // 指针域
};
// 定义单链表类
class LinkList {
public:
  LinkList();                                    // 构造函数
  ~LinkList();                                   // 析构函数
  void Append(const ElemType &value);            // 尾插法插入元素
  void PrintList() const;                        // 输出单链表
  int Length() const;                            // 获取单链表长度
  bool IsEmpty() const;                          // 判断单链表是否为空
  ElemType GetElem(int index) const;             // 获取指定位置的元素
  int LocateElem(const ElemType &value) const;   // 获取元素位置
  void Insert(int index, const ElemType &value); // 在指定位置插入元素
  void Delete(int index);                        // 删除指定位置的元素
private:
  ListNode *head; // 头指针
};
// 构造函数
LinkList::LinkList() : head(nullptr) {}
// 析构函数
LinkList::~LinkList() {
  ListNode *current = head;
  while (current != nullptr) {
    ListNode *temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
}
// 尾插法插入元素
void LinkList::Append(const ElemType &value) {
  ListNode *newNode = new ListNode{value, nullptr};
  if (head == nullptr) {
    head = newNode;
  } else {
    ListNode *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }
}
// 输出单链表
void LinkList::PrintList() const {
  ListNode *current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}
// 获取单链表长度
int LinkList::Length() const {
  int count = 0;
  ListNode *current = head;
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}
// 判断单链表是否为空
bool LinkList::IsEmpty() const { return head == nullptr; }
// 获取指定位置的元素
ElemType LinkList::GetElem(int index) const {
  if (index < 0)
    return '\0'; // 无效位置
  ListNode *current = head;
  for (int i = 0; current != nullptr && i < index; ++i) {
    current = current->next;
  }
  return current ? current->data : '\0';
}
// 获取元素位置
int LinkList::LocateElem(const ElemType &value) const {
  int index = 0;
  ListNode *current = head;
  while (current != nullptr) {
    if (current->data == value) {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1; // 未找到
}
// 在指定位置插入元素
void LinkList::Insert(int index, const ElemType &value) {
  if (index < 0)
    return;
  ListNode *newNode = new ListNode{value, nullptr};
  if (index == 0) {
    newNode->next = head;
    head = newNode;
  } else {
    ListNode *current = head;
    for (int i = 0; current != nullptr && i < index - 1; ++i) {
      current = current->next;
    }
    if (current != nullptr) {
      newNode->next = current->next;
      current->next = newNode;
    }
  }
}
// 删除指定位置的元素
void LinkList::Delete(int index) {
  if (index < 0 || head == nullptr)
    return;
  ListNode *current = head;
  if (index == 0) {
    head = head->next;
    delete current;
  } else {
    ListNode *prev = nullptr;
    for (int i = 0; current != nullptr && i < index; ++i) {
      prev = current;
      current = current->next;
    }
    if (current != nullptr) {
      prev->next = current->next;
      delete current;
    }
  }
}

