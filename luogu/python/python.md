## python学习入门

### 1. 第一个程序：hello world
```python
print("hello world")
```


第一个作业：输出`hello world`

[hello world](https://www.luogu.com.cn/problem/B2002)


### 2. 输出
在python当中，输出使用的是print()函数，我们将要输出的**变量**直接放在括号当中即可

### 3. 变量
变量就是用来存储值的一个**可变的量**

输入下列代码：
```python
a = "hello world"
print(a)
```

这串代码的运行结果和`print("hello world")`是相等的

输入下列代码：
```python
a = "hello world"
print(a)
a = 520
print(a)
```

这串代码的运行结果有两行：
```
hello world
520
```

a的值最开始是`hello world`，然后又改变成了$1$

变量的类型有**数字、字符串、列表**三种

#### 3.1. 数字
> 数字的基本类型有整数(int)和小数(float)，当然，在python当中还有一些复杂的数字表示，这里暂且不提

python当中的数字运算
| 符号 | 表示 | 符号 | 表示 |
| :--: | :--: | :--: | :--: |
| +    | 加   | **   | 次方 |
| -    | 减   | *    | 乘   |
| /    | 除   | //   | 整除 |
| %    | 取模 | =    | 赋值 |

在这里我们提一嘴python当中的注释

首先是单行注释：`#`这个符号的后面不会作为python语句被识别，可以任意写内容

然后是多行注释：
```python
# 单行注释
'''
多行注释
多行注释
多行注释
'''
```

这里暂且表过，待会我们会用到，到时候就知道具体作用了

我们继续来讲运算符，建议按照分界线依次输入代码，比如先写前三行的代码运行一次，删掉后再写后面的代码
```python
a = 10 #将10赋值给a，下面同理
b = 20
print(a + b) # 输出a+b的结果30

# ---------------------------------------
a = 10.5
b = 20
print(a + b) # 输出a+b的结果30.5
'''
这里提及一点：
小数加整数，结果是小数
小数加小数，结果是小数
'''

# ---------------------------------------
a = 10.5
b = 20.5
print(a + b) # 输出a+b的结果31.0，这里是带小数点的

# ---------------------------------------
a = 7
b = 2
print(a / b) # 输出a除以b的结果3.5

# ---------------------------------------
a = 7
b = 2
print(a // b) # 输出a除以b向下取整的结果3

# ---------------------------------------
a = 7
b = 2
print(a % b) # 输出a除以b的模数1

# ---------------------------------------
# 当然，我们还可以这么输出
a = 10
b = 20
c = a + b
print(a) # 输出30
```

#### 3.2. 字符串
字符串就是一串字符，比如最开始我们输出的"hello world"就是一个字符串

在存储字符串的时候，需要将其包裹在`' '`当中或者`" "`，我的个人习惯是放在双引号当中，单个字符放在单引号当中

```python
a = "hello world"
print(a) # 输出hello world
a = 'hello world'
print(a) # 输出hello world
```

**字符串的拼接操作**
```python
a = "hello"
b = "world"
print(a + b) # 输出helloworld
print(a + ' ' +  b) # 输出hello world
```


**字符串部分元素访问（切片）<++>**
```python
a = "hello world"
# 如果我们想要得到字符串a的第一个字符的话，可以
print(a[0])
# 想要输出hello的话
print(a[0:5]) # 就是将a[0],a[1],a[2],a[3],a[5]输出
# 想要输出world的话
print(a[6:]) # 就是将a[6]之后的字符全输出
```

**字符的转义**

我们在输出hello world的时候，将其包裹在引号内就好了，但是如果我们想要输出"hello world"的时候呢？想要输出带引号的字符串，就要用`\`将引号转义

```python
print("\"hello world\"")
```

当然，转义字符还有很多，比如我们想要换行，就可以使用`\n`

```python
print("hello\nworld")
'''
输出两行：
hello
world
'''
```

**字符串的长度**

使用`len()`函数获得字符串的长度

```python
a = "i love you"
print(len(a)) # 输出10
```

#### 3.3. 列表

列表可以存储多个数值，包括数字、字符串和列表（在列表中嵌套一个列表）

比如：
```python
a = [1, 2, 3, "hello world", "i love you"]
print(a[0], a[1], a[2], a[3], a[4])
# 输出：1 2 3 hello world i love you
# 当然了，列表当中的数值是可以改变的

a[4] = "i love you forever"
print(a[0], a[1], a[2], a[3], a[4])
# 输出：1 2 3 hello world i love you forever
```


此外，想要往列表中添加新的元素也很简单，使用`.append()`函数即可

```python
a = [1, 2, 3, "hello world", "i love you"]
print(a[0], a[1], a[2], a[3], a[4])
# 输出：1 2 3 hello world i love you
a.append("kiss kiss kiss")
print(a[0], a[1], a[2], a[3], a[4], a[5])
# 输出：1 2 3 hello world i love you kiss kiss kiss
```

当然了，列表可以直接输出，但是会带有括号

```python
a = [1, 2, 3, "hello world", "i love you"]
print(a)
# 输出：[1, 2, 3, 'hello world', 'i love you']
a.append("kiss kiss kiss")
print(a)
# 输出：[1, 2, 3, 'hello world', 'i love you', 'kiss kiss kiss']
```

删除元素，将想要删除的切片换成空即可
```python
a = [1, 2, 3, "hello world", "i love you"]
# 如果想去掉前面的数字，这么操作:
a[0:3] = []
```

列表长度，使用`len()`函数
```python
a = [1, 2, 3, "hello world", "i love you"]
print(len(a))
```


列表嵌套

```python
a = [1, 2, 3]
b = ["hello world", "i love you"]
c = [a, b]
print(c)
# 输出：[[1, 2, 3], ['hello world', 'i love you']]
```

### 4. if语句
if语句适用于判断条件，分为`if`, `elif`, `else`三种

我们看例题：

给定学生的分数$n$，$90 \le n \le 100$为$A$，$80 \le n < 90$为$B$，$70 \le n < 80$为$C$，$60 \le n < 70$为$D$，$n < 60$为$E$，确保$0 \le n \le 100$

```python
a = int(input()) # 输入的时候都是在字符串，用int()将其转化为整数
if a < 60:
    print('E')
elif a < 70:
    print('D')
elif a < 80:
    print('C')
elif a < 90:
    print('B')
else:
    print('A')
'''
这串代码的含义是：
如果n < 60，输出E，
否则如果n < 70，输出D
否则如果n < 80，输出C
…………
最后，如果上面的情况都不符合，则输出A
'''
```

### 5. for语句

给定一个列表，如果我们想要将每个元素输出，并输出它的长度，就可以使用for语句

```python
a = ["hello world", "i love you"]
for b in a:
    print(b, len(b))
'''
输出：
hello world 11
i love you 10
'''
```

### 6. range()函数

如果我们想将0-100全部输出，那么我们可以用到range函数

```python
for i in range(100):
    print(i)
```

如果想要输出1-100，我们可以这么写

```python
for i in range(1, 100):
    print(i)
```

如果想要将1-100隔一个输出，我们可以这么写
```python
for i in range(1, 100, 2):
    print(i)
```

给定一个列表，想要将其全部输出，我们可以这么写
```python
a = ["hello world", "i love you"]
for i in range(len(a)):
    print(a[i])
```

### 7. while循环
如果我们想输出小于100的斐波那契数列

```python
a, b = 0, 1
while a < 100:
    print(a)
    a, b = b, a + b
```

这段话的意思是，如果a小于100，就执行while循环里的语句，直到a大于等于100，结束循环

### 8. break和continue语句
如果我们想输出1-100当中所有不是3的倍数的数，可以使用continue

```python
for i in range(1, 100):
    if i % 3 == 0:
        continue
    print(i)
```

这段代码的意思是，如果i对3取模等于0（说明i为3的倍数）就跳过这次，否则就输出i

如果我们想要输出100以内的质数，可以这么写

```python
for i in range(2, 100):
    flag = True # True表示条件为真
    for j in range(2, i - 1):
        if i % j == 0:
            flag = False
            break
    if flag: # 如果条件为真，则输出
        print(i)
```

### 9. pass语句和match语句

pass语句用于进行留白处理，比如我想要写一个循环，但是还没有想好循环内怎么写，可以写下一个pass语句。如果空着不写的话，程序是会报错的

```python
for i in range(2, 100):
    pass
```

match语句类似于if语句，但是情况较多的时候比if要更快

我们运行一下下面的代码：
```python
n = 30
match n:
    case 60:
        print("n =", 60)
    case 50:
        print("n =", 50)
    case 40:
        print("n =", 40)
    case 30:
        print("n =", 30)
    case _:
        print("unkown")
# 输出30
```

```python
n = 20
match n:
    case 60:
        print("n =", 60)
    case 50:
        print("n =", 50)
    case 40:
        print("n =", 40)
    case 30:
        print("n =", 30)
    case _:
        print("unkown")
# 输出unkown
```

当然，我们可以让每个case匹配多个条件
```python
n = 40
match n:
    case 60 | 50 | 40 :
        print("n =", 60,"or",50,"or",40)
    case 30:
        print("n =", 30)
    case _:
        print("unkown")
```

### 10. 定义函数

如果我们想要求斐波那契数列的第n位，可以这么写
```python
n = int(input())
a, b = 0, 1
for i in range(n + 1):
    if i == n:
        print(a)
        break
    else:
        a, b = b, a + b
```

但是，如果在一个代码当中，我们想要多次求斐波那契数列第n位的话，每次都写一遍会很麻烦，而且容易造成代码的冗长，所以我们可以用def将其封装成一个函数


```python
def fib(n): # def 函数名(参数): 参数可以是多个
    a, b = 0, 1 # 函数体
    for i in range(n + 1):
        if i == n:
            print(a)
            break
        else:
            a, b = b, a + b

a = int(input())
fib(a)
a = int(input())
fib(a)
```


封装成函数之后，我们想要求斐波那契数列的时候，就可以直接fib(n)就行了，想要看第几项，n就填多少

### 11. 复杂输出

#### 11.1. 占位输出

如果我们想输出这样一句话：“我叫\*\*，我今年\*岁了”

当然，这里的名字和年龄是由我们输入

我们可以使用占位符或者.format函数

```python
Name = input()
year = int(input())

print(f"我叫{Name}，我今年{year}岁了")

print("我叫{}，我今年{}岁了".format(Name, year))
```

如果我们想要输出一个小数，但是我们只想要小数点后3位，就可以这么写

```python
pi = 3.141592653
print(f"{pi:.2f}")
```

#### 11.2. 手动格式化输出字符串

我想输出一个九九乘法表，我可以这么写

```python
for i in range(1, 10):
    for j in range(1, i + 1):
        print(f"{j}*{i}={i * j}".ljust(7), end=' ')
    print("")
```

str.ljust()函数是将元素左对齐，并自动在右边空白处补充空格。如果在空格当中填上7，输出一个长度为3的字符串，则会在右侧补充4个空格

同样的，str.rjust()就是相反，右对齐并在左侧填充空格

str.center()则是居中，并在两侧填充空格
