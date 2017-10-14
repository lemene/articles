# 对象的__xxx__简介

## 概述

## __class__
对象的类，调用它等同于调用类。

```Python
class A:
  def __init__(self, s): print(s)

a = A("a")		# a.__class__ 为 <class '__main__.A'>
b = a.__class__("b")	# 等价 b = A("b")
```

## __delattr__(self, attr)
响应内置函数delattr，删除对象的某个属性。

```Python
class A:
  def __init__(self, n): self.name = n
  def __delattr__(self, n): 
    print("delattr")
    super().__delattr__(n)

a = A("a")
a.name			# 显示 "a"
delattr(a, "name")      # 等价 a.__delattr__("name")
a.name               	# 报错
```

## 
## __len__(self)
响应len关键字

```Python
class A:
  def __len__(self): return 1

len(A()) 	# return 1
```

## __contains__(self, e)
响应in关键字，判断元素是否属于某个集合。

```Python
class A:
  def __contains__(self, e): return e == 1

1 in A() 	# 返回 True
2 in A()        # 返回 False
```

## __hash__(self)
响应hash关键字，计算对象的hash值
```Python
class A:
  def __hash__(self): return 3

hash(A())	# 返回 3
