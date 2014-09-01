lw-clogger 
==========

[![Build Status](https://travis-ci.org/Akagi201/lw-clogger.svg)](https://travis-ci.org/Akagi201/lw-clogger)

## Features
* Simple APIs similar to printf().
* Support different logging levels.
* Zero performance overhead when logging is disabled.
* Transparent logging to file/console/network/syslog. [TODO]
* Customizable module name. [TODO]

## Macros
* CLOG_SILENT: on/off lw-clogger's own error message.
* CLOG_MAX_MSG_LEN: max print message length.

## build & test
```
$ gcc test.c
$ ./a.out
[13658] INFO, 2014-09-02 00:28:10, test.c:main():19: LOG_INFO
[13658] NOTICE, 2014-09-02 00:28:10, test.c:main():20: LOG_NOTICE
[13658] INFO, 2014-09-02 00:28:10, test.c:main():24: Foo[Information                   ] Bar[10]
```