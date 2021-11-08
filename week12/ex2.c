#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const ieval[3] = {
    "RELEASED",
    "PRESSED ",
    "REPEATED"
};

int main(void) {
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event iev;
    ssize_t n;
    int fd;

    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.n", dev, strerror(errno)); // stderr - the standard stream for error output.
        return EXIT_FAILURE;
    }

    while (1) {
        n = read(fd, &iev, sizeof(iev));
        if (n == -1) {
            if (errno != EINTR)
                break;
        }
        else if (n != sizeof(iev)) {
            errno = EIO;
            break;
        }
        if (iev.type == EV_KEY && iev.value >= 0 && iev.value <= 2) {
            printf("%s 0x%04x (%d)", ieval[iev.value], (int)iev.code, (int)iev.code);
        }
        if (iev.value == 0) {
           printf("\n");
        }
    }

    fflush(stdout);
    fprintf(stderr, "%s.n", strerror(errno));

    return EXIT_FAILURE;
}
