#define CONTAINER_OF(ptr, sample, member) \
    (void *)((char *)(ptr) - \
    ((char *)&(sample)->member - (char *)(sample)))
