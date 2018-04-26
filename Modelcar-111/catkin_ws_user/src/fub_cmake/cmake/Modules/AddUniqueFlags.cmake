# Macro to add parameters to a list, and to remove duplicates.
# Call as e.g.
#    ADD_UNIQUE_FLAGS(EXISTING_LIST -a -b -c)
# to add the argument -a, -b and -c to ${EXISTING_LIST}

function(ADD_UNIQUE_FLAGS flags)
	# create a list with both the old and the new flags
	set(flag_list ${${flags}} ${ARGN})
	separate_arguments(flag_list)

	list(REMOVE_DUPLICATES flag_list)

	# convert back to string
	string(REPLACE "\n" "" flag_string "${flag_list}")
	string(REPLACE ";" " " flag_string "${flag_string}")

	# set value
	SET(${flags} "${flag_string}" PARENT_SCOPE)
endfunction()
