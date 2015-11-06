#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp, *pFile2 ;
    long i;
    char c;
pFile2 = fopen("C:\\Users\\tparlem\\Desktop\\myfile2.txt", "a");

printf("test1");
    if ((fp = fopen("C:\\Users\\tparlem\\Desktop\\stm32cubef7 (1)\\STM32Cube_FW_F7_V1.2.0\\Projects\\STM32746G-Discovery\\Applications\\LwIP\\LwIP_HTTP_Server_Netconn_RTOS\\Fs\\light.html", "rb+")) == NULL) {
        perror("fopen");
        return 1;
    }

printf("test2");
  while ((c = fgetc(fp)) != EOF) {
   // printf("0x%x, ", c);
     fprintf(pFile2, "0x%x, ", c);
  }

    return 0;
}
