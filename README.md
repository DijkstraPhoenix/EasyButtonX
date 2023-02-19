# EasyButtonX

### 版本 1.0.1-230219

### 简介

一个基于 EasyX 开发的按钮组件，使用时需要先安装 EasyX（推荐 IDE：visual studio 2017 及更高版本，最低可用版本 vc6.0）

由于 EasyX 限制，仅能在 windows 下使用

### 使用方法

##### 1. 将 EasyButtonX.h 放在需要引用的工程文件夹下

[![Xcg7d.md.png](https://i.328888.xyz/2023/02/19/Xcg7d.md.png)](https://imgloc.com/i/Xcg7d)

##### 2. 在需要使用 EasyButtonX 的 c++ 源代码文件中添加以下代码：

```C++
#include "EasyButtonX.h"
```

##### 3. 开始尽情的创作

### 功能大全

##### 1. 声明一个按钮：

```C++
Button 按钮名称(按钮x坐标,按钮y坐标,按钮x方向的长度,按钮y方向的长度,按钮文本,文本颜色);
```

如：

```C++
Button Mybutton(50,50,100,40,(char *)"Hello, World!",RGB(0,0,0));
```

**注意！按钮文本暂时不支持中文！**

##### 2. 获取点击信息

使用 `testpress()` 可以检测是否按下按钮，返回值保存在 `push` 变量里

如：

```C++
while(true)
{
    Mybutton.testpress();
    if(Mybutton.push)
    {
        printf("Press Button!");
    }
}
```

**请使用循环获取点击信息，否则将无法切换外观**

### 更新日志

- 2023-2-19: 首次发布 .version: 1.0.1-230219
