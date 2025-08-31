#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define N 1000000

int main() {
    int p2c[2], c2p[2];
    pid_t pid;
    int msg, reply;
    struct timeval start, end;

    pipe(p2c);
    pipe(c2p);
    pid = fork();

    if (pid == 0) {
        for (int i = 0; i < N; i++) {
            read(p2c[0], &msg, sizeof(msg));
            reply = msg + 1;  // just to "process" something
            write(c2p[1], &reply, sizeof(reply));
        }
    } else {
        gettimeofday(&start, NULL);
        for (int i = 0; i < N; i++) {
            msg = i;
            write(p2c[1], &msg, sizeof(msg));
            read(c2p[0], &reply, sizeof(reply));
        }
        gettimeofday(&end, NULL);

        long seconds = end.tv_sec - start.tv_sec;
        long usec = end.tv_usec - start.tv_usec;
        double elapsed = seconds + usec / 1000000.0;

        printf("Total time: %.6f sec\n", elapsed);
        printf("Requests/sec: %.2f\n", N / elapsed);
        printf("Avg round-trip: %.9f sec\n", elapsed / N);
    }
}
