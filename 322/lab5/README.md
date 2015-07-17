# Paging

====================================================

### DESCRIPTION

A program written in C that calculates the page number and the offset within the page for a given virtual memory address.
This specific program assumes the machine has a 32-bit virtual address with a 4-KB page size.

====================================================

### USAGE & SAMPLE OUTPUT

Usage
```bash
./paging <address number in the 0-4294967295 range>
```
Output
```bash
$ ./paging
The address 19986 contains:
page number = 4
offset = 3602

$ ./paging 4294967296
ERROR Invalid Memory Address

$ ./paging 50000
The address 50000 contains:
page number = 12
offset = 848
```
====================================================

### STATUS
Complete
