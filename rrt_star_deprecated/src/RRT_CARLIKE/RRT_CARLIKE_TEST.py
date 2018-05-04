'''
Created on 27.01.2018

@author: Arbeit
'''
import unittest
import numpy as np
from RRT_CARLIKE import unit_vector


class Test(unittest.TestCase):
    def setUp(self):
        vector_simple=np.array([0,2])
        vector_diagonal=np.array([1,1])
        orientation_dia=unit_vector(vector_diagonal)
        node=np.array([20.0,40.0,])
        
    def test_unit_vector(self):
        vector_simple=np.array([0,2])
        vector = unit_vector(vector_simple)
        self.assertEqual((vector, (0,1))
        


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()