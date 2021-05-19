#include <stdio.h>
#include <header.h>
int main(int argc, char *argv[])
{
    int map[ROWS][COLUMNS];
    int x = 0, y;  // coordinate
    char c;
    FILE *level;

    level = fopen(argv[1], "r");

    while (1)
    {
        c = fgetc(level);
        if (c == '\n')
        {
            break;
        }
        else
        {
            y = 0;
            map[x][y] = c;
            y++;
            while (1)
            {
                c = fgetc(level);
                if (c != '\n')
                {
                    map[x][y] = c;
                    y++;
                }
                else
                {
                    break;
                }
                
            }
            
        }
        x++;
    }
    fclose(level);
    for ( x = 0; x < 5; x++)
    {
        for ( y = 0; y < 9; y++)
        {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
    
    return 0;
}