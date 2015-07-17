# Catcher

Found sample code <a href="http://www.cs.kent.edu/~farrell/sp/lectures/signals/catch-ctrl-c.c">here</a>


====================================================

#### DESCRIPTION
A program written in C that catches registered signals.  The program prints its PID inorder to know which PID to send the signals to. When the program catches the registered signals, it writes particular information onto stdout - mainly the signal name and the epoch time. After catching three SIGTERMS in a row, the program exits.

====================================================

### USAGE & SAMPLE OUTPUT

In one terminal run
```bash
$ ./catcher <signal1> <signal2> ... <signaln>
```

In another terminal
```bash
$ kill -<signal1> <PID>
```

Example

```bash
$ ./catcher TERM USR1 USR2
./catcher: 	$$ = 6793
USR1 caught at time 1411702115
TERM caught at time 1411702126
USR2 caught at time 1411702135
TERM caught at time 1411702145
TERM caught at time 1411702147
TERM caught at time 1411702148
./catcher: Total signals caught = 6
$
```

Signals sent from different terminal
```bash
$ kill -USR1 6427
$ kill -USR2 6427
$ kill -TERM 6427
$ kill -TERM 6427
$ kill -TERM 6427
$ kill -TERM 6427
$ kill -TERM 6427
```
====================================================

### STATUS
Complete
