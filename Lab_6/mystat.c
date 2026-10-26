#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
char *
typename(int t)
{
// DONE: return "directory", "file" or "device" for T_DIR, T_FILE, T_DEVICE
switch(t)
{
case T_DIR:
return "directory";
case T_FILE:
return "file";
case T_DEVICE:
return "device";
}
return "?";
}
int
main(int argc, char *argv[])
{
struct stat st;
for(int i = 1; i < argc; i++){
// DONE: call stat(argv[i], &st); on error print to fd 2 and continue
if (stat(argv[i], &st) == -1)
{
fprintf(2, "Unable to inrerpret %s\n", argv[i]);
continue;
}
// DONE: print NAME: TYPE, inode N, links N, size N bytes
printf("%s: ", argv[i]); //written on my fucking own
printf("%s, ", typename(st.type));
printf("inode %u, ", st.ino);
printf("links %u, ", st.nlink);
printf("size %lu bytes\n", st.size);
}
exit(0);
}
