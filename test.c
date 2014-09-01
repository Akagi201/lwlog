/*
 * @file test.c
 * 
 * @author Akagi201
 * @date 2014/09/01
 * 
 * test program for lw-clogger
 */

#include "lw-clogger.h"

int main() {
	char *foo = NULL;
	int bar = 10;
	
	clogger *l = clog_on(NULL);
	l->level = LOG_INFO;
	
	clog_debug(l, LOG_INFO, "LOG_INFO");
	clog_debug(l, LOG_NOTICE, "LOG_NOTICE");
	clog_debug(l, LOG_DEBUG, "LOG_DEBUG");
	
	foo = "Information";
	clog_debug(l, LOG_INFO, "Foo[%-30s] Bar[%d]", foo, bar);
	
	clog_off(l);
	
	return 0;
}