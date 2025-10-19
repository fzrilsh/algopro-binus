#include <stdio.h>
#include <strings.h>
#include <limits.h>
#include <stdlib.h>

int main(){
    int t;
    scanf("%d", &t);

    int *results[t];
    int roomSizes[t];
    for (int i = 0; i < t; i++)
    {
        int friends, tmp_rooms, tmp_visits;
        scanf("%d %d %d", &friends, &tmp_rooms, &tmp_visits);
        
        int *rooms = malloc(tmp_rooms * sizeof(int));
        for (int j = 0; j < tmp_rooms; j++)
        {
            rooms[j] = 0;
        }

        int friends_pattern[friends][tmp_rooms];
        for (int j = 0; j < friends; j++)
        {
            for (int k = 0; k < tmp_rooms; k++)
            {
                scanf("%d", &friends_pattern[j][k]);
            }
        }

        for (int j = 0; j < tmp_visits; j++)
        {
            int visit;
            scanf("%d", &visit);

            for (int k = 0; k < tmp_rooms; k++)
            {
                rooms[k] = !friends_pattern[visit - 1][k] ? rooms[k] : !rooms[k];
            }
        }
        
        results[i] = rooms;
        roomSizes[i] = tmp_rooms;
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d:\n", i+1);
        for (int j = 0; j < roomSizes[i]; j++)
        {
            printf("%s\n", results[i][j] ? "YES" : "NO");
        }   
    }
    
    

    return 0;
}