# 概述
本目录存放使用pycaffe训练mnist的例子。


# 文件说明
+ create_net.py： 演示如何生成模型文件，并生成文件solver.prototxt、deploy.prototxt、train.prototxt和test.prototxt文件
+ train.py: 演示如何训练模型，会产生文件result_iter_xxxx.caffemodel和result_iter_xxxx.solverstate
+ test.py: 演示如何测试模型
+ predict.py: 演示如何使用模型
+ test.bmp: 使用mspaint绘制的数字图片

+ solver.prototxt：求解器配置文件，近似CAFFE/examples/mnist/lenet_solver.prototxt
+ deploy.prototxt：部署模型，近似CAFFE/examples/mnist/lenet.prototxt
+ train.prototxt和test.prototxt：训练模型和测试模型，近似CAFFE/examples/mnist/lenet_train_test.prototxt

+ result_iter_xxxx.caffemodel和result_iter_xxxx.solverstate: 运行train.py得到数据
+ mnist_test_lmdb和mnist_train_lmdb: mnist的训练和测试数据，参考CAFFE/examples/mnist/readme.md


