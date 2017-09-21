# CSV in R

本文接收如何使用R语言处理CSV文件。
[CSV文件](https://baike.baidu.com/item/CSV/10739)近似R语言的data.frame


`read.table`和`write.table`是基本函数、其它`read.csv`、`write.csv`等是其对应的基本函数的不同默认参数的版本。

## 列名（表头）和行名
header指表头或者列名、row.names表示行名，它与`data.frame`的概念一致。注意点：

**读**
1. header：布尔数，是否将第一行视为表头。其中`read.table`默认是`FALSE`，`read.csv`默认是`True`。
2. row.names：整数，表示指定第i列为列名，默认没有设置，即没有列名
3. `read.csv`默认行为读取列名，不识别行名，但当首行元素个数=其它行元素个数+1，则会认为第一列为列名。

**写**
1. row.names：布尔数，是否记录数据行名。默认是`TRUE`。
2. col.names：布尔数，是否记录数据列名，默认是`TRUE`。
3. 如果同时记录了行名和列名，在第一行第一列的位置会保存一个空数据，用于对齐。

注意：
读3和写3所提到的特点，如果csv文件第一行第一列没有对齐的空数据，执行下面代码，`read.csv`第一次和第二次执行的结果不同，需要设置 row.names=1。

```R
data = read.csv(csv_file_name)		# 需要改为data = read.csv(csv_file_name, row_names=1)
write.csv(data, csv_file_name)
data = read.csv(csv_file_name)		# 需要改为data = read.csv(csv_file_name, row_names=1)
```


