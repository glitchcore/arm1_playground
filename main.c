char* tty = (void*)0x0000ff00;

static int result = 0;

void print(char* str) {
    while(*str) {
        *tty = *str++;
    }
}

void main() {
    int a = 5;

    for(int i = 0; i < 2; i++) {
        a = a + 1;
        print("ARM1 forever!");
        print(" ");
    }

    result = a << 1;
}
