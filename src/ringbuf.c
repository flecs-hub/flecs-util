
#include <reflecs/reflecs.h>
#include <reflecs/util/ringbuf.h>

struct EcsRingBuf {
    EcsArray *data;
    uint32_t index;
};

EcsRingBuf* ecs_ringbuf_new(
    const EcsArrayParams *params,
    uint32_t size)
{
    EcsRingBuf *result = malloc(sizeof(EcsRingBuf));
    result->data = ecs_array_new(params, size);
    result->index = 0;
    return result;
}

void* ecs_ringbuf_push(
    EcsRingBuf *buffer,
    const EcsArrayParams *params)
{
    uint32_t size = ecs_array_size(buffer->data);
    uint32_t count = ecs_array_count(buffer->data);
    void *result;

    if (count == buffer->index) {
        result = ecs_array_add(&buffer->data, params);
    } else {
        result = ecs_array_get(buffer->data, params, buffer->index);
    }

    buffer->index = (buffer->index + 1) % size;

    return result;
}

void ecs_ringbuf_free(
    EcsRingBuf *buffer)
{
    ecs_array_free(buffer->data);
    free(buffer);
}

void* ecs_ringbuf_get(
    EcsRingBuf *buffer,
    const EcsArrayParams *params,
    uint32_t index)
{
    uint32_t count = ecs_array_count(buffer->data);
    index = ((buffer->index - count) + index) % ecs_array_size(buffer->data);
    return ecs_array_get(buffer->data, params, index);
}

void* ecs_ringbuf_last(
    EcsRingBuf *buffer,
    const EcsArrayParams *params)
{
    uint32_t index = buffer->index;
    if (!index) {
        index = ecs_array_size(buffer->data);
    }

    return ecs_array_get(buffer->data, params, index - 1);
}

uint32_t ecs_ringbuf_index(
    EcsRingBuf *buffer)
{
    return buffer->index;
}

uint32_t ecs_ringbuf_count(
    EcsRingBuf *buffer)
{
    return ecs_array_count(buffer->data);
}
