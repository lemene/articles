import numpy as np
from numpy.linalg import norm
def dtw_distance(x,y, cost=lambda x,y: norm(x-y)):

    #M = np.zeros([len(x), len(y)])
    #for i, xi in enumerate(x):
    #    for j, yi in enumerate(y):
    #        M[i,j] = distance(xi, yi)   


    D = np.ones([len(x)+1, len(y)+1])*np.Inf
    D[0,0] = 0
    for i, xi in enumerate(x):
        for j, yi in enumerate(y):
            D[i+1,j+1] = cost(xi, yi) + min(D[i,j+1], D[i+1,j], D[i,j])

    return D[len(x), len(y)]

if __name__ == '__main__':
    x = [1,2,3,4]
    y = [2,2,3]

    print(dtw_distance(x,y))
