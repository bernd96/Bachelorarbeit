#!/usr/bin/env python

import sys, random, math, pygame
import numpy as np
from pygame.locals import *
from math import sqrt,cos,sin,atan2
from lineIntersect import *
from numpy.lib.function_base import range
import datetime
from platform import node
from numpy import clip
import time
from unicodedata import decimal
#import matplotlib.pyplot as plt
#constants
XDIM = 960
YDIM = 640
WINSIZE = [XDIM, YDIM]
#MAX_STEERING_ANGLE_RADIUS, STEPSIZE, COS_ANGLE depending on each other. MAX_STEERING Angle is fixed, try different Stepsizes
MAX_STEERING_ANGLE_RADIUS = 4 
STEPSIZE = 7
#using cosine rule
COS_ANGLE= STEPSIZE/(2* MAX_STEERING_ANGLE_RADIUS)
""" A x B Matrix: NUM_NODES x ROWS """
NUM_NODES = 10000
ROWS = 6
RADIUS=20

START_NODE = np.array([0,YDIM/2,0,1,0,-1])
area = [(630,520,20,20)]
OBS=[(130,220,50,100)]

def is_in_area(node, area):
    if area[0][0]<node[0]<(area[0][0]+area[0][2]) and area[0][1]<node[1]<(area[0][1]+area[0][3]):
        return True
    else:
        return False
def obs_draw(pygame,screen):
    blue=(0,0,255)
    green=(0,255,0)
   # for o in OBS: 
     #   pygame.draw.rect(screen,blue,o)
    for g in area:
        pygame.draw.rect(screen, green, g)
# def reWire(list_of_nodes,newnode,pygame,screen):
#         white = 255, 240, 200
#         black = 20, 20, 40
#         for i in range(len(list_of_nodes)):
#             p = list_of_nodes[i]
#             if checkIntersect(p,newnode,OBS) and p!=newnode.parent and dist([p.x,p.y],[newnode.x,newnode.y]) <RADIUS and newnode.cost+dist([p.x,p.y],[newnode.x,newnode.y]) < p.cost:
#                 pygame.draw.line(screen,white,[p.x,p.y],[p.parent.x,p.parent.y])  
#                 p.parent = newnode
#                 p.cost=newnode.cost+dist([p.x,p.y],[newnode.x,newnode.y]) 
#                 list_of_nodes[i]=p  
#                 pygame.draw.line(screen,black,[p.x,p.y],[newnode.x,newnode.y])                    
#         return list_of_nodes
def drawSolutionPath(goal_node, list_of_nodes, pygame, screen):
    pink = 200, 20, 240
    node= goal_node
    while not node[5] == -1:
        parent=list_of_nodes[int(node[5])]

        pygame.draw.line(screen,pink,[node[0],int(node[1])],[parent[0],parent[1]],5)
        node=parent           
def unit_vector(vector):
    try:
        unitvector=vector/np.linalg.norm(vector)
    except ZeroDivisionError:
        print "you cant normalise 0-vector"
        return vector
    return unitvector
def cos_angle(v1,v2):
    v1_u = unit_vector(v1)
    v2_u = unit_vector(v2)
    #clip for rounding errors
    return np.clip(np.dot(v1_u, v2_u), -1.0, 1.0)
def project(nearest, new_node):
    #vector between list_of_nodes
    vector= new_node[:2]-nearest[:2]
  
    
    """all vectors are projected on STEPSIZE radius, also "inner" vectors!
        if you want to change it care about inner not reachable points"""
    dir_vector=STEPSIZE*unit_vector(vector)   
    new_node[:2]=dir_vector+nearest[:2]
    return new_node 
def set_parent(list_of_nodes, new_node, PARENT_FOUND,node_count):
    parent_number=0
    """linalg.norm returns length of vector (2-Norm)"""
    min_cost=np.linalg.norm(list_of_nodes[0,:2]-new_node[:2])
    for n in range(node_count):
        
        direction_vector=new_node[:2]-list_of_nodes[n,:2]
        orientation= list_of_nodes[n,3:5]
        """TODO: Punishment for hard steering or changing direction"""
        temp=np.linalg.norm(direction_vector)
        if not temp>min_cost:
            min_cost = temp
            parent_number=n
            """fehler im prgramm"""
            if cos_angle(direction_vector, orientation)>COS_ANGLE:
                #at least one valid parent node
                PARENT_FOUND=1
                #print "Parent found!"
            
                
   
    parent= list_of_nodes[parent_number]
    new_node[5]=parent_number
    #project new_node to parent node radius (stepsize)
    new_node=project(parent, new_node)
    #costs
    new_node[2]=parent[2]+STEPSIZE
    return new_node, PARENT_FOUND
def set_orientation(new_node, parent):
    """ 
    d direction unit vector
    o orientation unit vector
    """
    o= unit_vector(parent[3:5])
    d= unit_vector(new_node[:2]-parent[:2])
    orientation=np.array([0.0,0.0])
    """ Beweis der Formel siehe beiliegender Text """
    y_coor=d[0] * sqrt(1-(np.dot(o, d))**2)+o[0]*d[0]*d[1]+o[1]*(d[1]**2)
    orientation[1]=y_coor
    """
    orientation[1]==1 can result in negativ sqrt
    if ori[1]==1 ori[0]==0 anyway
    """    
    try:
        x_coor=sqrt(1-((orientation[1])**2))
        orientation[0]=x_coor
    except ArithmeticError:
        print "1^2 were bigger than one"
        orientation[1]
    """
    sqrt operations can lead to to different solutions for each x_coor and y_coor
    The correct orientation has the same angle to d as o to d (dot product is the same)
    np.around rounds to the 8th postion, needed cause IEEE Standard of representing doubles and compare them with == is error-prone
    """
    if not np.around(np.dot(orientation,d),8) == np.around(np.dot(o,d), decimals=8):
        orientation[0]= -x_coor
        if not np.around(np.dot(orientation,d),8) == np.around(np.dot(o,d), decimals=8):                
            orientation[1]=-y_coor
            if not np.around(np.dot(orientation,d),8) == np.around(np.dot(o,d), decimals=8):                    
                orientation[0]=x_coor
                if not np.around(np.dot(orientation,d),8) == np.around(np.dot(o,d), decimals=8):                        
                    print " You failed hard."
                    

    """ orientation is saved as int in list of nodes """
    #orientation = orientation*1000
    return orientation
def rewiring(list_of_nodes,node_count, new_node,pygame,screen):
    #node_count is the last added node
    ticks= time.time()
    node_number=node_count
    white=200,200,200
    black=200,20,40
    while not node_number==0:
        tticks= time.time()
        
        for n in range(node_count):
            parent=list_of_nodes[n]
            direction_vector=new_node[:2]-parent[:2]
            dist =np.linalg.norm(direction_vector)
    #        print dist, RADIUS, parent[2]+dist,new_node[2],cos_angle(direction_vector, parent[3:5])
            if dist<RADIUS:
                if parent[2]+dist<new_node[2]:
                    if cos_angle(direction_vector, parent[3:5])>COS_ANGLE:
                        drawtime= time.time()
                        #new parent found!
                        #erase old line
                        pygame.draw.line(screen,white, new_node[:2],list_of_nodes[int(new_node[5]),:2])
                        pygame.display.update()
                        #update costs
                        new_node[2] = parent[2]+dist
                        #allocate new parent and draw new line
                        new_node[5]=n
                        new_node[3:5]=set_orientation(new_node, parent)
                        #update list of nodes
                        list_of_nodes[node_number]=new_node
                        pygame.draw.line(screen, black, new_node[:2],parent[:2])
                        pygame.display.update()     
        #next node to examine: parent of last examined node
        
        node_number=int(new_node[5])
        new_node=list_of_nodes[node_number]  
        #print "Time for Node: " + str(1000*(time.time()-ticks)) + "ms, Node " + str(node_number) 
    #print "Time for Rewiring: " + str(1000*(time.time()-ticks)) + "ms" 
    return list_of_nodes
    
"""
Structure of Matrix: NUM_NODES x ROWS
    x-coordinate,int; y-coordinate,int; cost-to-node,double; orientation_x,double; orientation_y,double; parent,int;
    x-coordinate; y-coordinate; cost-to-node; orientation_x; orientation_y; parent;
    x-coordinate; y-coordinate; cost-to-node; orientation_x; orientation_y; parent;
    ...
"""      

def main():
    #initialize and prepare screen
    """TODO always giving list_of_nodes as parameter neccessary?"""
    pygame.init()
    screen = pygame.display.set_mode(WINSIZE)
    pygame.display.set_caption('RRTstar')
    white = 255, 255, 255
    black = 20, 20, 40
    screen.fill(white)
    obs_draw(pygame,screen)

    list_of_nodes = np.zeros((NUM_NODES,ROWS))
    #to be defined: delete invalid list_of_nodes or safe them for later?
    startticks= time.time()
    list_of_nodes[0]=START_NODE
    counter=0
    iteraterationticks = time.time()
    for node_count in range(list_of_nodes.shape[0]-1):
        PARENT_FOUND = 0
        while not PARENT_FOUND:
            """not random, but gauss-verteilt between start and goal (start-goal line expectationvalue)"""
            x_coor= int(random.random()*XDIM)
            y_coor= int(random.random()*YDIM)
            #for beginning [x,y] sufficent, better arithmetic performance? Check cost of slicing, node || node[:2]
            new_node= np.array([x_coor, y_coor,0.0,0.0,0.0,0.0])
            #project new node to parent
            """PARENT_FOUND needed because of possible invalid nodes"""
            new_node, PARENT_FOUND=set_parent(list_of_nodes,new_node, PARENT_FOUND,node_count+1)
           
        #set orientation
        new_node[3:5]=set_orientation(new_node, list_of_nodes[int(new_node[5])])
        #append new node
        list_of_nodes[node_count+1] = new_node
        pygame.draw.line(screen,black,[list_of_nodes[int(new_node[5]),0],list_of_nodes[int(new_node[5]),1]],[int(new_node[0]),int(new_node[1])])
        pygame.display.update()
        if is_in_area(new_node, area):
            drawSolutionPath(new_node, list_of_nodes, pygame, screen)
            pygame.display.update()
            goal_node=new_node
            break
        for e in pygame.event.get():
            if e.type == QUIT or (e.type == KEYUP and e.key == K_ESCAPE):
                sys.exit("Leaving because you requested it.")
        if counter==10:
            list_of_nodes=rewiring(list_of_nodes, node_count, new_node, pygame, screen)
            counter=0
        counter=counter+1
        if node_count % 500 ==0:
            print "Time for "+str(node_count)+" iteration:" + str((time.time()-iteraterationticks)) + "s"
            iteraterationticks = time.time()
        
    #print list_of_nodes[:10]
    print "Time for full algorithm: " + str(time.time()-startticks) + " seconds."
    """ Approach
    for n in list_of_nodes
        add random in list_of_nodes
        create normalized node & compute orientation
        find best node
        rewiring
        select_random_node    
    """
    
    
#     #list_of_nodes.append(Node(XDIM/2.0,YDIM/2.0)) # Start in the center
#     list_of_nodes.append(Node(0.0,160.0)) # Start in the corner
#     start=list_of_nodes[0]
#     goal=Node(275.0,270.0)
#     for node_count in range(NUMNODES):
#         rand = Node(random.random()*XDIM, random.random()*YDIM)
#         nn = list_of_nodes[0]
#         for p in list_of_nodes:
#             if dist([p.x,p.y],[rand.x,rand.y]) < dist([nn.x,nn.y],[rand.x,rand.y]):
#                 nn = p
#         interpolatedNode= step_from_to([nn.x,nn.y],[rand.x,rand.y])
#     
#         newnode = Node(interpolatedNode[0],interpolatedNode[1])
#         if checkIntersect(nn,rand,OBS):
#             [newnode,nn]=chooseParent(nn,newnode,list_of_nodes);
#             list_of_nodes.append(newnode)
#             pygame.draw.line(screen,black,[nn.x,nn.y],[newnode.x,newnode.y])
#             list_of_nodes=reWire(list_of_nodes,newnode,pygame,screen)
#             pygame.display.update()
#         #print node_count, "    ", list_of_nodes
#         for e in pygame.event.get():
#             if e.type == QUIT or (e.type == KEYUP and e.key == K_ESCAPE):
#                 sys.exit("Leaving because you requested it.")
#     drawSolutionPath(start,goal,list_of_nodes,pygame,screen)
#     pygame.display.update()
# if python says run, then we should run
if __name__ == '__main__':
    main()
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False



