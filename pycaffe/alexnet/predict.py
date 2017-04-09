# 本文使用训练好的网络推测图片代表的数字

import numpy as np
import matplotlib.pyplot as plt
import caffe

def load_labels():
    labels = []
    with open("synset_words.txt") as f:
        for line in f:
            labels.append(line[10:])

    return np.array(labels)

def get_net():
    return caffe.Net('deploy.prototxt', r'bvlc_alexnet.caffemodel',  caffe.TEST)


def preprocess(im):
    from skimage import transform, color

    #im = 1-im
    im = transform.resize(im, (227,227))
    im = im*255

    #im = res.mean(2)
    #im = im.reshape(im.shape + (1,))
    im = np.transpose(im, (2,0,1))
    return im #im.resize(28,28,3)

def predict(pic):
    
    # caffe.set_mode_gpu()

    net = get_net()

    #net.blobs['data'].reshape(1, 3, 227, 227) # batchsize = 1

    net.blobs['data'].data[...] = preprocess(caffe.io.load_image(pic))

    output = net.forward()

    prob = output['prob'][0]
    
    labels = load_labels()

    tops = prob.argsort()[::-1][:3]
    
    return list(zip(prob[tops], load_labels()[tops]))

if __name__ == '__main__':
    import sys
    
    pic = "fish.jpg" if len(sys.argv) < 2 else sys.argv[1]

    result = predict(pic)
    print(result)

