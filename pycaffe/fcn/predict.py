import caffe

import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

def get_net():
    return caffe.Net(r'./deploy.prototxt', r'./fcn8s-heavy-pascal.caffemodel', caffe.TEST)

def preprocess(im):
    
    im = np.array(im, dtype=np.float32)
    im = im[:,:,::-1]
    im -= np.array((104.00698793,116.66876762,122.67891434))
    im = im.transpose((2,0,1))

    return im


def predict(pic):
    net = get_net()

    im = preprocess(caffe.io.load_image(pic)*255)
    net.blobs['data'].reshape(1, *im.shape)
    net.blobs['data'].data[...] = im

    output = net.forward()
    print(output['score'][0].argmax(axis=0))
    print(output['score'][0]-net.blobs['score'].data[0])
    help()
    out = net.blobs['score'].data[0].argmax(axis=0)
    return out
    #return output['score'][0].argmax(axis=0)

def old():
    
    # load image, switch to BGR, subtract mean, and make dims C x H x W for Caffe
    im = Image.open(r'test.jpg')

    in_ = np.array(im, dtype=np.float32)
    in_ = in_[:,:,::-1]
    in_ -= np.array((104.00698793,116.66876762,122.67891434))
    in_ = in_.transpose((2,0,1))

    #in_ = preprocess(caffe.io.load_image('test.jpg'))
    in_ = preprocess(Image.open('test.jpg'))
    net = get_net()

    net.blobs['data'].reshape(1, *in_.shape)
    net.blobs['data'].data[...] = in_
    # run net and take argmax for prediction
    net.forward()
    out = net.blobs['score'].data[0].argmax(axis=0)

    plt.imshow(out,cmap='gray');
    plt.axis('off')
    plt.savefig('test.png')
    plt.show()

if __name__ == '__main__':

    import sys

    pic = "test.jpg" if len(sys.argv) < 2 else sys.argv[1]
    result = predict(pic)

    plt.imshow(result, cmap='gray')
    plt.axis('off')
    plt.show()
    