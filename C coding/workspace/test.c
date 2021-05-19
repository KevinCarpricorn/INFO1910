#include <stdio.h>

#define ROWS 20
#define COLUMNS 60
struct object
    {
        int x;
        int y;
    };

struct platform
{
    int switcher_x;
    int switcher_y;
    int key_x;
    int key_y;
    int status;  // on(1) or off(0)
};

int main(int argc, char *argv[])
{
    int map[ROWS][COLUMNS];
    int x = 0, y, i;  // coordinate
    char cha;
    FILE *level;
    struct object P;
    struct object X;
    struct platform a;
    struct platform b;
    struct platform c;
    struct platform d;
    struct platform e;
    struct platform f;
    struct platform g;
    struct platform h;
    level = fopen(argv[1], "r");

    while (1)
    {
        cha = fgetc(level);
        if (cha == '\n')
        {
            break;
        }
        else
        {
            y = 0;
            map[x][y] = cha;
            y++;
            while (1)
            {
                cha = fgetc(level);
                if (cha != '\n')
                {
                    map[x][y] = cha;
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

    while (1)
    {
        i = 0;
        cha = fgetc(level);
        if (cha == EOF)
        {
            break;
        }
        switch (cha)
        {
        case 'P':
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    P.x = (int)cha; 
                    i++;
                }
                else if (i == 4)
                {
                    P.y = (int)cha;
                    i++;
                }
                else if (i == 5)
                {
                    break;
                }   
            }
            break;

        case 'X':
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    X.x = (int)cha; 
                    i++;
                }
                else if (i == 4)
                {
                    X.y = (int)cha;
                    i++;
                }
                else if (i == 5)
                {
                    break;
                }
            }
            break;
        
        case 'a': 
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    a.switcher_x = (int)cha;
                    i++;
                }
                else if (i == 4)
                {
                    a.switcher_y = (int)cha;
                    i++;
                }
                else if (i == 6)
                {
                    a.key_x = (int)cha;
                    i++;
                }
                else if (i == 8)
                {
                    a.key_y = (int)cha;
                    i++;
                }
                else if (i ==10)
                {
                    a.status = (int)cha;
                    i++;
                }
                else if (i == 11)
                {
                    break;
                }
            }
            break;
        
        case 'b': 
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    b.switcher_x = (int)cha;
                    i++;
                }
                else if (i == 4)
                {
                    b.switcher_y = (int)cha;
                    i++;
                }
                else if (i == 6)
                {
                    b.key_x = (int)cha;
                    i++;
                }
                else if (i == 8)
                {
                    b.key_y = (int)cha;
                    i++;
                }
                else if (i ==10)
                {
                    b.status = (int)cha;
                    i++;
                }
                else if (i == 11)
                {
                    break;
                }
            }
            break;

        case 'c': 
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    c.switcher_x = (int)cha;
                    i++;
                }
                else if (i == 4)
                {
                    c.switcher_y = (int)cha;
                    i++;
                }
                else if (i == 6)
                {
                    c.key_x = (int)cha;
                    i++;
                }
                else if (i == 8)
                {
                    c.key_y = (int)cha;
                    i++;
                }
                else if (i ==10)
                {
                    c.status = (int)cha;
                    i++;
                }
                else if (i == 11)
                {
                    break;
                }
            }
            break;
        
        case 'd': 
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    d.switcher_x = (int)cha;
                    i++;
                }
                else if (i == 4)
                {
                    d.switcher_y = (int)cha;
                    i++;
                }
                else if (i == 6)
                {
                    d.key_x = (int)cha;
                    i++;
                }
                else if (i == 8)
                {
                    d.key_y = (int)cha;
                    i++;
                }
                else if (i ==10)
                {
                    d.status = (int)cha;
                    i++;
                }
                else if (i == 11)
                {
                    break;
                }
            }
            break;

        case 'e': 
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    e.switcher_x = (int)cha;
                    i++;
                }
                else if (i == 4)
                {
                    e.switcher_y = (int)cha;
                    i++;
                }
                else if (i == 6)
                {
                    e.key_x = (int)cha;
                    i++;
                }
                else if (i == 8)
                {
                    e.key_y = (int)cha;
                    i++;
                }
                else if (i ==10)
                {
                    e.status = (int)cha;
                    i++;
                }
                else if (i == 11)
                {
                    break;
                }
            }
            break;

        case 'f': 
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    f.switcher_x = (int)cha;
                    i++;
                }
                else if (i == 4)
                {
                    f.switcher_y = (int)cha;
                    i++;
                }
                else if (i == 6)
                {
                    f.key_x = (int)cha;
                    i++;
                }
                else if (i == 8)
                {
                    f.key_y = (int)cha;
                    i++;
                }
                else if (i ==10)
                {
                    f.status = (int)cha;
                    i++;
                }
                else if (i == 11)
                {
                    break;
                }
            }
            break;

        case 'g': 
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    g.switcher_x = (int)cha;
                    i++;
                }
                else if (i == 4)
                {
                    g.switcher_y = (int)cha;
                    i++;
                }
                else if (i == 6)
                {
                    g.key_x = (int)cha;
                    i++;
                }
                else if (i == 8)
                {
                    g.key_y = (int)cha;
                    i++;
                }
                else if (i ==10)
                {
                    g.status = (int)cha;
                    i++;
                }
                else if (i == 11)
                {
                    break;
                }
            }
            break;

        case 'h': 
            while (1)
            {
                cha = fgetc(level);
                i++;
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                {
                    continue;
                    i++;
                }
                else if (i == 2)
                {
                    h.switcher_x = (int)cha;
                    i++;
                }
                else if (i == 4)
                {
                    h.switcher_y = (int)cha;
                    i++;
                }
                else if (i == 6)
                {
                    h.key_x = (int)cha;
                    i++;
                }
                else if (i == 8)
                {
                    h.key_y = (int)cha;
                    i++;
                }
                else if (i ==10)
                {
                    h.status = (int)cha;
                    i++;
                }
                else if (i == 11)
                {
                    break;
                }
            }
            break;
        }
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