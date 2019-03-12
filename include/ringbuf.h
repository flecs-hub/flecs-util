

#ifndef FLECS_UTIL_RINGBUF_H_
#define FLECS_UTIL_RINGBUF_H_

#include <flecs>
#include "bake_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsRingBuf EcsRingBuf;

FLECS_UTIL_EXPORT
EcsRingBuf* ecs_ringbuf_new(
    const EcsArrayParams *params,
    uint32_t size);

FLECS_UTIL_EXPORT
void* ecs_ringbuf_push(
    EcsRingBuf *buffer,
    const EcsArrayParams *params);

FLECS_UTIL_EXPORT
void* ecs_ringbuf_get(
    EcsRingBuf *buffer,
    const EcsArrayParams *params,
    uint32_t index);

FLECS_UTIL_EXPORT
void* ecs_ringbuf_last(
    EcsRingBuf *buffer,
    const EcsArrayParams *params);

FLECS_UTIL_EXPORT
uint32_t ecs_ringbuf_index(
    EcsRingBuf *buffer);

FLECS_UTIL_EXPORT
uint32_t ecs_ringbuf_count(
    EcsRingBuf *buffer);

FLECS_UTIL_EXPORT
void ecs_ringbuf_free(
    EcsRingBuf *buffer);

#ifdef __cplusplus
}
#endif

#endif
