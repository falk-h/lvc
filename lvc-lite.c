#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
        // String representing the two chars in the number of the week, eg. "05".
        char week_string[3];

        // Unix time.
        time_t current_time;

        // Fancy time struct.
        struct tm *tmp;

        // Get time and turn it into a struct tm.
        current_time = time(NULL);
        tmp = localtime(&current_time);
        
        // Fail if time or localtime fail.
        if (tmp == NULL) {
                fprintf(stderr, "lvc-lite: couldn't get time");
                exit(EXIT_FAILURE);
        }

        // Format time and store it in week_string. Fail if strftime fails.
        if (strftime(week_string, sizeof(week_string), "%-V", tmp) == 0) {
                fprintf(stderr, "lvc-lite: couldn't format time");
                exit(EXIT_FAILURE);
        }


        // Convert the first two chars in week_string to a number.
        unsigned char week = 10 * (week_string[0] - '0') + week_string[1] - '0';

        /*
         * Horrible Wall of Ifs.
         * First checks if our week is a reexamination week, checks if it's an
         * examination week, checks if it's a teaching week, and calculates
         * which one it is using an offset, and finally just outputs the week's
         * number if it doesn't fall in any of the above categories. Study
         * period 4 is in there twice because it has a reexamination week in
         * the middle, and therefore needs two different offsets.
         */
        if (week == 1 || week == 16 || week == 22  || week == 33) {
            // Reexamination week.
            printf("OTV\n");
        } else if (week == 11 || week == 21 || week == 43 || week == 2) {
            // Examination week.
            printf("TV\n");
        } else if (week >= 35 && week <= 42) {
            // Study period 1
            printf("LV%d\n", week - 34);
        } else if (week >= 44 && week <= 51) {
            // Study period 2
            printf("LV%d\n", week - 43);
        } else if (week >= 3 && week <= 10) {
            // Study period 3
            printf("LV%d\n", week - 2);
        } else if (week >= 12 && week <= 15) {
            // Study period 4
            printf("LV%d\n", week - 11);
        } else if (week >= 17 && week <= 20) {
            // Study period 4
            printf("LV%d\n", week - 12);
        } else {
            // Week not in the academic year.
            printf("V%d\n", week);
        }
        
        return 0;
}
