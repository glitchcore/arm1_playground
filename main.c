char* tty = (char*)0x0000ff00;

void print(char* str) {
    while(*str) {
        *tty = *str++;
    }
}

void main() {
    print("ARM forever!");
    print(" ");

    for(int i = 0; i < 10; i++) {
        char s[] = {'0' + (char)i, '\0'};
        print(s);
    }
}
