#define INCL_VIO
#include <os2.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



void split ()
   {
   printf ("���������������������������������������������������������������������͹\n");
   }

void top ()
   {
   printf ("���������������������������������������������������������������������ͻ\n");
   }

void bottom ()
   {
   printf ("���������������������������������������������������������������������ͼ\n");
   }

void head ()
   {
   top ();
   printf ("�������0  �16 �32 �48 �64 �80 �96 �112�128�144�160�176�192�208�224�240�\n");
   printf ("�������x00�x10�x20�x30�x40�x50�x60�x70�x80�x90�xA0�xB0�xC0�xD0�xE0�xF0�\n");
   }



main (int argc, char *argv[])
   {
   int y, x, uRow, uCol, bAtt;
   char c, cell[2];

   if (argc ==1)
      {
      printf ("Usage: charset [c | a]");
      exit (0);
      }

   bAtt = (*argv[1] == 'a' || *argv[1] == 'A');

   cell[0] = '*';
   head ();
   for (y=0; y<16; y++)
      {
      split ();
      printf ("�%2d x%1x�", y, y);
      for (x=0; x<16; x++)
         {
         putch (' ');

         cell[1] = c = (char) (y + x * 16);

         VioGetCurPos (&uRow, &uCol, 0);

         if (bAtt)
            {
            VioWrtNAttr (cell+1, 3, uRow, uCol-1, 0);
            VioWrtNCell (cell, 1, uRow, uCol, 0);
            VioSetCurPos (uRow, uCol+2, 0);
            }
         else
            {
            VioWrtNChar (&c, 1, uRow, uCol, 0);
            VioSetCurPos (uRow, uCol+1, 0);
            putch (' ');
            }
         putch ('�');
         }
      putchar ('\n');
      }
   bottom ();
   return 0;
   }
   
