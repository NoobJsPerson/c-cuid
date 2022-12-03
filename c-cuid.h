#ifndef C_CUID_H
#define C_CUID_H

#ifdef __cplusplus
extern "C" {
#else
#define bool _Bool
#endif 

extern char* cuid(char* buff);
extern char* slug(char* buff);
extern bool isCuid(char* buff);
extern bool isSlug(char* buff);
#define CUID_LENGTH 26
#define SLUG_LENGTH 11

#ifdef __cplusplus
}
#endif 

#endif // C_CUID_H