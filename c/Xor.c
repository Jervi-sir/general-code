#include<stdio.h>

main()
{  int x,y,i;
   for(i=0;i<4;i++)
   {
      switch(i)
         {
            case 0 : x=0;y=0;;break;
            case 1 : x=0;y=1;;break;
            case 2 : x=1;y=0;;break;
            case 3 : x=1;y=1;;break;
            default: ;break;
         }
      printf("%d\n",!(x|y));
   }
}