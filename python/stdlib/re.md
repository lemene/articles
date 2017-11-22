# 正则表达式

## 表达式语法



## compile(pattern, flags=0)
返回Pattern对象

## escape(pattern)
转义特殊意义的字符，如将'['转义成'\['，可以简化pattern

```Python
p0 = re.compile('[01]')
p1 = re.compile(re.escape('[01]'))

p0.search('[01]')   # 匹配 '0'
p1.search('[01]')   # 匹配 '[01]'
```

## template(pattern, flags=0)

```Python
re.template("abc") == re.compile("abc")             # 返回：False
re.template("abc") == re.compile("abc", re.T)       # 返回：True
```
### match(pattern, string, flags=0)
匹配一个字符串的头部

```Python
re.match('\d+', "123abc")   # 返回Match对象，等价re.search('^\d+', "123abc")
re.match('\d+', "a123abc")  # 返回None
```
+ `re.search('^...',,)`和`re.match('...',,)`在`flags`设置了多行模式的行为不同。

### fullmatch(pattern, string, flags=0)
匹配整个字符串，注意和`match`的区别

```Python
re.fullmatch('\d+', "1234")   # 返回匹配'1234'的Match对象
re.fullmatch('\d+', "123a")   # 返回None
re.match('\d+', "123a")   # 返回匹配'123'的Match对象
```

### search(pattern, string, flags=0)
在字符串中查找模式，只返回第一个或者None

```Python
re.match('\d+', "a123abc456")  # 返回匹配'123'的Match对象
re.match('\d+', "abcdef")      # None
```
`
### findall(pattern, string, flags=0)
找出所有匹配pattern的子串，如果分组则会返回所有分组（参考Pattern）。

```Python
re.findall("\d+", "123abc456efg")  # 返回 [123, 456]
re.findall("\d+", "abcdef")  # 返回 []
re.findall("\d+([a-z])", "123abc456efg")    # 返回 [a, e]
re.findall("(\d+)([a-z])", "123abc456efg")    # 返回 [(123,a), (456,e)]
```

### finditer(pattern, string, flags=0)
类似findall，但返回迭代器。迭代的元素是Match对象。

```Python
for m in re.finditer("(\d+)([a-z])", "123abc456efg"):
    print(m.groups())                       # 分别为(123,a)和(456,e)
```

### purge()
空缓存中的正则表达式，非功能函数。


### sub(pattern, repl, string, count=0, flags=0)
替换匹配的子串，返回替换后的字符串

+ repl: 替换字符，可以是字符串也可以是函数，函数参数为Match对象
+ count：最多替换几个子串

```Python
re.sub("\d+", "222", "123abc456efg")       # 返回：222abc222efg
re.sub("w", "222", "123abc456efg")         # 123abc456efg
re.sub("\d+", lambda x:x.group()[0], "123abc456efg")    # 返回：1abc4efg
re.sub("\d+", "222", "123abc456efg", 1)       # 返回：222abc456efg
re.subn("\d+", "222", "123abc456efg", 3)      # 返回：222abc222efg
```

### subn(pattern, repl, string, count=0, flags=0)
类似sub，返回(替换后的字符串, 替换次数)

+ repl, count: 同`sub`

```Python
re.sub("\d+", "222", "123abc456efg")       # 返回：(222abc222efg, 2)
re.sub("w", "222", "123abc456efg")         # 返回：(123abc456efg, 0)
re.sub("\d+", lambda x:x.group()[0], "123abc456efg")    # 返回：(1abc4efg, 2)
re.sub("\d+", "222", "123abc456efg", 1)       # 返回：(222abc456efg, 1)
re.subn("\d+", "222", "123abc456efg", 3)      # 返回：(222abc222efg, 2)
```


### split(pattern, string, maxsplit=0, flags=0)
根据正则表达式分割字符串

+ maxsplit: 最大分割数目

```Python
re.split("\d", "a1b2c3d4")      # 结果：[a, b, c, d]
re.split("\d", "a1b2c3d4", 2)      # 结果：[a, b, c3d4]
re.split("b", "1b2Bc", flags=re.I)  # 忽略大小写，结果：[1, 2, c]
```

## 参考
https://docs.python.org/3/library/re.html
http://www.cnblogs.com/Mathics/p/4041363.html
http://www.cnblogs.com/tina-python/p/5508402.html

