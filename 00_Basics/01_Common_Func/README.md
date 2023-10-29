# C 语言常用函数

- [inc/](./inc/) - 通用头文件
  - [commonDef/](./inc/commonDef/) - 通用定义头文件
    - [commonTypeDef.h](./inc/commonDef/commonTypeDef.h) - 通用类型定义头文件
    - [commonPrintDef.h](./inc/commonDef/commonPrintDef.h) - 通用打印定义头文件
  - [commonHelper.h](./inc/commonHelper.h) - 通用头文件
  - [commonCmd.h](./inc/commonCmd.h) - 通用命令行指令头文件
  - [commonRingBuffer.h](./inc/commonRingBuffer.h) - 通用环形缓冲区头文件
  - [commonArray.h](./inc/commonArray.h) - 通用数组头文件
  - [commonString.h](./inc/commonString.h) - 通用字符串头文件
  - [commonLinkedList.h](./inc/commonLinkedList.h) - 通用链表头文件
  - [commonLinkedListDummy.h](./inc/commonLinkedListDummy.h) - 通用虚拟头节点链表头文件
  - [commonHashTable.h](./inc/commonHashTable.h) - 通用哈希表头文件
  - [commonBinaryTree.h](./inc/commonBinaryTree.h) - 通用二叉树头文件
- [src/](./src/) - 通用源文件
  - [commonHelper.c](./src/commonHelper.c) - 通用源文件
  - [commonCmd.c](./src/commonCmd.c) - 通用命令行指令源文件
  - [commonRingBuffer.c](./src/commonRingBuffer.c) - 通用环形缓冲区源文件
  - [commonArray.c](./src/commonArray.c) - 通用数组源文件
  - [commonString.c](./src/commonString.c) - 通用字符串源文件
  - [commonLinkedList.c](./src/commonLinkedList.c) - 通用链表源文件
  - [commonLinkedListDummy.c](./src/commonLinkedListDummy.c) - 通用虚拟头节点链表源文件
  - [commonHashTable.c](./src/commonHashTable.c) - 通用哈希表源文件
  - [commonBinaryTree.c](./src/commonBinaryTree.c) - 通用二叉树源文件
-

.
│  [main.c](main.c) - 主程序(测试用途)
│  README.md - 本文件
│
├─[inc/](./inc/) - 通用头文件
│  │  commonArray.h
│  │  commonBinaryTree.h
│  │  commonCmd.h
│  │  commonHashTable.h
│  │  commonHelper.h
│  │  commonLinkedList.h
│  │  commonLinkedListDummy.h
│  │  commonQueue.h
│  │  commonRingBuffer.h
│  │  commonStack.h
│  │  commonString.h
│  │
│  └─[commonDef/](./inc/commonDef/) - 通用定义头文件
│          [commonPrintDef.h](./inc/commonDef/commonPrintDef.h) - 通用打印定义头文件
│          [commonTypeDef.h](./inc/commonDef/commonTypeDef.h) - 通用类型定义头文件
│
└─[src/](./src/) - 通用源文件
        commonArray.c
        commonBinaryTree.c
        commonCmd.c
        commonHashTable.c
        commonHelper.c
        commonLinkedList.c
        commonLinkedListDummy.c
        commonQueue.c
        commonRingBuffer.c
        commonStack.c
        commonString.c