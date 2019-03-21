/**
 * @Date:   2019-03-06T19:27:39+08:00
 * @Email:  wanwb1224@gmail.com
 * @Last modified time: 2019-03-07T10:30:43+08:00
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) {
  int x = atoi(argv[argc - 3]);
  int y = atoi(argv[argc - 2]);
  int z = atoi(argv[argc - 1]);
  printf("dir:%s x:%d, y:%d, z:%d\n",argv[1], x, y, z);
  return 0;
}
