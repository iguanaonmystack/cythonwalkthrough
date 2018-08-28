AC_INIT([CythonWalkthrough3], 0.1)
AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CC
AC_CONFIG_FILES(Makefile)

# Check for Python development files
# From: https://stackoverflow.com/questions/5056606/how-to-use-autotools-to-build-python-interface-at-same-time-as-library
AM_PATH_PYTHON([3.4])
AC_ARG_VAR([PYTHON_INCLUDE], [Include flags for python, bypassing python-config])
AC_ARG_VAR([PYTHON_CONFIG], [Path to python-config])
AS_IF([test -z "$PYTHON_INCLUDE"], [
  AS_IF([test -z "$PYTHON_CONFIG"], [
    AC_PATH_PROGS([PYTHON_CONFIG],
                  [python$PYTHON_VERSION-config python-config],
                  [no],
                  [`dirname $PYTHON`])
    AS_IF([test "$PYTHON_CONFIG" = no], [AC_MSG_ERROR([cannot find python-config for $PYTHON.])])
  ])
  AC_MSG_CHECKING([python include flags])
  PYTHON_INCLUDE=`$PYTHON_CONFIG --includes`
  AC_MSG_RESULT([$PYTHON_INCLUDE])
])

# Check for Cython
AC_DEFUN(AC_PROG_CYTHON, [AC_CHECK_PROG(CYTHON,cython3,yes)])
AC_PROG_CYTHON
if test x"${CYTHON}" == x"yes" ; then
    AC_MSG_NOTICE([Found cython3])
else
    AC_MSG_ERROR([Cannot find cython3 tool.])
fi


AC_OUTPUT
