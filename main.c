char* tty = (void*)0x0000ff00;

static int result = 0;

void print(char* str) {
    while(*str) {
        *tty = *str++;
    }
}

void main() {
    int a = 5;

    volatile int* frame = (int*)tty + 4;

    *frame = (1 << 24) | (10 << 16) | (10 << 8);
    volatile int* beginLine = frame;

    frame++;

    *frame++ = (2 << 24) | (3 << 28) | (60 << 16) | (100 << 8);
    *frame = 0;

    while(1) {
        for(char x = 10; x < 120; x += 3) {
            *beginLine = (1 << 24) | (x << 16) | (10 << 8);
            *frame = 0;
        }

        for(char x = 120; x > 10; x -= 3) {
            *beginLine = (1 << 24) | (x << 16) | (10 << 8);
            *frame = 0;
        }
    }

    for(int i = 0; i < 2; i++) {
        a = a + (a << 2);
        print("ARM1 forever!");
        print(" ");
    }

    result = a << 1;
}
