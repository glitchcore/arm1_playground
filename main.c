#include <stdint.h>

uint32_t* tty = (uint32_t*)0x0000ff00;

typedef enum _Color {
    MOVE = 1,
    LINE = 2,
    CW = 3,
    CCW = 4,
    EXT_CW = 5,
    EXT_CCW = 6
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

Part demo[] = {
    {.type = MOVE, .x = 78, .y = 13, .r = 0, .color = RED},
    {.type = LINE, .x = 198, .y = 13, .r = 0, .color = RED},
    {.type = LINE, .x = 198, .y = 118, .r = 0, .color = RED},
    {.type = LINE, .x = 48, .y = 118, .r = 0, .color = RED},
    {.type = LINE, .x = 48, .y = 43, .r = 0, .color = RED},
    {.type = LINE, .x = 78, .y = 13, .r = 0, .color = RED},
    {.type = MOVE, .x = 55, .y = 85, .r = 0, .color = RED},
    {.type = CW, .x = 192, .y = 46, .r = 114, .color = RED},
    {.type = MOVE, .x = 71, .y = 96, .r = 0, .color = RED},
    {.type = CCW, .x = 182, .y = 54, .r = 81, .color = RED},
    {.type = MOVE, .x = 75, .y = 63, .r = 0, .color = RED},
    {.type = EXT_CCW, .x = 128, .y = 39, .r = 34, .color = RED},
    {.type = MOVE, .x = 84, .y = 56, .r = 0, .color = RED},
    {.type = EXT_CCW, .x = 115, .y = 42, .r = 25, .color = RED},
    {.type = MOVE, .x = 105, .y = 53, .r = 0, .color = RED},
    {.type = EXT_CW, .x = 105, .y = 71, .r = 11, .color = RED},
    {.type = MOVE, .x = 109, .y = 61, .r = 0, .color = RED},
    {.type = EXT_CCW, .x = 109, .y = 79, .r = 11, .color = RED},
    {.type = MOVE, .x = 46, .y = 149, .r = 0, .color = RED},
    {.type = LINE, .x = 46, .y = 142, .r = 0, .color = RED},
    {.type = CW, .x = 74, .y = 142, .r = 14, .color = RED},
    {.type = LINE, .x = 65, .y = 142, .r = 0, .color = RED},
    {.type = CCW, .x = 54, .y = 142, .r = 6, .color = RED},
    {.type = LINE, .x = 54, .y = 149, .r = 0, .color = RED},
    {.type = CCW, .x = 65, .y = 149, .r = 6, .color = RED},
    {.type = LINE, .x = 74, .y = 149, .r = 6, .color = RED},
    {.type = CW, .x = 46, .y = 149, .r = 14, .color = RED},
    {.type = MOVE, .x = 77, .y = 128, .r = 0, .color = RED},
    {.type = LINE, .x = 85, .y = 128, .r = 0, .color = RED},
    {.type = LINE, .x = 85, .y = 141, .r = 0, .color = RED},
    {.type = LINE, .x = 98, .y = 141, .r = 0, .color = RED},
    {.type = LINE, .x = 98, .y = 128, .r = 0, .color = RED},
    {.type = LINE, .x = 106, .y = 128, .r = 0, .color = RED},
    {.type = LINE, .x = 106, .y = 163, .r = 0, .color = RED},
    {.type = LINE, .x = 98, .y = 163, .r = 0, .color = RED},
    {.type = LINE, .x = 98, .y = 149, .r = 0, .color = RED},
    {.type = LINE, .x = 85, .y = 149, .r = 0, .color = RED},
    {.type = LINE, .x = 85, .y = 163, .r = 0, .color = RED},
    {.type = LINE, .x = 77, .y = 163, .r = 0, .color = RED},
    {.type = LINE, .x = 77, .y = 128, .r = 0, .color = RED},
    {.type = MOVE, .x = 119, .y = 128, .r = 0, .color = RED},
    {.type = LINE, .x = 131, .y = 128, .r = 0, .color = RED},
    {.type = LINE, .x = 140, .y = 163, .r = 0, .color = RED},
    {.type = LINE, .x = 132, .y = 163, .r = 0, .color = RED},
    {.type = LINE, .x = 131, .y = 156, .r = 0, .color = RED},
    {.type = LINE, .x = 119, .y = 156, .r = 0, .color = RED},
    {.type = LINE, .x = 118, .y = 163, .r = 0, .color = RED},
    {.type = LINE, .x = 110, .y = 163, .r = 0, .color = RED},
    {.type = LINE, .x = 119, .y = 128, .r = 0, .color = RED},
    {.type = MOVE, .x = 125, .y = 136, .r = 0, .color = RED},
    {.type = LINE, .x = 125, .y = 136, .r = 0, .color = RED},
    {.type = LINE, .x = 129, .y = 149, .r = 0, .color = RED},
    {.type = LINE, .x = 121, .y = 149, .r = 0, .color = RED},
    {.type = LINE, .x = 125, .y = 136, .r = 0, .color = RED},
    {.type = MOVE, .x = 141, .y = 149, .r = 0, .color = RED},
    {.type = LINE, .x = 141, .y = 142, .r = 0, .color = RED},
    {.type = CW, .x = 169, .y = 142, .r = 14, .color = RED},
    {.type = LINE, .x = 169, .y = 149, .r = 0, .color = RED},
    {.type = CW, .x = 141, .y = 149, .r = 14, .color = RED},
    {.type = MOVE, .x = 149, .y = 149, .r = 0, .color = RED},
    {.type = LINE, .x = 149, .y = 142, .r = 0, .color = RED},
    {.type = CW, .x = 160, .y = 142, .r = 6, .color = RED},
    {.type = LINE, .x = 160, .y = 149, .r = 0, .color = RED},
    {.type = CW, .x = 149, .y = 149, .r = 6, .color = RED},
    {.type = MOVE, .x = 174, .y = 142, .r = 0, .color = RED},
    {.type = LINE, .x = 174, .y = 135, .r = 0, .color = RED},
    {.type = CW, .x = 199, .y = 137, .r = 14, .color = RED},
    {.type = LINE, .x = 191, .y = 137, .r = 0, .color = RED},
    {.type = CCW, .x = 181, .y = 142, .r = 6, .color = RED},
    {.type = LINE, .x = 186, .y = 142, .r = 0, .color = RED},
    {.type = CW, .x = 198, .y = 149, .r = 14, .color = RED},
    {.type = LINE, .x = 198, .y = 156, .r = 0, .color = RED},
    {.type = CW, .x = 172, .y = 153, .r = 14, .color = RED},
    {.type = LINE, .x = 181, .y = 153, .r = 0, .color = RED},
    {.type = CCW, .x = 191, .y = 149, .r = 6, .color = RED},
    {.type = LINE, .x = 186, .y = 149, .r = 0, .color = RED},
    {.type = CW, .x = 174, .y = 142, .r = 14, .color = RED}
};

void main() {
    frame = tty + 4;

    Part begin_line_part = { .type = MOVE, .x = 10, .y = 10 };
    Part end_line_part = {.type = LINE, .color = RED, .x = 60, .y = 100};

    for(uint16_t i = 0; i < sizeof(demo)/sizeof(demo[0]); i++) {
        place_part(&demo[i]);
        render();
    }

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
