/*
 * @file lw-clogger.h
 * 
 * @author Akagi201
 * @date 2014/09/01
 * 
 * A header only, extreme light weight logger for C.
 */

#ifndef LW_CLOGGER_H_
#define LW_CLOGGER_H_ (1)

#include <syslog.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/* the same as syslog */
const char * const CLOG_LEVEL_CHARS[] = {
		"EMERG",
		"ALERT",
		"CRIT",
		"ERR",
		"WARNING",
		"NOTICE",
		"INFO",
		"DEBUG"
		
};

#define CLOG_MAX_MSG_LEN (1024)

typedef struct _clogger {
	/* The current level of this logger. Messages exceed it will be dropped. */
	int level;
	
	/* The file being written */
	int fd;
	
	char *date_format;
}clogger;

void _clog_err(const char *fmt, ...) {
#ifdef CLOG_SILENT
    (void) fmt;
#else
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
#endif
    return;
}

// turn on clog
clogger * clog_on(const char * path) {

	clogger *l = NULL;
	int fd = -1;
	
	if (NULL == path) {
		fd = STDOUT_FILENO;
	} else {
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
		if (-1 == fd) {
			_clog_err("Unable to open %s: %s\n", path, strerror(errno));
			return NULL;
		}
	}
	
	l = (clogger *)malloc(sizeof(clogger));
	if (NULL == l) {
		return NULL;
	}
		
	l->date_format = (char *)"%Y-%m-%d %H:%M:%S";
	l->level = LOG_INFO;
	l->fd = fd;

	return l;
}

// turn off clog
void clog_off(clogger *l){
	if (l != NULL) {
		if (l->fd != STDOUT_FILENO) {
			close(l->fd);
		}
		
		free(l);
	}
	
	return;
}

//
int clog_set_level();

void clog_file(clogger *l, int level, const char *sfile, const char *sfunc, int sline, const char *msg) {
	time_t now = 0;
	int res = -1;
	char buf[64] = {0};
	char log[CLOG_MAX_MSG_LEN + 128] = {0};

	if (level > l->level) {
		return;
	}
	
	now = time(NULL);
	
	strftime(buf, sizeof(buf), l->date_format, localtime(&now));
	
	snprintf(log, sizeof(log), "[%d] %s, %s, %s:%s():%d: %s\n"
			, (int)getpid(), CLOG_LEVEL_CHARS[level], buf, sfile, sfunc, sline, msg);
	
	res = write(l->fd, log, strlen(log));
	if (-1 == res) {
		_clog_err("Unable to write to log file: %s\n", strerror(errno));
	}
	
	return;
}

#define clog_debug(l, level, fmt, ...) _clog_debug(l, level, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

void _clog_debug(clogger *l, int level, const char *sfile, const char *sfunc, int sline, const char *fmt, ...) {
	va_list ap;
	char msg[CLOG_MAX_MSG_LEN] = {0};
	
	va_start(ap, fmt);
	vsnprintf(msg, sizeof(msg), fmt, ap);
	clog_file(l, level, sfile, sfunc, sline, msg);
	
	va_end(ap);
	
	return;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // LW_CLOGGER_H_