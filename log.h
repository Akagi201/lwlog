/*
 * @file log.h
 * @auther Akagi201
 *
 * @date 2014/09/16
 */

#ifndef LOG_H_
#define LOG_H_ (1)

#ifdef NODEBUG
#define LOG(fmt, ...) do {} while (0)
#else
#define LOG(fmt, ...) fprintf(stdout, "[DEBUG] %s:%s:%d: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif

#endif // LOG_H_