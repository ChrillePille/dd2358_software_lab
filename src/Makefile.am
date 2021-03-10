# specify executable
bin_PROGRAMS = $(top_builddir)/bin/main.out

# specify source files in current directory
__top_builddir__bin_main_out_SOURCES = main.cpp matrix.c cwblas.cpp

#specify compiler flags
__top_builddir__bin_main_out_CFLAGS = -I$(top_srcdir)/include -Wall -g -O3
__top_builddir__bin_main_out_CPPFLAGS = $(BLAS_LINKER_FLAGS)
