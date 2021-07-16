/**
 * 192.168.1.1 3232235777
 */

#include <stdio.h>
#include <stdlib.h>

int my_atoi(char *str) {
    return atoi(str); 
}

int main(int argc, char **argv)
{
   unsigned int ip_num = 0; 

   int i = 0;
   char *ip = argv[1];

   char *start = ip;
   int flag = 0;
   int ip_arr[4] = {0};

   for (i = 0; ip[i] != '\0'; i++) {
        if (ip[i] == '.')  {
            ip[i] = '\0';
            ip_arr[flag++] = my_atoi(start);
            start = &ip[i + 1];
            if (flag == 3)
                ip_arr[flag] = my_atoi(start);
        }
   }

   for (i = 0; i < 4; i++) {
        ip_num |= ip_arr[i] << ((3 - i) * 8);
   }
   printf("%u\n", ip_num);


   unsigned char octet = '\0';
   unsigned char mask = 0xff;
   char ip_str[20] = { '\0' };
   int ip_arr1[4] = {0};
   for (i = 3; i >= 0; i--) {
        octet = (ip_num >> (i * 8)) & mask;
        ip_arr1[i] = octet;
   }
   sprintf(ip_str, "%d.%d.%d.%d", ip_arr1[3], ip_arr1[2], ip_arr1[1], ip_arr1[0]);
   printf("%s\n", ip_str);

   return 0;
}
