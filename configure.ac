AC_INIT([Assignment 3], 1.0)
: ${CFLAGS=""}

AM_INIT_AUTOMAKE([foreign])
AC_PROG_CC
AC_PROG_CXX

# Google Test
PKG_CHECK_MODULES([GTEST], [gtest_main])

AC_CONFIG_FILES(Makefile src/Makefile tests/Makefile)
AC_OUTPUT