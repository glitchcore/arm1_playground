#include <stdint.h>

uint32_t* tty = (uint32_t*)0x0000ff00;

typedef enum _Color {
    MOVE = 1,
    LINE = 2,
    CIRCLE = 3
} Color;

typedef enum _Type {
    BLACK = 1,
    WHITE = 2,
    RED = 3,
    GREEN = 4,
    BLUE = 5
} Type;

typedef struct _Part {
    uint8_t x;
    uint8_t y;
    uint8_t r;
    Color color;
    Type type;
} Part;

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

    Part begin_line_part = { .type = MOVE, .x = 10, .y = 10 };
    Part end_line_part = {.type = LINE, .color = RED, .x = 60, .y = 100};

    uint32_t* begin_line = place_part(&begin_line_part);

    place_part(&end_line_part);
    render();

    while(1) {
        for(char x = 10; x < 120; x += 3) {
            begin_line_part.x = x;
            update_part(&begin_line_part, begin_line);
            render();
        }

        for(char x = 120; x > 10; x -= 3) {
            begin_line_part.x = x;
            update_part(&begin_line_part, begin_line);
            render();
        }
    }
}
