// FIFO
#include<stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");

    int temp[frames];
    for(m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    for(m = 0; m < pages; m++) {
        s = 0;
        for(n = 0; n < frames; n++) {
            if(incomingStream[m] == temp[n]) {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m];
        } else if(s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
        printf("\n");
        printf("%d\t\t\t", incomingStream[m]);
        for(n = 0; n < frames; n++) {
            if(temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);

    return 0;
}

// LRU
#include<stdio.h>

int main() {
    int q[20], p[50], c = 0, c1, d, f, i, j, k = 0, n, r, t, b[20], c2[20];

    printf("Enter no of pages:");
    scanf("%d", &n);
    printf("Enter the reference string:");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter no of frames:");
    scanf("%d", &f);
    q[k] = p[k];
    printf("\n\t%d\n", q[k]);
    c++;
    k++;

    for(i = 1; i < n; i++) {
        c1 = 0;
        for(j = 0; j < f; j++) {
            if(p[i] != q[j])
                c1++;
        }
        if(c1 == f) {
            c++;
            if(k < f) {
                q[k] = p[i];
                k++;
                for(j = 0; j < k; j++)
                    printf("\t%d", q[j]);
                printf("\n");
            } else {
                for(r = 0; r < f; r++) {
                    c2[r] = 0;
                    for(j = i - 1; j < n; j--) {
                        if(q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for(r = 0; r < f; r++)
                    b[r] = c2[r];
                for(r = 0; r < f; r++) {
                    for(j = r; j < f; j++) {
                        if(b[r] < b[j]) {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }
                for(r = 0; r < f; r++) {
                    if(c2[r] == b[0])
                        q[r] = p[i];
                    printf("\t%d", q[r]);
                }
                printf("\n");
            }
        }
    }

    printf("\nThe no of page faults is %d", c);
}
