lw-clogger
==========

## Features
* Transparent logging to file/console/network/syslog.
* Support different logging levels.
* Customizable log level, module name.
* Zero performance overhead when logging is disabled.
* Simple APIs similar to printf().

## build & test
```
$ gcc test.c
$ ./a.out
[13658] INFO, 2014-09-02 00:28:10, test.c:main():19: LOG_INFO
[13658] NOTICE, 2014-09-02 00:28:10, test.c:main():20: LOG_NOTICE
[13658] INFO, 2014-09-02 00:28:10, test.c:main():24: Foo[Information                   ] Bar[10]
```