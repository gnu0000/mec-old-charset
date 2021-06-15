#define INCL_VIO
#include <os2.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



void split ()
   {
   printf ("ฬอออออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออฮอออน\n");
   }

void top ()
   {
   printf ("ษอออออหอออหอออหอออหอออหอออหอออหอออหอออหอออหอออหอออหอออหอออหอออหอออหอออป\n");
   }

void bottom ()
   {
   printf ("ศอออออสอออสอออสอออสอออสอออสอออสอออสอออสอออสอออสอออสอออสอออสอออสอออสอออผ\n");
   }

void head ()
   {
   top ();
   printf ("บฑฑฑฑฑบ0  บ16 บ32 บ48 บ64 บ80 บ96 บ112บ128บ144บ160บ176บ192บ208บ224บ240บ\n");
   printf ("บฑฑฑฑฑบx00บx10บx20บx30บx40บx50บx60บx70บx80บx90บxA0บxB0บxC0บxD0บxE0บxF0บ\n");
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
      printf ("บ%2d x%1xบ", y, y);
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
         putch ('บ');
         }
      putchar ('\n');
      }
   bottom ();
   return 0;
   }
   
