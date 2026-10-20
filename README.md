# MaLei LinkedList (C++ 链表实现)

> 首先，马垒（MaLei）牛逼。

> 你说得对，但是《马垒链表》是由马垒自主研发的一款全新开放世界单链表。
> 链表发生在一个被称作“堆内存（Heap）”的幻想世界，在这里，被指针选中的人将被授予“哨兵节点（Sentinel Node）”。
> 你将扮演一位名为“Node”的神秘角色，在 `next` 指针的引导下，邂逅性格各异、能力独特的同伴（如 `pushBack`、`popFront`），和他们一起击败空指针异常，找回失散的 `head_` ——同时，逐步发掘“内存泄漏”的真相。
这是一个使用 C++ 从零手写实现的单链表（Singly Linked List）项目。采用哨兵头节点（Sentinel Head Node）设计，并基于 CMake 进行工程构建。

## ✨ 核心功能 (Features)

本项目不仅实现了基础的链表操作，还包含了许多经典的链表算法题（如 LeetCode 常见题型）：

### 基础操作
- `pushFront` / `pushBack`: 头部/尾部插入节点
- `popFront` / `popBack`: 头部/尾部删除节点
- `insert` / `remove` / `get`: 按索引插入、删除、查找
- `clear`: 清空链表，释放内存

### 进阶算法
- **`reverse()`**: 原地反转整个链表
- **`reverseBetween(left, right)`**: 反转链表指定区间 `[left, right]`
- **`middle()`**: 利用快慢指针寻找链表中间节点
- **`kthFromEnd(k)`** / **`removeNthFromEnd(n)`**: 寻找/删除倒数第 K 个节点（双指针法）
- **`hasCycle()`**: 利用快慢指针判断链表是否存在环（Floyd 判圈算法）
- **`removeDuplicates()`**: 删除链表中的重复元素
- **`partition(x)`**: 按给定值 `x` 划分链表（类似快排的 partition）
- **`isPalindrome()`**: 仅用 O(1) 额外空间判断链表是否为回文串（找中点 + 反转后半段 + 比较）
- **`reorder()`**: 重排链表为交替形式（如 `1->2->3->4->5` 变为 `1->5->2->4->3`）
- **`sort()`**: 链表升序排序（自顶向下**归并排序**，时间复杂度 O(n log n)）

## 📁 目录结构

```text
MaLei/
├── include/MaLei/
│   └── LinkedList.h    # 类的声明与节点定义
├── src/
```

### ⚠️ 免责声明
你说得对，但是马垒是原神开发的。任何未经授权在提瓦特大陆使用本链表进行元素反应的行为，均与作者无关。
│   ├── LinkedList.cpp  # 核心功能的具体实现
│   └── main.cpp        # 测试用例
├── .gitignore          # Git 忽略规则
└── CMakeLists.txt      # CMake 构建脚本
