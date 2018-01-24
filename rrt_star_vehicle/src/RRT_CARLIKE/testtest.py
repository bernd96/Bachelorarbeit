'''
Created on 22.12.2017

@author: Arbeit
'''
import numpy as np


if __name__ == '__main__':
    list_of_nodes = np.array([[1,2,3,4], [5,6,7,8]])
    list_of_nodes[:1,:]= 2
    print(list_of_nodes)