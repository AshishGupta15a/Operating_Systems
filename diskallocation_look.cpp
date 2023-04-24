#include<stdio.h>
#include<stdlib.h>
int main() 
{
    int n, head_pos, i, j, total_dist = 0;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the request queue: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head_pos);
    int min_req = 0, max_req = 149; 
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        if(head_pos < req[i]) {
            break;
        }
    }
    int left = i - 1; 
    int right = i; 
    printf("\nScan Disk Allocation Method:\n\n");
    printf("Head movement to the right:\n");
    for(i = right; i < n; i++) {
        printf("Servicing request %d, Seek time = %d\n", req[i], abs(head_pos - req[i]));
        total_dist += abs(head_pos - req[i]);
        head_pos = req[i];
    }
    printf("Head movement to the left:\n");
    for(i = left; i >= 0; i--) {
        printf("Servicing request %d, Seek time = %d\n", req[i], abs(head_pos - req[i]));
        total_dist += abs(head_pos - req[i]);
        head_pos = req[i];
    }
    printf("\nTotal seek time = %d\n", total_dist);
    return 0;
}

