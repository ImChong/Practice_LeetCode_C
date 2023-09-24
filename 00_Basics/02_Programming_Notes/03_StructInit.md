在C语言中，你可以使用多种方法来定义结构体(`struct`)。以下是一些常见的定义方式：

1. **基础定义**：

   ```c
   struct Student {
       char name[50];
       int age;
   };
   ```

2. **通过typedef创建一个新的类型名**：
   这种方式可以让你在后续的代码中不必每次都使用`struct`关键字。

   ```c
   typedef struct {
       char name[50];
       int age;
   } Student;
   ```

3. **结构体内包含其他结构体**：

   ```c
   struct Address {
       char street[100];
       char city[50];
   };

   struct Person {
       char name[50];
       struct Address address; // 嵌套结构体
   };
   ```

4. **结构体包含指向自己类型的指针**：
   用于创建链表、树等数据结构。

   ```c
   struct Node {
       int data;
       struct Node* next;
   };
   ```

5. **结构体中使用位字段**：
   当你想在结构体中为某个成员分配特定数量的位时，可以使用位字段。

   ```c
   struct Flags {
       unsigned int isOn : 1;  // 只占用1位
       unsigned int isReady : 1;  // 只占用1位
   };
   ```

6. **匿名结构体**：
   在某些情况下，你可能不需要给结构体命名。

   ```c
   struct {
       char name[50];
       int age;
   } student1, student2;
   ```

7. **结构体数组**：

   ```c
   struct Student {
       char name[50];
       int age;
   };

   struct Student class[50];  // 定义一个包含50个学生的数组
   ```

8. **结构体中的联合**：
   结构体可以包含联合，联合允许在同一内存位置存储不同的数据类型。

   ```c
   union Data {
       int i;
       float f;
       char str[20];
   };

   struct Info {
       char type[10];
       union Data data;
   };
   ```

每种定义方式都有其适用的场景，根据需要选择合适的定义方式。
