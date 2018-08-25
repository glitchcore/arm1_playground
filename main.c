#include <stdint.h>
#include "demo.h"

uint32_t* tty = (uint32_t*)0x0000ff00;

void print(char* str) {
    while(*str) {
        *tty = *str++;
    }
}

void update_part(Part* part, uint32_t* frame_ptr) {
    *frame_ptr = (part->type << 24) | (part->color << 28) |
        (part->x << 16) | (part->y << 8) | part->r;
}

volatile uint32_t* frame = 0;
uint32_t* place_part(Part* part) {
    uint32_t* frame_ptr = frame++;
    update_part(part, frame_ptr);

    return frame_ptr;
}

void render() {
    *frame = 0;
}

void main() {
    frame = tty + 4;

    for(uint16_t i = 0; i < sizeof(demo)/sizeof(demo[0]); i++) {
        place_part(&demo[i]);
        render();
    }
}
