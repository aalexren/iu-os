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

    int codes[6]; // to keep the codes

    printf("PE -- CAP -- HJKL\n");

    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.n", dev, strerror(errno)); // stderr - the standard stream for error output.
        return EXIT_FAILURE;
    }

    while (1) {
        n = read(fd, &iev, sizeof(iev));
        //if (n == -1) {
        //    if (errno != EINTR)
        //        break;
        //}
        //else if (n != sizeof(iev)) {
        //    errno = EIO;
        //    break;
        //}
        if (iev.value == 1) {
           for (int i = 5; i > 0; --i) {
               codes[i] = codes[i-1];
           }
           codes[0] = iev.code;
	   //for (int i = 0; i < 6; ++i) {
	   //	printf("%d ", codes[i]);
	   //}
	   printf("\n");
           if ((codes[0] == 25 && codes[1] == 18) || (codes[0] == 18 && codes[1] == 25))
              printf("I passed the exam!\n");
           else if (codes[0] == 25 && codes[1] == 30 && codes[2] == 46)
              printf("Get some capuccino...\n");
           else if (codes[0] == 38 && codes[1] == 37 && codes[2] == 36 && codes[3] == 35)
              printf("That's my cute vimmy shortcut :)\n");
        }
    }

    fflush(stdout);
    fprintf(stderr, "%s.n", strerror(errno));

    return EXIT_FAILURE;
}
