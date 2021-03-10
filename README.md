# dd2358_software_lab

## Exercise 2
I built this system on WSL using autotools, installed with the command:
```
$ sudo apt-get install build-essential autoconf autoconf-archive autotools-dev cmake
```

Using the `autogen.sh` script we install required files to use autoconf.

Run
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
which build the whole project, and we can build the tests by invoking:
```
$ make check
```
For more verbose test output, run the `func_test` executable in `tests/`.