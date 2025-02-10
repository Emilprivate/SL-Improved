/*========================================
 *    sl.c: SL version 5.03
 *        Copyright 1993,1998,2014-2015
 *                  Toyoda Masashi
 *                  (mtoyoda@acm.org)
 *        Last Modified: 2014/06/03
 *========================================
 */
/* sl version 5.03 : Fix some more compiler warnings.                        */
/*                                              by Ryan Jacobs    2015/01/19 */
/* sl version 5.02 : Fix compiler warnings.                                  */
/*                                              by Jeff Schwab    2014/06/03 */
/* sl version 5.01 : removed cursor and handling of IO                       */
/*                                              by Chris Seymour  2014/01/03 */
/* sl version 5.00 : add -c option                                           */
/*                                              by Toyoda Masashi 2013/05/05 */
/* sl version 4.00 : add C51, usleep(40000)                                  */
/*                                              by Toyoda Masashi 2002/12/31 */
/* sl version 3.03 : add usleep(20000)                                       */
/*                                              by Toyoda Masashi 1998/07/22 */
/* sl version 3.02 : D51 flies! Change options.                              */
/*                                              by Toyoda Masashi 1993/01/19 */
/* sl version 3.01 : Wheel turns smoother                                    */
/*                                              by Toyoda Masashi 1992/12/25 */
/* sl version 3.00 : Add d(D51) option                                       */
/*                                              by Toyoda Masashi 1992/12/24 */
/* sl version 2.02 : Bug fixed.(dust remains in screen)                      */
/*                                              by Toyoda Masashi 1992/12/17 */
/* sl version 2.01 : Smoke run and disappear.                                */
/*                   Change '-a' to accident option.                         */
/*                                              by Toyoda Masashi 1992/12/16 */
/* sl version 2.00 : Add a(all),l(long),F(Fly!) options.                     */
/*                                              by Toyoda Masashi 1992/12/15 */
/* sl version 1.02 : Add turning wheel.                                      */
/*                                              by Toyoda Masashi 1992/12/14 */
/* sl version 1.01 : Add more complex smoke.                                 */
/*                                              by Toyoda Masashi 1992/12/14 */
/* sl version 1.00 : SL runs vomiting out smoke.                             */
/*                                              by Toyoda Masashi 1992/12/11 */

#include <curses.h>
#include <unistd.h>
#include "sl.h"
#include <time.h>

int my_mvaddstr(int y, int x, char *str)
{
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}

int main(int argc, char *argv[])
{
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    // Improve horizontal centering by counting actual characters
    int center_x = (COLS - 35) / 2;  // 35 is the actual width of the monkey
    int center_y = (LINES - MONKEYHEIGHT) / 2 + 2;  // Adjust vertical center
    clock_t start_time = clock();
    int base_y;

    while ((double)(clock() - start_time) / CLOCKS_PER_SEC < 5.0) {
        // Standing position
        base_y = center_y;
        my_mvaddstr(base_y-3, center_x + 8, TEXT_MSG);  // Center text above monkey
        
        // Draw monkey frame 1
        my_mvaddstr(base_y+0,  center_x, MONKEY1_1);
        my_mvaddstr(base_y+1,  center_x, MONKEY1_2);
        my_mvaddstr(base_y+2,  center_x, MONKEY1_3);
        my_mvaddstr(base_y+3,  center_x, MONKEY1_4);
        my_mvaddstr(base_y+4,  center_x, MONKEY1_5);
        my_mvaddstr(base_y+5,  center_x, MONKEY1_6);
        my_mvaddstr(base_y+6,  center_x, MONKEY1_7);
        my_mvaddstr(base_y+7,  center_x, MONKEY1_8);
        my_mvaddstr(base_y+8,  center_x, MONKEY1_9);
        my_mvaddstr(base_y+9,  center_x, MONKEY1_10);
        my_mvaddstr(base_y+10, center_x, MONKEY1_11);
        refresh();
        usleep(200000);

        // Clear screen at current position
        for (int i = 0; i < MONKEYHEIGHT; i++) {
            my_mvaddstr(base_y+i, center_x, MONKEYDEL);
        }
        my_mvaddstr(base_y-3, center_x + 8, TEXT_DEL);

        // Jump start
        base_y = center_y - 2;
        my_mvaddstr(base_y-3, center_x + 8, TEXT_MSG);
        
        // Draw monkey frame 2
        my_mvaddstr(base_y+0,  center_x, MONKEY2_1);
        my_mvaddstr(base_y+1,  center_x, MONKEY2_2);
        my_mvaddstr(base_y+2,  center_x, MONKEY2_3);
        my_mvaddstr(base_y+3,  center_x, MONKEY2_4);
        my_mvaddstr(base_y+4,  center_x, MONKEY2_5);
        my_mvaddstr(base_y+5,  center_x, MONKEY2_6);
        my_mvaddstr(base_y+6,  center_x, MONKEY2_7);
        my_mvaddstr(base_y+7,  center_x, MONKEY2_8);
        my_mvaddstr(base_y+8,  center_x, MONKEY2_9);
        my_mvaddstr(base_y+9,  center_x, MONKEY2_10);
        my_mvaddstr(base_y+10, center_x, MONKEY2_11);
        refresh();
        usleep(200000);

        // Clear screen at current position
        for (int i = 0; i < MONKEYHEIGHT; i++) {
            my_mvaddstr(base_y+i, center_x, MONKEYDEL);
        }
        my_mvaddstr(base_y-3, center_x + 8, TEXT_DEL);

        // Mid-air
        base_y = center_y - 4;
        my_mvaddstr(base_y-3, center_x + 8, TEXT_MSG);
        
        // Draw monkey frame 3
        my_mvaddstr(base_y+0,  center_x, MONKEY3_1);
        my_mvaddstr(base_y+1,  center_x, MONKEY3_2);
        my_mvaddstr(base_y+2,  center_x, MONKEY3_3);
        my_mvaddstr(base_y+3,  center_x, MONKEY3_4);
        my_mvaddstr(base_y+4,  center_x, MONKEY3_5);
        my_mvaddstr(base_y+5,  center_x, MONKEY3_6);
        my_mvaddstr(base_y+6,  center_x, MONKEY3_7);
        my_mvaddstr(base_y+7,  center_x, MONKEY3_8);
        my_mvaddstr(base_y+8,  center_x, MONKEY3_9);
        my_mvaddstr(base_y+9,  center_x, MONKEY3_10);
        my_mvaddstr(base_y+10, center_x, MONKEY3_11);
        refresh();
        usleep(200000);

        // Clear screen at current position
        for (int i = 0; i < MONKEYHEIGHT; i++) {
            my_mvaddstr(base_y+i, center_x, MONKEYDEL);
        }
        my_mvaddstr(base_y-3, center_x + 8, TEXT_DEL);

        // Landing
        base_y = center_y - 2;
        my_mvaddstr(base_y-3, center_x + 8, TEXT_MSG);
        
        // Draw monkey frame 4
        my_mvaddstr(base_y+0,  center_x, MONKEY4_1);
        my_mvaddstr(base_y+1,  center_x, MONKEY4_2);
        my_mvaddstr(base_y+2,  center_x, MONKEY4_3);
        my_mvaddstr(base_y+3,  center_x, MONKEY4_4);
        my_mvaddstr(base_y+4,  center_x, MONKEY4_5);
        my_mvaddstr(base_y+5,  center_x, MONKEY4_6);
        my_mvaddstr(base_y+6,  center_x, MONKEY4_7);
        my_mvaddstr(base_y+7,  center_x, MONKEY4_8);
        my_mvaddstr(base_y+8,  center_x, MONKEY4_9);
        my_mvaddstr(base_y+9,  center_x, MONKEY4_10);
        my_mvaddstr(base_y+10, center_x, MONKEY4_11);
        refresh();
        usleep(200000);

        // Clear screen at current position
        for (int i = 0; i < MONKEYHEIGHT; i++) {
            my_mvaddstr(base_y+i, center_x, MONKEYDEL);
        }
        my_mvaddstr(base_y-3, center_x + 8, TEXT_DEL);
    }

    endwin();
    return 0;
}
