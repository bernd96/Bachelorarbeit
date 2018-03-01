import 
class calculator
	
	
	def __init__(self)
	
	def is_in_area(node, area)
		if area[0][0]<node.x<(area[0][0]+area[0][2]) and area[0][1]<node.y<(area[0][1]+area[0][3]):
        	return True
		return False
	
	def normalise(x,y)
	"""TODO verhalten bei ZeroDivision errors"""
		vector=np.array([x,y])
		try:
			unit_vector=vector/np.linalg.norm(vector)
		except ZeroDivisionError:
        	print "you cant normalise 0-vector"
        return vector