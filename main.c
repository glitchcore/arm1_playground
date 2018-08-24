char* tty = (void*)0x0000ff00;

void print(char* str) {
    while(*str) {
        *tty = *str++;
    }
}

void main() {
    int a = 5;

    print("ARM forever!");
    print(" ");

    for(int i = 0; i < 10; i++) {
        char s[] = {'0' + (char)i, '\0'};
        print(s);
    }
}
