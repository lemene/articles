
'''该文件生成mnist模型文件，演示如何使用代码构建Caffe的文件'''

import caffe

def create_net_body(n):
    '''创建网络模型主体，即不包含输入输出的网络'''
    from caffe import layers as L, params as P 
        
    n.conv1 = L.Convolution(n.data, kernel_size=5, num_output=20,  stride=1, weight_filler=dict(type='xavier'))
    n.pool1 = L.Pooling(n.conv1, kernel_size=2, stride=2, pool=P.Pooling.MAX)
    n.conv2 = L.Convolution(n.pool1, kernel_size=5, num_output=50, stride=1, weight_filler=dict(type='xavier'))    
    n.pool2 = L.Pooling(n.conv2, kernel_size=2, stride=2, pool=P.Pooling.MAX)
    n.ip1   = L.InnerProduct(n.pool2, num_output=500, weight_filler=dict(type='xavier'))
    n.relu1 = L.ReLU(n.ip1, in_place=True)
    n.ip2 = L.InnerProduct(n.relu1, num_output=10, weight_filler=dict(type='xavier'))

    return n

def create_deploy_net():
    '''创建部署模型'''

    # 建立缩写
    from caffe import layers as L, params as P 

    n = caffe.NetSpec()
    n.data = L.Input(input_param=dict(shape=dict(dim=[1, 1, 28, 28])))
    n = create_net_body(n)
    n.prob  = L.Softmax(n.ip2)

    return n

def create_train_net():
    '''创建部署模型'''

    # 建立缩写
    from caffe import layers as L, params as P 

    n = caffe.NetSpec()
    n.data, n.label = L.Data(batch_size=64, backend=P.Data.LMDB, source = 'mnist_train_lmdb',
                             transform_param=dict(scale=1./255), ntop=2)
    n = create_net_body(n)
    n.loss  = L.SoftmaxWithLoss(n.ip2, n.label)

    return n



def create_test_net():
    '''创建测试网络'''

    # 建立缩写
    from caffe import layers as L, params as P 

    n = caffe.NetSpec()

    n.data, n.label = L.Data(batch_size=64, backend=P.Data.LMDB, source = 'mnist_test_lmdb',
                             transform_param=dict(scale=1./255), ntop=2)
    n = create_net_body(n)
    n.loss  = L.SoftmaxWithLoss(n.ip2, n.label)
    n.accuracy = L.Accuracy(n.ip2, n.label)

    return n

def create_solver_config():
    '''创建求解器配置文件，本质上是proto文件和前面创建的网络有本质差别'''

    from caffe.proto import caffe_pb2

    config = caffe_pb2.SolverParameter()
    
    config.net = 'train.prototxt'
    config.max_iter = 10000
    config.display = 100
    config.power = 0.75
    
    #config.test_iter = 100

    config.test_interval = 500
    config.base_lr = 0.01
    config.momentum = 0.9
    config.weight_decay = 0.0005
    config.lr_policy = "inv"
    config.gamma = 0.0001

    config.snapshot = 5000
    config.snapshot_prefix = "result"
    config.solver_mode = 0

    return config




def write():
    with open('train.prototxt', 'w') as f:
        f.write(str(create_train_net().to_proto()))

    with open('test.prototxt', 'w') as f:
        f.write(str(create_test_net().to_proto()))

    with open('deploy.prototxt', 'w') as f:
        f.write(str(create_deploy_net().to_proto()))

    with open('solver.prototxt', 'w') as f:
        f.write(str(create_solver_config()))

if __name__ == "__main__":
    write()


    
    