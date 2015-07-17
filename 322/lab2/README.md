# Launch-Tube

Used <a href="https://stackoverflow.com/questions/5206840/duplicating-an-array-of-strings-or-copying-them-to-another-array/5206927#5206927">this</a> code snippet found here for copying the argv array

====================================================

### DESCRIPTION

LAUNCH:
A command-line tool written in C that launches another process (child process). This child process executes a particular program.

TUBE:
A command-line tool written in C that launches two child processes, and sets up a pipe between them for inter-process communication.

====================================================

### USAGE & SAMPLE OUTPUT

##### LAUNCH

Usage
```bash
$ ./launch /path/to/command
```

Sample
```bash
$ ./launch /bin/ls -l
/bin/ls $$ 5011
total 64
-rwxrwxr-x. 1 usr1 usr1 11340 Sep 20 12:23 launch
-rw-rw-r--. 1 usr1 usr1   864 Sep 18 19:48 launch.c
-rw-rw-r--. 1 usr1 usr1  6976 Sep 20 12:23 launch.o
-rw-rw-r--. 1 usr1 usr1  1107 Sep 11 20:53 LICENSE
-rw-rw-r--. 1 usr1 usr1   427 Sep 18 19:45 Makefile
-rw-rw-r--. 1 usr1 usr1   830 Sep 18 19:49 README
-rwxrwxr-x. 1 usr1 usr1 12123 Sep 20 12:23 tube
-rw-rw-r--. 1 usr1 usr1  1890 Sep 20 12:20 tube.c
-rw-rw-r--. 1 usr1 usr1  9328 Sep 20 12:23 tube.o
/bin/ls $? 0
```
##### TUBE
Usage
```bash
$ ./tube /path/to/command1 , /path/to/command2
```
Sample
```bash
$ cat filename
This is line one.
This is line two.
This is line three.
This is line four.

$ ./tube /bin/cat filename , /usr/bin/head -2

/bin/cat 	      $$ 1934
/usr/bin/head  	$$ 1935
This is line one.
This is line two.
/bin/cat 	      $? 0
/usr/bin/head  	$? 0
```

====================================================

### STATUS
Complete
