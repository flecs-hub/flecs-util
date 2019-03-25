
#include <flecs>
#include <flecs.util>

struct ecs_ringbuf_t {
    ecs_array_t *data;
    int32_t index;
};

ecs_ringbuf_t* ecs_ringbuf_new(
    const ecs_array_params_t *params,
    uint32_t size)
{
    ecs_ringbuf_t *result = malloc(sizeof(ecs_ringbuf_t));
    ecs_assert(result != NULL, ECS_OUT_OF_MEMORY, NULL);

    result->data = ecs_array_new(params, size);
    result->index = 0;
    return result;
}

void* ecs_ringbuf_push(
    ecs_ringbuf_t *buffer,
    const ecs_array_params_t *params)
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
    ecs_ringbuf_t *buffer)
{
    ecs_array_free(buffer->data);
    free(buffer);
}

void* ecs_ringbuf_get(
    ecs_ringbuf_t *buffer,
    const ecs_array_params_t *params,
    uint32_t index)
{
    int32_t count = ecs_array_count(buffer->data);
    int32_t size = ecs_array_size(buffer->data);
    index = ((buffer->index - count + size) + (int32_t)index) % size;
    return ecs_array_get(buffer->data, params, index);
}

void* ecs_ringbuf_last(
    ecs_ringbuf_t *buffer,
    const ecs_array_params_t *params)
{
    uint32_t index = buffer->index;
    if (!index) {
        index = ecs_array_size(buffer->data);
    }

    return ecs_array_get(buffer->data, params, index - 1);
}

uint32_t ecs_ringbuf_index(
    ecs_ringbuf_t *buffer)
{
    return buffer->index;
}

uint32_t ecs_ringbuf_count(
    ecs_ringbuf_t *buffer)
{
    return ecs_array_count(buffer->data);
}
