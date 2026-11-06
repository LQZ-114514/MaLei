# MaLei Data Structures (马垒的数据结构库)

> 首先，马垒（MaLei）牛逼。

你说得对，但是《马垒数据结构》是由马垒自主研发的一款全新开放世界底层架构库。代码发生在一个被称作“堆内存（Heap）”的幻想世界，在这里，被指针选中的人将被授予“哨兵节点（Sentinel Node）”。你将扮演一位名为“Node”的神秘角色，在 `next` 指针、`left/right` 指针以及 `hash` 映射的引导下，邂逅性格各异、能力独特的同伴（如 `pushBack`、`insertHelper`、`put`），和他们一起击败空指针异常，解决哈希碰撞与聚集现象，找回失散的 `head_`、`root_` 以及被删除的墓碑——同时，逐步发掘“内存泄漏”的真相。

这是一个使用 C++ 从零手写实现的数据结构与算法代码库，采用 CMake 进行工程构建。目前包含 **单链表**、**二叉树** 与 **哈希表** 三个独立的核心子项目，涵盖了大量 LeetCode 面试高频算法。

---

## 📁 目录结构

```text
MaLei/
├── LinkedList/         # 链表项目
│   ├── include/MaLei/
│   ├── src/
│   ├── .gitignore
│   └── CMakeLists.txt
├── BinaryTree/         # 二叉树项目
│   ├── include/
│   ├── src/
│   ├── .gitignore
│   └── CMakeLists.txt
├── HashTable/          # 哈希表项目
│   ├── include/
│   ├── src/
│   ├── .gitignore
│   └── CMakeLists.txt
└── README.md
```

---

## 🔗 1. LinkedList (单链表实现)

采用哨兵头节点（Sentinel Head Node）设计，实现了基础的增删改查，以及多种经典链表算法。

### ✨ 核心功能

**基础操作**

| 函数 | 功能描述 |
| :--- | :--- |
| `pushFront` / `pushBack` | 头部 / 尾部插入节点 |
| `popFront` / `popBack` | 头部 / 尾部删除节点 |
| `insert` / `remove` / `get` | 按索引插入、删除、查找 |
| `clear` | 清空链表，释放内存 |

**进阶算法**

| 函数 | 功能描述 |
| :--- | :--- |
| `reverse()` | 原地反转整个链表 |
| `reverseBetween(left, right)` | 反转链表指定区间 `[left, right]` |
| `middle()` | 利用快慢指针寻找链表中间节点 |
| `kthFromEnd(k)` / `removeNthFromEnd(n)` | 寻找 / 删除倒数第 K 个节点（双指针法） |
| `hasCycle()` | 利用快慢指针判断链表是否存在环（Floyd 判圈算法） |
| `removeDuplicates()` | 删除链表中的重复元素 |
| `partition(x)` | 按给定值 `x` 划分链表 |
| `isPalindrome()` | 仅用 O(1) 额外空间判断链表是否为回文串（找中点 + 反转后半段 + 比较） |
| `reorder()` | 重排链表为交替形式（如 `1->2->3->4->5` 变为 `1->5->2->4->3`） |
| `sort()` | 链表升序排序（自顶向下归并排序，时间复杂度 O(n log n)） |

---

## 🌳 2. BinaryTree (二叉搜索树实现)

手写二叉搜索树（BST），包含深度/广度优先遍历、树属性判定、树形 DP 以及回溯算法的实战应用。

### ✨ 核心功能

**基础操作**

| 函数 | 功能描述 |
| :--- | :--- |
| `insert` | 插入节点 |
| `clear` / `empty` | 清空树、判断是否为空 |
| `size` / `height` | 获取节点总数、获取树的高度 |

**遍历操作**

| 函数 | 功能描述 |
| :--- | :--- |
| `preorder()` / `inorder()` / `postorder()` | 前序 / 中序 / 后序遍历 (DFS) |
| `levelorder()` | 层序遍历 (BFS) |

**属性与判定**

| 函数 | 功能描述 |
| :--- | :--- |
| `leafCount()` | 统计叶子节点数 |
| `degreeOneCount()` / `degreeTwoCount()` | 统计度为 1 和度为 2 的节点数 |
| `isFull()` | 判断是否为满二叉树 |
| `isComplete()` | 判断是否为完全二叉树（BFS + 状态记录） |
| `isBalanced()` | 判断是否为高度平衡树（自底向上 O(N) 算法） |

**高级算法**

| 函数 | 功能描述 |
| :--- | :--- |
| `mirror()` | 翻转二叉树（递归修改左右孩子） |
| `sameTree()` / `isSymmetric()` | 判断两棵树是否相同 / 是否镜像对称（双树同步递归） |
| `diameter()` | 求树的直径（树形 DP 复用高度信息） |
| `printPaths()` | 输出所有根到叶子的路径（DFS + 回溯） |
| `lowestCommonAncestor(a, b)` | 求两个节点的最近公共祖先 (LCA) |
| `maxPathSum()` | 求树中的最大路径和（树形 DP） |

---

## 🗂️ 3. HashTable (哈希表实现)

从零手写实现哈希表，对比并完成了两种最经典的冲突解决策略：**链地址法（拉链法）** 与 **开放寻址法（线性探测）**。

### ✨ 核心功能

**链地址法 (ChainedHashTable)**

| 函数 | 功能描述 |
| :--- | :--- |
| `put` / `get` / `remove` | 插入更新 / 获取值 / 删除键值对 |
| `contains` / `clear` / `size` | 判断存在 / 清空表 / 获取元素数量 |
| `loadFactor()` | 计算当前负载因子 |
| `rehash()` / `reserve()` | 动态扩容重新散列 / 保证最小容量 |
| `bucketSize()` / `maxBucketSize()` | 分析桶内链表长度与最大冲突链 |
| `collisionCount()` | 统计当前哈希表发生冲突的元素数量 |

**开放寻址法 (OpenHashTable)**

| 函数 | 功能描述 |
| :--- | :--- |
| `put` / `get` / `remove` | 插入更新 / 获取值 / 墓碑删除 |
| `contains` / `clear` / `size` | 判断存在 / 清空表 / 获取元素数量 |
| `hash()` / `probe()` | 计算初始槽位 / 线性探测寻找下一个可用槽位 |
| `findIndex()` | 核心查找逻辑，返回 key 所在的槽位下标 |
| `rehash()` / `reserve()` | 动态扩容清理墓碑 / 保证最小容量 |
| `clusterCount()` / `longestCluster()` | 统计连续聚集区域数量与最长聚集长度（分析聚集现象） |
| `averageProbeLength()` | 计算平均探测长度（性能分析指标） |

---

## 🛠️ 编译与运行

本仓库包含三个独立的 CMake 项目，请分别进入对应目录进行编译：

### 编译运行 LinkedList 项目

```bash
cd LinkedList
mkdir build && cd build
cmake ..
cmake --build .

# Windows 下运行
./Debug/MaLei.exe
```

### 编译运行 BinaryTree 项目

```bash
cd BinaryTree
mkdir build && cd build
cmake ..
cmake --build .

# Windows 下运行
./Debug/Tree.exe
```

### 编译运行 HashTable 项目

```bash
cd HashTable
mkdir build && cd build
cmake ..
cmake --build .

# Windows 下运行 (根据你 CMakeLists 里的 target 名调整)
./Debug/HashTable.exe
```

---

## ⚠️ 免责声明

你说得对，但是马垒是原神开发的。任何未经授权在提瓦特大陆使用本仓库的指针进行元素反应，或由于哈希冲突引发世界树崩溃的行为，均与作者无关。