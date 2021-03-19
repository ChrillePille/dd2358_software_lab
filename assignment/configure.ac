AC_INIT([Assignment 3], 1.0)
: ${CFLAGS=""}

AM_INIT_AUTOMAKE([foreign])
AC_PROG_CC
AC_PROG_CXX

AC_CHECK_LIB([blas],[cblas_sgemm])

# Google Test
PKG_CHECK_MODULES([GTEST], [gtest_main])

AC_CHECK_HEADERS([cblas.h], [found_cblas_headers=yes; break;])
AS_IF([test "x$found_cblas_headers" != "xyes"],
	[AC_MSG_ERROR([Unable to find the cblas header.])])

AC_CONFIG_FILES(Makefile src/Makefile tests/Makefile)
AC_OUTPUT