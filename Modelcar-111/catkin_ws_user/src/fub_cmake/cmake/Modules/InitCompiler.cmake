# force a default build type, unless specified otherwise
IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
	  "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
	  FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

INCLUDE(AddUniqueFlags)

ADD_UNIQUE_FLAGS(CMAKE_CXX_FLAGS
	# set C++11 as standard
	-std=c++11

	# change all warnings to errors to enforce better code
	-Werror

	# abort compilation on first error (prevents multiple errors to be shown)
	-Wfatal-errors

	# enable warnings (ref. https://gcc.gnu.org/onlinedocs/gcc-4.8.3/gcc/Warning-Options.html#Warning-Options)
	-Wall
	-Wextra


	-Wsign-promo                       # warn when overload resolution chooses a promotion from unsigned or
	                                   # enumerated type to a signed type, over a conversion to an unsigned
	                                   # type of the same size. Previous versions of G++ would try to pre-
	                                   # serve unsignedness, but the standard mandates the current behavior.


	-Wpointer-arith                    # warn about anything that depends on the “size of” a function type or of void


	-Wcast-qual                        # warn whenever a pointer is cast so as to remove a type qualifier from the target type

	-Woverloaded-virtual               # warn against hiding a base class's virtual function

	-Winit-self                        # warn about uninitialized variables that are initialized with themselves

	-Winvalid-pch                      # warn if a precompiled header is found in the search path but can't be used

	-Wlogical-op                       # warn about suspicious uses of logical operators in expressions. This
	                                   # includes using logical operators in contexts where a bit-wise operator
	                                   # is likely to be expected.

	-Wstrict-null-sentinel             # warn about the use of an uncasted NULL as sentinel


	-Wformat-security                  # If -Wformat is specified (part of -Wall), also warn about uses of format
	-Werror=format-security            # functions that represent possible security problems. At present, this warns
	                                   # about calls to printf and scanf functions where the format string is not a
	                                   # string literal and there are no format arguments, as in printf (foo);. This
	                                   # may be a security hole if the format string came from untrusted input and
	                                   # contains ‘%n’.

	-Wswitch-default                   # Warn whenever a switch statement does not have a default case.

	-Wswitch-enum                      # warn whenever a switch statement has an index of enumerated type and lacks a case
	                                   # for one or more of the named codes of that enumeration. case labels outside the
	                                   # enumeration range also provoke warnings when this option is used. The only difference
	                                   # between -Wswitch and this option is that this option gives a warning about an omitted
	                                   # enumeration code even if there is a default label.

	# disable some warnings again (enabled as part of -Wall, -Wextra, ...)
	-Wno-reorder
	-Wno-unused-variable
	-Wno-unused-function
	-Wno-unused-parameter
	-Wno-unused-local-typedefs
	-Wno-sign-compare
	-Wno-long-long                     # don't complain about long long
	-Wno-missing-field-initializers    # allow implicit zero initialization
	-Wno-unknown-warning-option        # do not throw errors for warnings that clang doesnt support
	-Wno-deprecated-declarations
	-Wno-missing-braces
	-Wno-format-security
)
