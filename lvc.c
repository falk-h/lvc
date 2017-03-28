#include <stdio.h>
//#include <stdlib.h>

int main(int argc, char *argv[]) {
                        
        FILE *weekstr = popen("date \"+%V\"", "r");
        char w1 = getc(weekstr);
        char w0 = getc(weekstr);
        pclose(weekstr);
        char week = 10 * (w1 - '0') + (w0 - '0');
        
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
