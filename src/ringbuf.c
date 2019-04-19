
#include <flecs>
#include <flecs.util>

struct ecs_ringbuf_t {
    ecs_vector_t *data;
    int32_t index;
};

ecs_ringbuf_t* ecs_ringbuf_new(
    const ecs_vector_params_t *params,
    uint32_t size)
{
    ecs_ringbuf_t *result = ecs_os_malloc(sizeof(ecs_ringbuf_t));
    ecs_assert(result != NULL, ECS_OUT_OF_MEMORY, NULL);

    result->data = ecs_vector_new(params, size);
    result->index = 0;
    return result;
}

void* ecs_ringbuf_push(
    ecs_ringbuf_t *buffer,
    const ecs_vector_params_t *params)
{
    uint32_t size = ecs_vector_size(buffer->data);
    uint32_t count = ecs_vector_count(buffer->data);
    void *result;

    if (count == buffer->index) {
        result = ecs_vector_add(&buffer->data, params);
    } else {
        result = ecs_vector_get(buffer->data, params, buffer->index);
    }

    buffer->index = (buffer->index + 1) % size;

    return result;
}

void ecs_ringbuf_free(
    ecs_ringbuf_t *buffer)
{
    ecs_vector_free(buffer->data);
    ecs_os_free(buffer);
}

void* ecs_ringbuf_get(
    ecs_ringbuf_t *buffer,
    const ecs_vector_params_t *params,
    uint32_t index)
{
    int32_t count = ecs_vector_count(buffer->data);
    int32_t size = ecs_vector_size(buffer->data);
    index = ((buffer->index - count + size) + (int32_t)index) % size;
    return ecs_vector_get(buffer->data, params, index);
}

void* ecs_ringbuf_last(
    ecs_ringbuf_t *buffer,
    const ecs_vector_params_t *params)
{
    uint32_t index = buffer->index;
    if (!index) {
        index = ecs_vector_size(buffer->data);
    }

    return ecs_vector_get(buffer->data, params, index - 1);
}

uint32_t ecs_ringbuf_index(
    ecs_ringbuf_t *buffer)
{
    return buffer->index;
}

uint32_t ecs_ringbuf_count(
    ecs_ringbuf_t *buffer)
{
    return ecs_vector_count(buffer->data);
}
