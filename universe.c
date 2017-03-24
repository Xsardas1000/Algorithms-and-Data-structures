//
//  universe.c
//  sphere
//
//  Created by Максим on 03.12.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>
#include <string.h>

struct buffer {
    int begin, end, size;
    char *buf;
};

typedef struct buffer buffer;

buffer* create_buffer(int size) {
    buffer *b = calloc(1, sizeof(*b));
    b->begin = b->end = 0;
    b->size = size;
    b->buf = calloc(size, sizeof(b->buf[0]));
    return b;
}

void write_buffer(buffer *b, void *data, int size) {
    char *d = (char *)data;
    for (int i = 0; i < size && b->begin != (b->end + 1) % b->size; i++) {
        b->buf[b->end] = d[i];
        b->end = (b->end + 1) % b->size;
    }
}

void read_buffer(buffer *b, void *data, int size) {
    char *d = (char *)data;
    for (int i = 0; i < size && b->begin != b->end; ++i) {
        d[i] = b->buf[b->begin];
        b->begin = (b->begin + 1) % b->size;
    }
}

int main(void) {
    buffer* b = create_buffer(20);
    
    int x = 10, y = 20;
    
    write_buffer(b, &x, sizeof(x));
    write_buffer(b, &y, sizeof(y));
    
    long long t;
    read_buffer(b, &t, sizeof(t));
    printf("%lld", t);
    
    return 0;
}
