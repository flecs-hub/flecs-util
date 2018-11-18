/** @file
 * @section time Time API
 * @brief Utility API for doing time measurements.
 */

#ifndef REFLECS_UTIL_TIME_H_
#define REFLECS_UTIL_TIME_H_

#include <reflecs/util/util.h>

#ifdef __cplusplus
extern "C" {
#endif

REFLECS_UTIL_EXPORT
void ut_sleep(
  unsigned int sec,
  unsigned int nanosec);

REFLECS_UTIL_EXPORT
void ut_time_get(
    struct timespec* time);

REFLECS_UTIL_EXPORT
double ut_time_to_double(
    struct timespec t);

REFLECS_UTIL_EXPORT
struct timespec ut_time_sub(
    struct timespec t1,
    struct timespec t2);

REFLECS_UTIL_EXPORT
double ut_time_measure(
    struct timespec start);

#ifdef __cplusplus
}
#endif

#endif
