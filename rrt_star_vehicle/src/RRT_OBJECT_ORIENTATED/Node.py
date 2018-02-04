'''
Created on 31.01.2018

@author: Arbeit
'''

class Node(object):
    '''
    Node of the RRT
    x,y_coor is position of node
    orientation is angle of vehicle when passing the node
        0° is like(1,0)
        45° is like(1,1)
        90° is like(0,1)
        ...
        270° is like (0,-1)
    '''
    x_coor=0
    y_coor=0
    
    orientation=0
    parent=0

    def __init__(self, params):
        '''
        Constructor
        '''
        