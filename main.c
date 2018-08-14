char* tty = (void*)0x0000ff00;

static int result = 0;

void print(char* str) {
    while(*str) {
        *tty = *str++;
    }
}

void main() {
    int a = 5;

    int* frame = (int*)tty + 4;

    *frame = (1 << 24) | (10 << 16) | (10 << 8);
    int* beginLine = frame;

    frame++;

    *frame++ = (2 << 24) | (3 << 28) | (20 << 16) | (20 << 8);
    *frame = 0;

    for(char x = 10; x < 30; x++) {
        *beginLine = (1 << 24) | (x << 16) | (10 << 8);
        *frame = 0;
    }

    for(int i = 0; i < 2; i++) {
        a = a + (a << 2);
        print("ARM1 forever!");
        print(" ");
    }

    result = a << 1;
}
