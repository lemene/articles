# itertools

## 无限迭代器
### count(start=0, step=1)
不限等差数列，如：

	start=10, step=2 --> [10, 12, 14, 16, ...]

### cycle(iterable)
循环迭代iterable，如：

	iterable = [1,2,3] --> [1,2,3,1,2,3,1,...]

### repeat(object[,times])
重复times次或无限次

	object=5 --> [5, 5, 5, 5, ...]
	object=5, times=3 --> [5, 5, 5]

##

### accumulate(iterable[, func])
逐个累加或func操作

    iterable=[1,2,3] 	-->  [1, 3, 6]
    iterable=[1,2,3], func=lambda x,y: x*y  --> [1, 2, 6]

### chain(\*iterables)
多个迭代器串行组成一个迭代器

    *iterables=[1,2,3],"ABC"  --> [1, 2, 3, 'A', 'B', 'C']

### chain.from_iterable(iterable)
类似chain，但将它的多个参数放入迭代器中，因此无需展开，可使用无限迭代器。

    iterable=[[1,2,3],"ABC"]  --> [1, 2, 3, 'A', 'B', 'C']

### compress(data, selectors)
使用selectors选择迭代的数据

    data='ABCD', selectors=[0,0,1,1] --> ['C', 'D']

### dropwhile(predicate, iterable)
使用predicate为False的之后的元素

    predicate=lambda x: x<4, iterable=[1,2,5,2,7]  -->  [5, 2, 7]

###  filterfalse(function or None, sequence)
使用predicate函数选择元素，等价compress(iterable, [not predicate(i) for i in iterate)
    
    function=None, sequence=[0, False, 1 True]  -->  [0, False]
    function=lambda x: x%2, sequence=[0,1,2,3,4,5,6]  -->  [0,2,4,6]
    
### groupby(iterable[, keyfunc])
按照keyfunc分组，返回(key, sub-iterator)

    iterable=[1,2,2]   --> (1, (1)), (2, (2,2))
    iterable=[1,2,3], keyfunc=lambda x:x>2 	--> (False, (1,2)), (True, (3))

### islice(iterable, start[, stop[, step]])
按照start,stop,step的设置去iterable的元素

    iterable="ABCDEFG", start=2  			-->  "CDEFG"
    iterable=[1,2,3,4], start=2, stop=6  		-->  "CDEF"
    iterable=[1,2,3,4], start=2  stop=6, step=2		-->  "CE"
   
### starmap(function, sequence)
类似map，可处理多参数的函数，使用`*`操作将元素展开。

    function=pow, sequence=[(2,3),(3,4),(5,6)] 	-->  [6, 12, 30]


### takewhile(predicate, iterable)
参考`dropwhile`，使用predicate为False之前的元素

    predicate=lambda x: x<4, iterable=[1,2,5,2,7]  -->  [1, 2]

### tee(iterable, n=2)
将iterable分成n个

    iterable=[1,2,3]   -->  [[1,2,3], [1,2,3]]

### zip_longest(iter1 [,iter2 [...]], [fillvalue=None])
类似zip，但zip匹配最短的，zip_longest匹配最长的，使用fillvalue填充

    iter1="ABCD", iter2="xy", fillvalue='-'  --> Ax, By, C-, D-

## 组合生成器

### product(\*iterables, repeat=1)
组合多个迭代器

### permutations(iterable[, r])
集合元素排列，r没设置则为全排列。

    iterable=ABC       --> [ABC, ACB, BAC, BCA, CAB, CBA]
    iterable=ABC, r=2  --> [AB, AC, BA, BC, CA, CB]
    iterable=ABC, r=4  --> []

### combinations(iterable, r)
迭代集合内元素的组合，r表示r个元素组合。

    iterable=ABC, r=2  -->  [AB, AC, BC]
    iterable=ABC, r=4  -->  []

### combinations_with_replacement(iterable, r)
类似`combinations`，但允许元素自己和自己组合。

    iterable=ABC, r=2  -->  [AA, AB, AC, BB, BC, CC]
    iterable=ABC, r=4  -->  []



## 参考
[10.1. itertools — Functions creating iterators for efficient looping](https://docs.python.org/3/library/itertools.html)


