/**
 * @Author: ruo_van
 * @Date:   2019-02-22T09:27:52+08:00
 * @Email:  wanwb1224@gmail.com
 * @Last modified by:
 * @Last modified time: 2019-03-04T10:58:19+08:00
 */



#include <stdio.h>

int main() {
  float a[200], b[200], c[100],cc[100], d[200], e[200];
  FILE *fp = fopen("./test.bin", "wb");
  for (int i = 0; i < 200; i++) {
    a[i] = i;
    b[i] = i*10;
  }
  fwrite(a, sizeof(float), 200, fp);
  fclose(fp);
  FILE *fp1 = fopen("./test1.bin", "wb+");
  for (int i = 0; i < 200; i++)
    fprintf(fp1, "%f  %f\n", a[i], b[i]);
  fclose(fp1);
  fp = fopen("./test.bin", "r");
  fread(c, sizeof(float), 100, fp);
  //fclose(fp);
  //fp = fopen("./test.bin", "r");
  fread(cc, sizeof(float), 100, fp);
  fclose(fp);
  for (int i = 0; i < 100; i++) printf("%d: %f %f\n",i,  c[i], cc[i]);
  fp1 = fopen("./test1.bin", "r");
  for (int i = 0; i < 100; i++) fscanf(fp1, "%f  %f\n", (d + i), (e + i));
  fclose(fp1);
  //for (int i = 0; i < 100; i++) printf("%f  %f\n", d[i], e[i]);
}
