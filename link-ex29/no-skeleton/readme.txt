# compile the lib file and make the .so
# you may need -fPIC here on some platforms. add that if you get an error
$ cc -c libex29.c -o libex29.o
$ cc -shared -o libex29.so libex29.o

# make the loader program
$ cc -Wall -g -DNDEBUG ex29.c -ldl -o ex29

# try it out with some things that work
$ ex29 ./libex29.so print_a_message "hello there"
-bash: ex29: command not found
$ ./ex29 ./libex29.so print_a_message "hello there"
A STRING: hello there
$ ./ex29 ./libex29.so uppercase "hello there"
HELLO THERE
$ ./ex29 ./libex29.so lowercase "HELLO tHeRe"
hello there
$ ./ex29 ./libex29.so fail_on_purpose "i fail"
[ERROR] (ex29.c:23: errno: None) Function fail_on_purpose return 1 for data: i fail

# try to give it bad args
$ ./ex29 ./libex29.so fail_on_purpose
[ERROR] (ex29.c:11: errno: None) USAGE: ex29 libex29.so function data

# try calling a function that is not there
$ ./ex29 ./libex29.so adfasfasdf asdfadff
[ERROR] (ex29.c:20: errno: None) Did not find adfasfasdf
  function in the library libex29.so: dlsym(0x1076009b0, adfasfasdf): symbol not found

# try loading a .so that is not there
$ ./ex29 ./libex.so adfasfasdf asdfadfas
[ERROR] (ex29.c:17: errno: No such file or directory) Failed to open
    the library libex.so: dlopen(libex.so, 2): image not found
$
注

有时候你像往常一样运行cc -Wall -g -DNDEBUG -ldl ex29.c -o ex29，并且认为它能够正常工作，但是没有。在一些平台上，参数的顺序会影响到它是否生效，这也没什么理由。在Debian或者Ubuntu中你需要执行cc -Wall -g -DNDEBUG ex29.c -ldl -o ex29，这是唯一的方式。所以虽然我在这里使用了OSX，但是以后如果你链接动态库的时候它找不到某个函数，要试着自己解决问题。

这里面比较麻烦的事情是，实际平台的不同会影响到命令参数的顺序。将-ldl放到某个位置没有理由与其它位置不同。它只是一个选项，还需要了解这些简直是太气人了。
