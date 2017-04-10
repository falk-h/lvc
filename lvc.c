#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
        FILE *stream;

        if (argc > 1) { 
                if (strcmp(argv[1], "-h") == 0) {
                        // Print help text.
                        printf("Usage: lvc [OPTION]\n");
                        printf("Get the week in the academic year\n");
                        printf("\n");
                        printf("  -d DATE    Get the week for DATE. Default is today.\n");
                        printf("             Works like date's -d flag.\n");
                        printf("  -h         Display this help message.\n");
                        return 0;
                } else if (argc == 2 && strcmp (argv[1], "-d") == 0) {
                        // Exit if we get "-d" without a string following it.
                        printf("lvc: no date string specified\n");
                        return 1;
                } else if (strcmp(argv[1], "-d") != 0) {
                        // Exit if we get something that's not "-d" or "-h".
                        printf("lvc: unexpected argument '%s'\n", argv[1]);
                        return 1;
                } else if (argc > 3) {
                        // Exit if we get more than 2 arguments.
                        printf("lvc: too many arguments\n");
                        return 1;
                }

                // Build the command to call.
                char command[256] = "date -d \"";
                strcat(command, argv[2]);
                strcat(command, "\" \"+%V\" 2> /dev/null");

                // Call the command we built.
                stream = popen(command, "r");
        } else {
                // Get the current date if there aren't any command line options.
                stream = popen("date \"+%V\" 2> /dev/null", "r");
        }

        // Get first char.
        char w1 = getc(stream);

        // Get second char.
        char w0 = getc(stream);

        // Fail if date failed.
        if (w1 == -1 || w0 == -1) {
                printf("lvc: invalid date string specified\n");
                return 1;
        }

        // Close the stream.
        pclose(stream);

        // Convert the chars to a number.
        char week = 10 * (w1 - '0') + (w0 - '0');

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
