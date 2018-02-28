'''
Created on 31.01.2018

@author: Arbeit
'''
import numpy as np

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
		parent is the parent node
    '''
    x=0
    y=0
    
    orientation=0
    parent=null
	

    def __init__(self, x_coor, y_coor, orientation,parent):
        '''
        Constructor
        '''
		self.x=x_coor
		self.y=y_coor
		self.orientation=orientation
		self.parent=parent
	
	def get_x(self)
		return self.x 
	def get_y(self)
		return self.y
	def get_orientation(self)
		return self.orientation
	def get_parent(self)
		return self.parent
    def set_x(self, x)
		self.x=x
	def set_y(self,y)
		self.y=y
	def set_orientation(self, orientation)
		self.orientation=orientation
	def set_parent(self, parent)
		self.parent=parent
	"""TODO hgierhin oder zum calculator?"""
	def is_reachable(self, parent_node)
		direction_vector_x=self.x-parent_node.x
		direction_vector_y=self.y-parent_node.y
		
		cos_dir_vec= 
	def set_orientation(self,parent_node)
	