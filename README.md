# dd2358_software_lab

I built this system on WSL using autotools, installed with the command:
```
$ sudo apt-get install build-essential autoconf autoconf-archive autotools-dev cmake pkg-config
```

Make sure to install dependencies also:
```
$ sudo apt-get install libopenblas-dev libgtest-dev libgmock-dev gnuplot-qt
```

## Exercise 1
No code. Refer to report.

## Exercise 2

Using the `autogen.sh` script we install required files to use autoconf.

After entering the `assignment/` directory, run
```
$ ./autogen.sh
```
after which we run the `configure` script
```
$ ./configure
```
which lets us invoke
```
$ make
```
which builds the whole project. We can build the tests by invoking:
```
$ make check
```
For more verbose test output, run the `func_test` executable in `tests/`.
```
$ ./tests/func_test
```

## Exercise 3
Install openblas with
```
$ sudo apt-get install libopenblas-dev
```
To run the test suite, run the `func_test` executable in `tests/` with the `--gtest_also_run_disabled_tests` option enabled:
```
$ ./tests/func_test --gtest_also_run_disabled_tests
```

To run the experiment, run the following in the `assignment/` directory: 
```
$ ./src/run.sh bin/main.out bin/naive_perf.dat bin/cblas_perf.dat
```
Which will produce both data sets in parallel. Plotting this data can be done by:
```
$ cd bin
$ gnuplot exec_time_plot.gp
$ gnuplot flops_plot.gp
```


## Exercise 4