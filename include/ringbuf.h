

#ifndef REFLECS_UTIL_RINGBUF_H_
#define REFLECS_UTIL_RINGBUF_H_

#include <reflecs.dir/util/array.h>
#include "prebaked.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsRingBuf EcsRingBuf;

REFLECS_UTIL_EXPORT
EcsRingBuf* ecs_ringbuf_new(
    const EcsArrayParams *params,
    uint32_t size);

REFLECS_UTIL_EXPORT
void* ecs_ringbuf_push(
    EcsRingBuf *buffer,
    const EcsArrayParams *params);

REFLECS_UTIL_EXPORT
void* ecs_ringbuf_get(
    EcsRingBuf *buffer,
    const EcsArrayParams *params,
    uint32_t index);

REFLECS_UTIL_EXPORT
void* ecs_ringbuf_last(
    EcsRingBuf *buffer,
    const EcsArrayParams *params);

REFLECS_UTIL_EXPORT
uint32_t ecs_ringbuf_index(
    EcsRingBuf *buffer);

REFLECS_UTIL_EXPORT
uint32_t ecs_ringbuf_count(
    EcsRingBuf *buffer);

REFLECS_UTIL_EXPORT
void ecs_ringbuf_free(
    EcsRingBuf *buffer);

#ifdef __cplusplus
}
#endif

#endif
