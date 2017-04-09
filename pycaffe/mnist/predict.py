'''使用mnist网络预测图片的字符'''

import caffe
import numpy as np
import matplotlib.pyplot as plt

def model():
    '''返回lenet模型'''
    return caffe.Net('deploy.prototxt', r'./result_iter_10000.caffemodel',  caffe.TEST)

def preprocess(im):
    '''预处理图片，使图片数据满足输入要求'''
    from skimage import transform, color
    
    im = color.rgb2gray(transform.resize(im, (28,28))) # 调大小

    im = im.reshape(im.shape + (1,))    # 增加一维，
    im = np.transpose(im, (2,0,1))      # 调整各维分布

    return im 

def predict(pic):
    
    # caffe.set_mode_gpu()  # 设置gpu模式

    net = model()

    # 设置输入数据
    net.blobs['data'].data[...] = preprocess(caffe.io.load_image(pic))

    # 向前计算，并获得输出数据
    output = net.forward()
    prob = output['prob'][0]

    # 返回前三名的编号和概率
    tops = prob.argsort()[::-1][:3]
    return list(zip(tops, prob[tops]))


if __name__ == '__main__':
    import sys

    pic = "test.bmp" if len(sys.argv) < 2 else sys.argv[1]
    result = predict(pic)
    print(result)
