#include <stdio.h>

int main(int argc, char *argv[]) {
        // Get the current week using date.
        FILE *stream = popen("date \"+%V\"", "r");
        
        // Get first char
        char w1 = getc(stream);

        // Get second char
        char w0 = getc(stream);

        // Close the stream
        pclose(stream);

        // Convert to a number
        char week = 10 * (w1 - '0') + (w0 - '0');

        /*
         * Horrible Wall of Ifs.
         * First checks if our week is a reexamination week, checks if it's an
         * examination week, checks if it's a teaching week, and calculates
         * which one it is with an offset, and finally just outputs the week's
         * number if it doesn't fall in any of the above categories. Study
         * period 4 is in there twice because it has a reexamination week in
         * the middle, and therefore needs two different offsets.
         */
        if (week == 1 || week == 14 || week == 22  || week == 33) {
            // Reexamination week.
            printf("OTV");
        } else if (week == 11 || week == 21 || week == 43 || week == 2) {
            // Examination week.
            printf("TV");
        } else if (week >= 35 && week <= 42) {
            // Study period 1
            printf("LV%d\n", week - 34);
        } else if (week >= 44 && week <= 51) {
            // Study period 2
            printf("LV%d\n", week - 43);
        } else if (week >= 3 && week <= 10) {
            // Study period 3
            printf("LV%d\n", week - 2);
        } else if (week >= 12 && week <= 13) {
            // Study period 4
            printf("LV%d\n", week - 11);
        } else if (week >= 15 && week <= 20) {
            // Study period 4
            printf("LV%d\n", week - 12);
        } else {
            // Week not in the academic year.
            printf("V%d", week);
        }
        
        return 0;
}
