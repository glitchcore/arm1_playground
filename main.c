
char hello_string[] = "ARM1 forever";
void* tty = (void*)0x0000ff00;

static int result = 0;

void main() {
    int a = 5;

    for(int i = 0; i < 5; i++) {
    	a = a + 1;
    }

    result = a + 1;
}
