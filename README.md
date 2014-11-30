lwlog
=====

[![Build Status](https://travis-ci.org/Akagi201/lwlog.svg?branch=master)](https://travis-ci.org/Akagi201/lwlog)

A header only, colorful, leveled, macro implemented logging lib for C.

```C
lwlog_emerg("This a emerge log.");
lwlog_alert("This a alert log.");
lwlog_crit("This a crit log.");
lwlog_err("This a err log.");
lwlog_warning("This a warning log.");
lwlog_notice("This a notice log.");
lwlog_info("This a info log.");
lwlog_debug("This a debug log.");
```

![screenshot](https://raw.github.com/Akagi201/lwlog/master/assets/lwlog.png)

## Features
* Only one header is needed.
* Colorful output to console.
* `errno` support.
* Simple APIs similar to printf().
* Support different logging levels.
* Zero performance overhead when logging is disabled.
* Customizable module name. [TODO]
* Transparent logging to file/console/network/syslog. [Maybe]

## Install

`clib install Akagi201/lwlog`

## Macro controls

* log level control
* color control

```C
#define LOG_COLOR (1) // 0: off, 1: on, default: 1
#define LOG_LEVEL (7) // -1: off, 0~7: different log levels, default: 7

#include "lwlog.h"
```

## Build & Test

```C
$ gcc test.c
$ ./a.out
```