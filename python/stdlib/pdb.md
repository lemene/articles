# pdb

## 概述
pdb是python自带的一个包，为python程序提供一种交互的源代码调试功能，类似gdb。

## 启用方式
启用方式分为：命令行方式和嵌入代码方式，后者需要修改代码但能够直接跳转至目标位置。

**命令行方式**

    python -m pdb test.py

**嵌入代码方式**


    import pdb
    ...
    pdb.set_trace()    # 正常启动，执行到该处进入调试

    
## 调试模式下的指令
调试模式下可以执行类似gdb的指令，也可以执行合法的Python代码。

指令有
| 指令 | 缩写 | 说明 |
| - | - | - |
| break | b | 设置断点 |
| contiune | c | 继续执行程序 |
| list | l | 查看当前行的代码段 |
| step | s | 进入函数 |
| return | r | 执行代码到返回当前函数 |
| exit | q | 中止并退出 |
| next | n | 执行下一行 |
|  | p | 打印变量的值 |
| help | | 帮助 |


### pdb提供的函数




## 参考
https://docs.python.org/2/library/pdb.html
https://docs.python.org/3/library/pdb.html


