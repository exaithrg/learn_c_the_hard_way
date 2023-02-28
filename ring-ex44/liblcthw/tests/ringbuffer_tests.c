#include "minunit.h"
#include "assert.h"
#include "stdbool.h"
#include "../src/lcthw/ringbuffer.h"

#define BUFFER_SIZE 5

RingBuffer *buffer = NULL;

char *test_create()
{
    buffer = RingBuffer_create(BUFFER_SIZE);
    mu_assert(buffer != NULL, "Failed to create Ring buffer");

    return NULL;
}

char *test_read_write()
{
    int rc = 0;

    mu_assert(RingBuffer_empty(buffer) == true, "RingBuffer_empty wrong return value");
    mu_assert(RingBuffer_full(buffer) == false, "RingBuffer_full wrong return value");

    rc = RingBuffer_read(buffer, "1", 1);
    mu_assert(rc != 0, "RingBuffer_read expected to return error code, but was successful");

    // rc = RingBuffer_write(buffer, "", 0);
    // mu_assert(rc != 0, "RingBuffer_write succeeded with length 0");

    rc = RingBuffer_write(buffer, "1234", 4);
    // mu_assert(rc == 0, "RingBuffer_write bad exit status");
    mu_assert(RingBuffer_available_data(buffer) == 4, "wrong available data after Ringbuffer_write");
    mu_assert(RingBuffer_available_space(buffer) == 1, "wrong available space after RingBuffer_write");
    mu_assert(RingBuffer_empty(buffer) == false, "RingBuffer_empty wrong return value");

    return NULL;
}

char *test_destroy()
{
    RingBuffer_destroy(buffer);

    return NULL;
}
/*
RingBuffer *RingBuffer_create(int length);
void RingBuffer_destroy(RingBuffer *buffer);
int RingBuffer_read(RingBuffer *buffer, char *target, int amount);
int RingBuffer_write(RingBuffer *buffer, char *data, int length);

bool RingBuffer_empty(RingBuffer *buffer);
bool RingBuffer_full(RingBuffer *buffer);
int RingBuffer_available_data(RingBuffer *buffer);
int RingBuffer_available_space(RingBuffer *buffer);

bstring RingBuffer_gets(RingBuffer *buffer, int amount);
*/

char *all_tests()
{
    printf("START TSET\n");
    mu_suite_start();

    printf("TEST_CREATE\n");
    mu_run_test(test_create);
    printf("TEST_READ_WRITE\n");
    mu_run_test(test_read_write);
    printf("TEST_DESTROY\n");
    mu_run_test(test_destroy);
    printf("TEST_END\n");

    return NULL;
}

RUN_TESTS(all_tests);
