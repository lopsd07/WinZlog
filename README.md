WinZlog
=================

##Zlog on Windows

- The original Linux version https://github.com/HardySimpson/zlog
- This repo based on the WinZlog https://github.com/lopsd07/WinZlog

I have fixed an crash issue and upgrade the solution to `Visual Studio 2015`.   

Release文件夹下有VS2015编译生成的`.lib`和`.dll`及zlog头文件可以根据zlog文档直接在使用。

编译工程依赖两个库：

Requires the glob function from the Unixem project: 
http://synesis.com.au/software/unixem.html 

Requires the pthreads-win32 library: 
http://www.sourceware.org/pthreads-win32/

Project tree

    ├─extlib  Requires libs
    │  ├─Pre-built.2
    │  │  ├─dll
    │  │  │  ├─x64
    │  │  │  └─x86
    │  │  ├─include
    │  │  └─lib
    │  │      ├─x64
    │  │      └─x86
    │  └─unixem-1.9.1
    │      ├─build
    │      ├─doc
    │      │  └─html
    │      │      └─1.9.1
    │      ├─include
    │      ├─include_error
    │      ├─lib
    │      ├─src
    │      │  └─internal
    │      └─test
    ├─Release  VS2010 output .lib .dll and zlog include file
    │  ├─bin
    │  ├─demo
    │  ├─head
    │  └─lib
    ├─test   
    └─zlog   VS2010 Project
    ├─bin
    ├─doc
    ├─lib
    ├─Release
    ├─src
    ├─test
    └─tools
