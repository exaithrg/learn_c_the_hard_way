# RELEARN_C
**C语言给了你穿越抽象假象的力量，将你从愚昧中解放出来。**

## prac0

无压力，我就是在Linux真机上开发的。

## prac1

```
make ex1
CFLAGS="-Wall" make ex1
man 3 puts
```

## prac2

![image-20230225164226778](relearn_c.assets/image-20230225164226778.png)

```
永远记住要缩进，以及如果你得到了像这种奇奇怪怪的错误，应该复查你是否都使用了 TAB 字符，由于一些make的变种十分挑剔。
$ make clean
Makefile:4: *** missing separator.  Stop.
man make
man cc
cc=gcc(?)
which cc
```

## prac3

No comments

## parc4

什么是valgrind？

这个可以用apt install安装，但是人家推荐：

```
# 1) Download it (use wget if you don't have curl)
curl -O http://valgrind.org/downloads/valgrind-3.6.1.tar.bz2

# use md5sum to make sure it matches the one on the site
md5sum valgrind-3.6.1.tar.bz2

# 2) Unpack it.
tar -xjvf valgrind-3.6.1.tar.bz2

# cd into the newly created directory
cd valgrind-3.6.1

# 3) configure it
./configure

# 4) make it
make

# 5) install it (need root)
sudo make install
```

下载下来的文件没法用，是个错误文件，放弃。

```
valgrind-3.6.1.tar.bz2
➜  valgrind bzip2 -df valgrind-3.6.1.tar.bz2
➜  valgrind tar -xvf valgrind-3.6.1.tar
tar: This does not look like a tar archive
tar: Exiting with failure status due to previous errors
➜  valgrind xo .
➜  valgrind
```

```
sudo apt install valgrind
sudo apt install aptitude
sudo aptitude install valgrind
先n再y，降级一些软件包
```

![image-20230225171310900](relearn_c.assets/image-20230225171310900.png)

> - 无论什么时候你运行C程序并且使它工作，都应该使用`Valgrind`重新运行它来检查。
> - 对于得到的每个错误，找到“源码:行数”提示的位置，然后修复它。你可以上网搜索错误信息，来弄清楚它的意思。
> - 一旦你的程序在`Valgrind`下不出现任何错误信息，应该就好了。你可能学会了如何编写代码的一些技巧。

**注意：我设了一个vg的alias，意思是valgrind**

## ex5

No comments

## ex6

![image-20230225191224406](relearn_c.assets/image-20230225191224406.png)

![image-20230225191236957](relearn_c.assets/image-20230225191236957.png)

![image-20230225191254242](relearn_c.assets/image-20230225191254242.png)

## ex7

no comments

## ex8

![image-20230225193004444](relearn_c.assets/image-20230225193004444.png)

![image-20230225193539787](relearn_c.assets/image-20230225193539787.png)

## ex9

![image-20230225194035098](relearn_c.assets/image-20230225194035098.png)

第一次遇到不确定的

![image-20230225194222827](relearn_c.assets/image-20230225194222827.png)

![image-20230225194328661](relearn_c.assets/image-20230225194328661.png)

这说明了很多问题

C初始化int数组的时候，如果设{0}，那就是全部初始化为0，如果设其他的，那就是第一个是那个其他的，其他的还是0.如下：

![image-20230225194534232](relearn_c.assets/image-20230225194534232.png)

![image-20230225194548443](relearn_c.assets/image-20230225194548443.png)

## ex10

- 查询`NULL`是什么东西，尝试将它用做`states`的一个元素，看看它会打印出什么。

**NULL是个空指针**。

- 看看你是否能在打印之前将`states`的一个元素赋值给`argv`中的元素，再试试相反的操作。

可以的

argc是argv中字符的个数，argv是一个字符串的数组。

![image-20230225195619036](relearn_c.assets/image-20230225195619036.png)

## ex11

no comments

## ex12

no comments

## ex13

![image-20230225202536776](relearn_c.assets/image-20230225202536776.png)

![image-20230225202542743](relearn_c.assets/image-20230225202542743.png)

![image-20230225202557974](relearn_c.assets/image-20230225202557974.png)

![image-20230225202628050](relearn_c.assets/image-20230225202628050.png)

**大写转小写的用法**

![image-20230225203518839](relearn_c.assets/image-20230225203518839.png)

![image-20230225203510079](relearn_c.assets/image-20230225203510079.png)

## ex14

主要是用到了ctype.h里面的isprint函数。

函数	功能
isalnum	检查 ch 是否为字母或数字
isalpha	检查 ch 是否为字母
isblank (C++11 only)	检查 ch 是否为’\t’ 或 ’ ’
iscntrl	检查 ch 是否为控制字符（ ASCII值在 0 ~ 31）
isdigit	检查 ch 是否为数字（ ‘0’ ~ ‘9’ ）
isgraph	检查 ch 是否为可显示字符，不包括空格
islower	检查 ch 是否为小写字母（‘a’ ~ ‘z’）
isprint	检查 ch 是否为可打印字符，包括空格
ispunct	检查 ch 是否为标点字符，即除字母，数字和空格以外的所有可打印字符
isspace	检查 ch 是否为 ’ ', ‘\t’, ‘\n’, ‘\v’, ‘\f’, ‘\r’
isupper	检查 ch 是否为大写字母（‘A’ ~ ‘Z’）
isxdigit	检查 ch 是否为一个 16 进制的数学字符（即 ‘0’ ~ ‘9’ 或 ‘A’ ~ ‘F’ 或 ‘a’ - ‘f’）
tolower	将 ch 字符转换成小写字母
toupper	将 ch 字符转换成大写字母
————————————————
版权声明：本文为CSDN博主「ultraji」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_23827747/article/details/79705576

## ex15

重要：指针语料库

现在我打算向你提供一个词库，用于读写指针。当你遇到复杂的指针语句时，试着参考它并且逐字拆分语句（或者不要使用这个语句，因为有可能并不好）：

```
type *ptr
```

`type`类型的指针，名为`ptr`。

```
*ptr
```

`ptr`所指向位置的值。

```
*(ptr + i)
```

（`ptr`所指向位置加上`i`）的值。

> 译者注：以字节为单位的话，应该是`ptr`所指向的位置再加上`sizeof(type) * i`。

```
&thing
```

`thing`的地址。

```
type *ptr = &thing
```

名为`ptr`，`type`类型的指针，值设置为`thing`的地址。

```
ptr++
```

自增`ptr`指向的位置。

我们将会使用这份简单的词库来拆解这本书中所有的指针用例。

无论怎么样，你都不应该把指针和数组混为一谈。它们并不是相同的东西，即使C让你以一些相同的方法来使用它们。例如，如果你访问上面代码中的`sizeof(cur_age)`，你会得到指针的大小，而不是它指向数组的大小。如果你想得到整个数组的大小，你应该使用数组的名称`age`，就像第12行那样。

> 译者注，除了`sizeof`、`&`操作和声明之外，数组名称都会被编译器推导为指向其首个元素的指针。对于这些情况，不要用“是”这个词，而是要用“推导”。

另外，如果要打印指针，应该使用printf `%p`

**特别注意，即使i在自增1，指针也不是自增1，好像是自增sizeof(xx)**

代码：

![image-20230225205831645](relearn_c.assets/image-20230225205831645.png)

输出：

![image-20230225205851109](relearn_c.assets/image-20230225205851109.png)

## ex16



# Appendix

## Zed的强大调试宏

https://www.cntofu.com/book/25/ex20.md

**或许可以用于大型C项目的维护工作**

```c
#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
```



## 学习Python

笨办法学python：https://learnpythonthehardway.org/

