'''使用mnist网络预测图片的字符'''

import caffe

def get_net():
    '''返回lenet模型'''
    return caffe.Net('test.prototxt', r'./result_iter_10000.caffemodel', caffe.TEST)


def test():

    net = get_net()

    net.blobs['data'].reshape(100, 1, 28, 28)

    accuracy = 0
    for i in range(100):
        output = net.forward()
        accuracy += output['accuracy']*100
    
    print(accuracy / (100*100))

    
if __name__ == '__main__':
    test()