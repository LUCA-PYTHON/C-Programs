#include <stdio.h>

int main(void)
{
    int start;
    int stop;
    int motor;
    int symbole;
    int startApproved = 0;
    int stopApproved = 0;

    /* Waiting for input 0 or 1 from Start Taster */
    while (startApproved == 0) {
        printf("Start-Taster (0/1): ");

        if (scanf("%d", &start) == 1 && (start == 0 || start == 1)) {
            startApproved = 1;
        } else {
            printf("Please enter 0 or 1.\n");
        }

        /* EOF means: No more input will come */
        if (symbole == EOF && startApproved == 0) {
            return 1;
        }
    }

    /* Waiting for input 0 or 1 from Stop Taster */
    while (stopApproved == 0) {
        printf("Stop-Taster (0/1): ");

        if (scanf("%d", &stop) == 1 && (stop == 0 || stop == 1)) {
            stopApproved = 1;
        } else {
            printf("Please enter 0 or 1.\n");
        }

        if (symbole == EOF && stopApproved == 0) {
            return 1;
        }
    }

    /* The motor is only on when Start is 1 and Stop is 0. */
    if (start == 1 && stop == 0) {
        motor = 1;
    } else {
        motor = 0;
    }

    if (motor == 1) {
        printf("Motor: On\n");
    } else {
        printf("Motor: Off\n");
    }

    return 0;
}
