[toc]

# 说明
实现堆的数据结构，但不能输入成员比较函数，自定义比较需要封装元素。

```Python
heap = []
heappush(heap,item)        # 加入一个值
item = heappop(heap)    # 弹出最小值
item = heap[0]                # 查看最小值
heapify(x)                        # 将list堆化
item = heapreplace(heap,item)         # 先pop，再push
item = heappushpop(heap, item)     # 先push，再pop
```
+ heapreplace和heappushpop的细微差别
+ 无法自定义比较函数 

# 参考

[python中heapq堆的讲解 python中heapq堆的讲解 ](http://www.cnblogs.com/chang1203/p/6537345.html)
