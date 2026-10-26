#include "kernel/types.h"
#include "user/user.h"
int
main(int argc, char *argv[])
{
int p2c[2], c2p[2]; // parent-to-child, child-to-parent
6
Operating Systems – Laboratory Work No. 8 Balan Gabriel, FAF-241
char b = 'e';
pipe(p2c);
pipe(c2p);
if(fork() == 0){
close(p2c[1]); close(c2p[0]); // the ends the child does not use
// DONE: read 1 byte from p2c[0] into b
read(p2c[0], &b, 1);
printf("%d: received ping, data: %c\n", getpid(), b);
// DONE: write the byte b into c2p[1]
write(c2p[1], &b, 1);
exit(0);
}
close(p2c[0]); close(c2p[1]); // the ends the parent does not use
// DONE: write 1 byte into p2c[1]
write(p2c[1], &b, 1);
// DONE: read 1 byte from c2p[0] into b
read(c2p[0], &b, 1);
printf("%d: received pong, data: %c\n", getpid(), b);
wait(0);
exit(0);
}
