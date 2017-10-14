# 正则表达式

## 表达式语法

## 

### match
匹配

### search

### split(pattern, string, maxsplit=0, flags=0)
根据正则表达式分割字符串

+ pattern, string, flags: 
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

