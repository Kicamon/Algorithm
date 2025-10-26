# CPP——竞赛语法入门到精通

> 本资料旨在帮助想要参加信息学竞赛的同学快速掌握比赛所需的CPP语法，本资料的部分语法内容需要**CPP14**以上的版本，这也是正规的OI与ACM比赛所支持的版本，至于蓝桥杯一类的非正式比赛，请自行查询其所支持的语法版本并在比赛前熟悉，本教程不做考虑。

## 前言
> 算法比赛常用的操作系统是Windows或者NOI Linux（基于Ubuntu），这里简单简单描述一下两种操作系统的CPP编程环境配置

### Windows
#### 一、集成开发环境
集成开发环境（integrated development environment，IDE），是一种将代码编辑、编译、调试、打包等常规开发功能集成在一起的软件，使用IDE比较方便新手上手，省去配置环境变量等麻烦。

比赛常用的IDE是[Dev-C++](https://www.bloodshed.net/)，默认采用C++11标准，兼容C++98和C++14，是很多算法比赛比如蓝桥杯和天梯赛默认采用的代码编辑器。

Dev-C++这个软件已经长时间没有维护了，国内有一些技术大佬fork了一个版本，开发了[小熊猫C++](http://royqh.net/redpandacpp/)，这个软件专门针对算法竞赛开发了相关功能，非常适合算法竞赛选手日常刷题使用。

网上的CPP教程使用的大多数都是微软开发的IDE[Visual Studio](https://visualstudio.microsoft.com/zh-hans/)，这个IDE可以说是最适合Windows下工程类项目开发的软件之一，支持众多语言，功能非常强大。但是VS使用的CPP都是微软更改过的，和比赛使用的CPP有不兼容的地方，因此不推荐使用这个IDE。

#### 二、编译器
使用文本编辑器+编译器也是很多信竞选手的选择。由于IDE内置了大量的功能，但是诸如AI辅助、项目打包等功能都是算法学习当中用不到的，留着这些功能不仅占用硬盘空间，而且对内存的要求也比较高，所以很多信竞选手选择使用轻量的代码编辑器编写代码，并用编译器来编译调试代码。

编译器选用[MinGw](https://nuwen.net/mingw.html)，配合VScode或者Sublime使用即可，这里有一些具体的教程：[VScode教程](https://www.bilibili.com/video/BV1jJHTefEsJ/?share_source=copy_web&vd_source=475439b97ebe9d52756e71beadb34c29)、[Sublime教程](https://www.bilibili.com/video/BV1qV411c7VL/?spm_id_from=333.337.search-card.all.click&vd_source=54c7f15515681874f0bdf2982482d588)

### Linux
如果只是刷题的话，这里推荐直接使用[NOI Linux](https://www.noi.cn/gynoi/jsgz/2021-07-16/732450.shtml)，所有的环境都已经配置好了，下载安装后直接使用即可。

如果日常使用Linux的话，安装clang即可，也能够配合VScode或者Sublime使用，下面是常用的Linux发行版的安装命令
安装`clang`
```shell
sudo apt install clang #Debian系：Debian Linux, Ubuntu Linux, Linux Mint, Pop Os
sudo pacman -S clang #Arch系：Arch Linux, Manjaro Linux
```

编译运行
```shell
g++ test.cpp -std=c++14 -o test && ./test
```

可以写个运行脚本来自动编译运行单文件CPP程序，文件名命名为`run.sh`
```shell
#! /bin/bash

code_file=$1
extension="${code_file##*.}"
run_file=$(basename "$code_file" ".$extension")

g++ "$code_file" -std=c++14 -o "$run_file" && ./"$run_file"
```

然后运行`chmod +x run.sh`即可，需要编译运行代码的时候，只需要运行`./run.sh test.cpp`即可


[toc]

## 第一章、CPP基础语法
### 第一节、初识CPP
#### 1. 第一个CPP程序
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl; // 输出Hello World
    return 0;
}
```

**编译并运行**这个代码，可以发现，弹出的终端当中出现了一行`Hello World`

**下面我们来一行行讲解这个代码：**
1、头文件：代码的第1行
- **头文件的结构：**`#include<头文件名>`，这里我们用到的是`iostream`这个头文件，就是`#include <iostream>`。
- **头文件的作用：**头文件内分类定义了多种函数，我们用到某种类型的函数就需要使用`#include<>`将其引入到代码当中。比如我们这里用到的`iostream`，标准输入输出流的头文件，`i`是`input`的缩写、`o`是`output`的缩写、`stream`是`流`。代码的第5行用到的`cout`就是CPP的**标准输出函数**，我们用到了这个函数，就要在它的前面将其所在的头文件（也就是`iostream`）引入。

2、使用标准命名空间：代码的第2行
- **命名空间的使用：**其代码为`using namespace std;`。`using namespace`意为使用命名空间，这里使用的就是`std`，也就是standard的缩写。
- **命名空间的作用：**命名空间在CPP的**项目开发**当中十分常见，其作用是用来解决复杂项目中的**命名冲突**的问题。在CPP的项目开发当中不推荐使用这行代码，可能会出现命名冲突，但是在信竞的单文件代码当中出现的命名有限，命名冲突很容易避免，加入这行代码可以**简化**我们的代码。如果没有这行代码，我们的第5行就要写成`std::cout << "Hello World" << std::endl;`，因此在信竞当中推荐使用标准命名空间。

3、主函数：代码的第4、6、7行
- **主函数的结构：**
```cpp
int main() {
    return 0;
}
```
- **主函数的作用：**从**逻辑**上来说，每个CPP代码都是从主函数开始执行，并且从主函数结束运行的，因此**每个CPP代码都需要含有主函数**。花括号`{}`里就是我们写代码的地方
- **return 0：**`return`是函数的返回值，每个函数都会有一个返回值，其作用我们会在函数这一节讲到。主函数返回一个0就代表代码正常执行完成并退出了。

4、语句：代码的第5行
- **cout语句：**输出指定内容，其语法为：`cout << 需要输出的内容;`，如果需要输出一串字符，则需要用`""`将字符串包起来
- **endl语句：**标准换行，其作用是将输出的内容换行，可以自行运行下面两个代码感受其作用：
  - 代码1：
  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      cout << "Hello World" << endl;
      cout << "Hello World" << endl;
      return 0;
  }
  ```
  - 代码2：
  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      cout << "Hello World";
      cout << "Hello World";
      return 0;
  }
  ```
- **<<的作用：**标准输出流当中，可以用`<<`将多个内容**连接**起来，比如上面的代码中，将标准换行endl连接到输出的字符串后面
- **结束符**：每个语句的末尾都要加上`;`来表示这个语句结束了。CPP没有严格限制的代码标准，因此需要通过结束符来分割语句

5、代码注释：代码第5行，语句后面
- **代码注释的作用：**说明代码的作用，方便自己以及他人阅读代码，计算机在编译的时候并不会识别注释的内容
- **代码注释的使用**：
  1. **行注释：//**，在`//`后，这一行的所有内容都是注释
  2. **块注释：/\*\*/：**在这两个`/*`和`*/`中间的所有内容都是注释，可以**跨行**

> 至此，我们第一个代码的每一行都讲解完成

#### 2. CPP中的数据类型

1、整型：表示整数的数据类型

| **数据类型**          | **占用空间** | **取值范围**   |
| --------------------- | ------------ | -------------- |
| short（短整型）       | 2字节        | -2^15^~2^15^-1 |
| int（整型）           | 4字节        | -2^31^~2^31^-1 |
| long（长整型）        | 4字节        | -2^31^~2^31^-1 |
| long long（长长整型） | 8字节        | -2^63^~2^63^-1 |

<font color="green">int是最常用的整型</font>

2、实型（浮点型）：表示小数的数据类型

| **数据类型** | **占用空间** | **有效数字范围** |
| ------------ | ------------ | ---------------- |
| float        | 4字节        | 7位有效数字      |
| double       | 8字节        | 15~16位有效数字  |

<font color="green">double是最常用的整型</font>

3、字符型：表示单个字符的数据类型

| 数据类型 | 占用空间 |
| -------- | -------- |
| char     | 1字节    |

4、布尔类型：表示正确或错误的数据类型

| 数据类型 | 占用空间 |
| -------- | -------- |
| bool     | 1字节    |

bool型存在两种，`true(1)`和`flase(0)`，分别表示正确和错误

#### 3. CPP中的变量与常量
变量是可变的量，其创建语法为`数据类型 变量名;`或者`数据类型 变量名 = 变量初始值;`

变量在创建之后可以再通过赋值改变其存储的值

```c++
#include <iostream>

int main() {
    int a;
    int b = 10;
    a = 5;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
```

常量是创建之后就不可更改的量，所以<font color="red">常量的创建一定要对其赋予初始值</font>

常量创建有两种方式：

1、#define宏常量：`#define 常量名 常量值`

2、const修饰的变量：`const 数据类型 常量名 = 常量值;`

```c++
#include<iostream>

int main() {
    #define a 10
    const int b = 20;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
```

#### 4. 标识符的命名规则
标识符是指**变量**、**常量名**和**函数名**等，它们具有以下命名规则：
1. 标识符不能是关键字
2. 标识符只能由字母、数字、下划线组成
3. 第一个字符必须为字母或下划线
4. 标识符中字母区分大小写

**注意：命名争取做到顾名思义的效果，方便阅读。**
