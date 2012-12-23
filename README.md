WinZlog
=======

Zlog on Windows

在zlog Linux版https://github.com/HardySimpson/zlog
和Windows上的移植https://github.com/pattheaux/zlog
的基础上使用VS2010建立的完整工程。

Release文件夹下有VS2010编译生成的.lib和.dll及zlog头文件可以根据zlog文档直接在使用。


依赖两个库
Requires the glob function from the Unixem project: 
http://synesis.com.au/software/unixem.html 
Requires the pthreads-win32 library: 
http://sources.redhat.com/pthreads-win32/

工程目录
├─extlib  依赖的两个库
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
├─Release  VS2010编译生成的.lib和.dll及zlog头文件
│  ├─demo
│  ├─dll
│  ├─head
│  └─lib
├─test   测试工程
│  ├─Debug
│  └─Release
└─zlog    VS2010工程
    ├─Debug
    ├─dll
    ├─doc
    ├─lib
    ├─Release
    ├─src
    ├─test
    └─tools

