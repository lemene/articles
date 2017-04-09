'''使用mnist网络预测图片的字符'''

import caffe

def train():
    '''加载和测试求解器'''

    # 设置GPU
    #caffe.set_device(0)
    #caffe.set_mode_gpu()

    # 加载求解器，net是训练网络，test_nets是测试网络
    solver = caffe.SGDSolver("solver.prototxt")
     
    solver.solve()

    
if __name__ == '__main__':
    train()