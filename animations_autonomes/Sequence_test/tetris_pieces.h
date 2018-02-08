#ifndef PIECES_H
#define PIECES_H

//Tetris pieces: these piece matrices are represented by their corresponding colors (1-7)
#define Z1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {1, 1, 0, 0}, \
    {0, 1, 1, 0}, \
}
#define Z2 { \
    {0, 0, 0, 0}, \
    {0, 1, 0, 0}, \
    {1, 1, 0, 0}, \
    {1, 0, 0, 0}, \
}
#define S1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {0, 2, 2, 0}, \
    {2, 2, 0, 0}, \
}
#define S2 { \
    {0, 0, 0, 0}, \
    {2, 0, 0, 0}, \
    {2, 2, 0, 0}, \
    {0, 2, 0, 0}, \
}
#define J1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {3, 3, 3, 0}, \
    {0, 0, 3, 0}, \
}
#define J2 { \
    {0, 0, 0, 0}, \
    {0, 3, 0, 0}, \
    {0, 3, 0, 0}, \
    {3, 3, 0, 0}, \
}
#define J3 { \
    {0, 0, 0, 0}, \
    {3, 0, 0, 0}, \
    {3, 3, 3, 0}, \
    {0, 0, 0, 0}, \
}
#define J4 { \
    {0, 0, 0, 0}, \
    {0, 3, 3, 0}, \
    {0, 3, 0, 0}, \
    {0, 3, 0, 0}, \
}
#define L1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {4, 4, 4, 0}, \
    {4, 0, 0, 0}, \
}
#define L2 { \
    {0, 0, 0, 0}, \
    {4, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 0, 0}, \
}
#define L3 { \
    {0, 0, 0, 0}, \
    {0, 0, 4, 0}, \
    {4, 4, 4, 0}, \
    {0, 0, 0, 0}, \
}
#define L4 { \
    {0, 0, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 4, 0}, \
}
#define T1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {6, 6, 6, 0}, \
    {0, 6, 0, 0}, \
}
#define T2 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {6, 6, 0, 0}, \
    {0, 6, 0, 0}, \
}
#define T3 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {6, 6, 6, 0}, \
    {0, 0, 0, 0}, \
}
#define T4 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {0, 6, 6, 0}, \
    {0, 6, 0, 0}, \
}
#define I1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {5, 5, 5, 5}, \
    {0, 0, 0, 0}, \
}
#define I2 { \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
}
#define O1 {  \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {0, 7, 7, 0}, \
    {0, 7, 7, 0}, \
}


#endif
