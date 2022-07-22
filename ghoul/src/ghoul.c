#include "tokio.h"

int main() {
    int i;
    for (i = 1000; i > 0; i -= 7) {
        print_ghoul(i);
        DELAY(25); /* in milliseconds */
    }
    print_red("I'm a ghoul...");
    return 0;
}
