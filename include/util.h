#ifndef REFLECS_UTIL_H
#define REFLECS_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#if REFLECS_UTIL_IMPL && defined _MSC_VER
#define REFLECS_UTIL_EXPORT __declspec(dllexport)
#elif REFLECS_UTIL_IMPL
#define REFLECS_UTIL_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define REFLECS_UTIL_EXPORT __declspec(dllimport)
#else
#define REFLECS_UTIL_EXPORT
#endif

#ifdef __cplusplus
}
#endif

#endif
