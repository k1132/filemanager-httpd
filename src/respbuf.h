#ifndef RESPBUF_H
#define RESPBUF_H

#include "membuf.h"

typedef struct RespBuf RespBuf;

/* Creates a new response.
 * Parameter sysErrno may be:
 *  >= 0    - errno value indicating the error
 *  < 0     - negated HTTP error, e.g. -405 for HTTP error 405
 */
RespBuf *resp_new(int sysErrno);

/* Returns error message associated with sysErrno given in resp_new().
 * Returns NULL when sysErrno was 0.
 */
const char *resp_getErrMessage(RespBuf*);

/* Adds header to response
 */
void resp_appendHeader(RespBuf*, const char *name, const char *value);

/* Appends data to response body
 */
void resp_appendData(RespBuf*, const char *data, unsigned dataLen);

/* Appends string to response body
 */
void resp_appendStr(RespBuf*, const char *str);

/* Appends list of strings to response body.
 * The list shall be terminated with NULL.
 */
void resp_appendStrL(RespBuf*, const char *str1, const char *str2,  ...);

MemBuf *resp_finish(RespBuf*, int onlyHead);

#endif /* RESPBUF_H */
