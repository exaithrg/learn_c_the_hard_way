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



# 学习Python

笨办法学python：https://learnpythonthehardway.org/

