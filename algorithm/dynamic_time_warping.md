# Dynamic Time Warping 动态时间规整算法


DTW是衡量两个时间序列的相似度（**距离**）的方法，常用比较两个语言序列或动作序列的相似性。

这里我们将两条序列记为：

$$
X = x_1, x_2, ..., x_m  \\
Y = y_1, y_2, ..., y_n
$$

距离则理解为把一条序列转变成另一条序列的**最小'代价'**，如图：
![](https://en.wikipedia.org/wiki/File:Dynamic_time_warping.png)

序列点转换代价定义为两点之间的距离$||x_i-y_j||$，进而定义转换代价矩阵$M = (||x_i-y_j||)_{n \times m} $。
在矩阵$M$上寻找**归整路径（Warp path）**，
$$ W= \{w_k=(i_k,j_k)\}_{k=1,2,...,s},\ \ s=\max(m,n)$$
它需要满足：
$$
i_1 = 1, \ i_k \le i_{k+1} \le i_k+1, \ i_s = m \\
j_1 = 1, \ j_k \le j_{k+1} \le j_k+1, \ j_s = n \\
$$

每条路径代表一种转换方式，则两条序列的距离定义为：
$$ D(X,Y)=\min_{W}(\sum_{(i,j)\in W}||x_i-y_j||))$$

上述问题可以转换成下面的式子，通过动态规划求解，算法类似[最长公共子序列](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem)。
$$D(X,Y) = D(m,n) \\    
D(i,j) = ||x_i-y_j|| + \min(D(i-1,j),D(i,j-1),D(i-1,j-1)) \\
D(1,1) = ||x_1-y_1||
D[0,1:n] = inf \ D[1:m,0] = inf \ D[0,0] = 0
$$
如下图
![](http://images.cnitblog.com/blog/434101/201305/09145159-11a439ce088840818b5e314bf12d2ef4.jpg)

## 实现

[参考代码](./dynamic_time_warping.py)

## 参考
https://en.wikipedia.org/wiki/Dynamic_time_warping
http://blog.csdn.net/u012878609/article/details/48787249
