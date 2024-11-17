#include "LoadLevel.h"
#include <iostream>

void LoadLevel(std::vector<Bottle> &bottles, int level)
{
    bottles.clear();

    switch (level)
    {
    case 1:
        bottles.resize(8); // 6 playable bottles + 2 empty bottles
        bottles[0].push('P');
        bottles[0].push('O');
        bottles[0].push('R');
        bottles[0].push('Y');

        bottles[1].push('P');
        bottles[1].push('G');
        bottles[1].push('O');
        bottles[1].push('R');

        bottles[2].push('P');
        bottles[2].push('G');
        bottles[2].push('B');
        bottles[2].push('O');

        bottles[3].push('O');
        bottles[3].push('B');
        bottles[3].push('R');
        bottles[3].push('Y');

        bottles[4].push('G');
        bottles[4].push('P');
        bottles[4].push('G');
        bottles[4].push('R');

        bottles[5].push('Y');
        bottles[5].push('B');
        bottles[5].push('Y');
        bottles[5].push('B');
        break;

    case 2:
        bottles.resize(7); // 5 playable bottles + 2 empty bottles
        bottles[0].push('O');
        bottles[0].push('R');
        bottles[0].push('R');
        bottles[0].push('G');

        bottles[1].push('B');
        bottles[1].push('O');
        bottles[1].push('G');
        bottles[1].push('O');

        bottles[2].push('B');
        bottles[2].push('R');
        bottles[2].push('Y');
        bottles[2].push('G');

        bottles[3].push('B');
        bottles[3].push('Y');
        bottles[3].push('G');
        bottles[3].push('Y');

        bottles[4].push('B');
        bottles[4].push('Y');
        bottles[4].push('R');
        bottles[4].push('O');
        break;

    case 3:
        bottles.resize(8); // 6 playable bottles + 2 empty bottles
        bottles[0].push('P');
        bottles[0].push('B');
        bottles[0].push('P');
        bottles[0].push('G');

        bottles[1].push('P');
        bottles[1].push('B');
        bottles[1].push('Y');
        bottles[1].push('R');

        bottles[2].push('O');
        bottles[2].push('B');
        bottles[2].push('O');
        bottles[2].push('Y');

        bottles[3].push('O');
        bottles[3].push('R');
        bottles[3].push('P');
        bottles[3].push('G');

        bottles[4].push('B');
        bottles[4].push('Y');
        bottles[4].push('G');
        bottles[4].push('R');

        bottles[5].push('Y');
        bottles[5].push('R');
        bottles[5].push('O');
        bottles[5].push('G');
        break;

    case 4:
        bottles.resize(8); // 6 playable bottles + 2 empty bottles
        bottles[0].push('O');
        bottles[0].push('R');
        bottles[0].push('O');
        bottles[0].push('R');

        bottles[1].push('O');
        bottles[1].push('Y');
        bottles[1].push('R');
        bottles[1].push('P');

        bottles[2].push('G');
        bottles[2].push('P');
        bottles[2].push('Y');
        bottles[2].push('G');

        bottles[3].push('G');
        bottles[3].push('B');
        bottles[3].push('O');
        bottles[3].push('B');

        bottles[4].push('B');
        bottles[4].push('G');
        bottles[4].push('Y');
        bottles[4].push('R');

        bottles[5].push('Y');
        bottles[5].push('P');
        bottles[5].push('B');
        bottles[5].push('P');
        break;

    case 5:
        bottles.resize(8); // 6 playable bottles + 2 empty bottles
        bottles[0].push('P');
        bottles[0].push('G');
        bottles[0].push('Y');
        bottles[0].push('P');

        bottles[1].push('O');
        bottles[1].push('R');
        bottles[1].push('B');
        bottles[1].push('O');

        bottles[2].push('G');
        bottles[2].push('P');
        bottles[2].push('B');
        bottles[2].push('O');

        bottles[3].push('G');
        bottles[3].push('O');
        bottles[3].push('Y');
        bottles[3].push('B');

        bottles[4].push('G');
        bottles[4].push('Y');
        bottles[4].push('R');
        bottles[4].push('B');

        bottles[5].push('Y');
        bottles[5].push('R');
        bottles[5].push('P');
        bottles[5].push('R');
        break;

    case 6:
        bottles.resize(9); // 7 playable bottles + 2 empty bottles
        bottles[0].push('C');
        bottles[0].push('C');
        bottles[0].push('P');
        bottles[0].push('B');

        bottles[1].push('O');
        bottles[1].push('O');
        bottles[1].push('C');
        bottles[1].push('O');

        bottles[2].push('O');
        bottles[2].push('Y');
        bottles[2].push('R');
        bottles[2].push('B');

        bottles[3].push('G');
        bottles[3].push('P');
        bottles[3].push('R');
        bottles[3].push('B');

        bottles[4].push('G');
        bottles[4].push('P');
        bottles[4].push('Y');
        bottles[4].push('P');

        bottles[5].push('R');
        bottles[5].push('G');
        bottles[5].push('Y');
        bottles[5].push('R');

        bottles[6].push('Y');
        bottles[6].push('G');
        bottles[6].push('C');
        bottles[6].push('B');
        break;

    case 7:
        bottles.resize(9); // 7 playable bottles + 2 empty bottles
        bottles[0].push('C');
        bottles[0].push('O');
        bottles[0].push('C');
        bottles[0].push('O');

        bottles[1].push('P');
        bottles[1].push('R');
        bottles[1].push('O');
        bottles[1].push('C');

        bottles[2].push('O');
        bottles[2].push('P');
        bottles[2].push('G');
        bottles[2].push('C');

        bottles[3].push('B');
        bottles[3].push('R');
        bottles[3].push('B');
        bottles[3].push('G');

        bottles[4].push('B');
        bottles[4].push('G');
        bottles[4].push('Y');
        bottles[4].push('G');

        bottles[5].push('R');
        bottles[5].push('Y');
        bottles[5].push('P');
        bottles[5].push('Y');

        bottles[6].push('Y');
        bottles[6].push('R');
        bottles[6].push('B');
        bottles[6].push('P');
        break;

    case 8:
        bottles.resize(8); // 6 playable bottles + 2 empty bottles
        bottles[0].push('O');
        bottles[0].push('P');
        bottles[0].push('G');
        bottles[0].push('P');

        bottles[1].push('B');
        bottles[1].push('O');
        bottles[1].push('G');
        bottles[1].push('B');

        bottles[2].push('B');
        bottles[2].push('G');
        bottles[2].push('Y');
        bottles[2].push('Y');

        bottles[3].push('R');
        bottles[3].push('O');
        bottles[3].push('Y');
        bottles[3].push('P');

        bottles[4].push('R');
        bottles[4].push('B');
        bottles[4].push('G');
        bottles[4].push('P');

        bottles[5].push('R');
        bottles[5].push('R');
        bottles[5].push('O');
        bottles[5].push('Y');
        break;

    case 9:
        bottles.resize(10); // 8 playable bottles + 2 empty bottles
        bottles[0].push('S');
        bottles[0].push('C');
        bottles[0].push('S');
        bottles[0].push('R');

        bottles[1].push('C');
        bottles[1].push('R');
        bottles[1].push('C');
        bottles[1].push('C');

        bottles[2].push('P');
        bottles[2].push('S');
        bottles[2].push('S');
        bottles[2].push('O');

        bottles[3].push('P');
        bottles[3].push('G');
        bottles[3].push('G');
        bottles[3].push('G');

        bottles[4].push('G');
        bottles[4].push('Y');
        bottles[4].push('B');
        bottles[4].push('B');

        bottles[5].push('B');
        bottles[5].push('Y');
        bottles[5].push('O');
        bottles[5].push('R');

        bottles[6].push('R');
        bottles[6].push('P');
        bottles[6].push('Y');
        bottles[6].push('O');

        bottles[7].push('Y');
        bottles[7].push('P');
        bottles[7].push('O');
        bottles[7].push('B');
        break;

    case 10:
        bottles.resize(11); // 9 playable bottles + 2 empty bottles
        bottles[0].push('G');
        bottles[0].push('S');
        bottles[0].push('B');
        bottles[0].push('O');

        bottles[1].push('S');
        bottles[1].push('O');
        bottles[1].push('D');
        bottles[1].push('C');

        bottles[2].push('P');
        bottles[2].push('C');
        bottles[2].push('P');
        bottles[2].push('G');

        bottles[3].push('O');
        bottles[3].push('R');
        bottles[3].push('O');
        bottles[3].push('D');

        bottles[4].push('B');
        bottles[4].push('P');
        bottles[4].push('P');
        bottles[4].push('G');

        bottles[5].push('B');
        bottles[5].push('D');
        bottles[5].push('C');
        bottles[5].push('C');

        bottles[6].push('R');
        bottles[6].push('R');
        bottles[6].push('S');
        bottles[6].push('R');

        bottles[7].push('Y');
        bottles[7].push('G');
        bottles[7].push('D');
        bottles[7].push('Y');

        bottles[8].push('Y');
        bottles[8].push('B');
        bottles[8].push('Y');
        bottles[8].push('S');
        break;

    case 11:
        bottles.resize(10); // 8 playable bottles + 2 empty bottles
        bottles[0].push('S');
        bottles[0].push('P');
        bottles[0].push('O');
        bottles[0].push('C');

        bottles[1].push('P');
        bottles[1].push('O');
        bottles[1].push('Y');
        bottles[1].push('P');

        bottles[2].push('O');
        bottles[2].push('C');
        bottles[2].push('Y');
        bottles[2].push('S');

        bottles[3].push('G');
        bottles[3].push('B');
        bottles[3].push('P');
        bottles[3].push('R');

        bottles[4].push('G');
        bottles[4].push('Y');
        bottles[4].push('G');
        bottles[4].push('C');

        bottles[5].push('B');
        bottles[5].push('G');
        bottles[5].push('S');
        bottles[5].push('C');

        bottles[6].push('B');
        bottles[6].push('B');
        bottles[6].push('R');
        bottles[6].push('O');

        bottles[7].push('Y');
        bottles[7].push('S');
        bottles[7].push('R');
        bottles[7].push('R');
        break;

    case 12:
        bottles.resize(11); // 9 playable bottles + 2 empty bottles
        bottles[0].push('G');
        bottles[0].push('D');
        bottles[0].push('B');
        bottles[0].push('S');

        bottles[1].push('C');
        bottles[1].push('D');
        bottles[1].push('R');
        bottles[1].push('Y');

        bottles[2].push('P');
        bottles[2].push('P');
        bottles[2].push('P');
        bottles[2].push('S');

        bottles[3].push('O');
        bottles[3].push('O');
        bottles[3].push('Y');
        bottles[3].push('G');

        bottles[4].push('D');
        bottles[4].push('G');
        bottles[4].push('Y');
        bottles[4].push('P');

        bottles[5].push('B');
        bottles[5].push('S');
        bottles[5].push('O');
        bottles[5].push('O');

        bottles[6].push('B');
        bottles[6].push('C');
        bottles[6].push('C');
        bottles[6].push('S');

        bottles[7].push('R');
        bottles[7].push('G');
        bottles[7].push('R');
        bottles[7].push('Y');

        bottles[8].push('R');
        bottles[8].push('C');
        bottles[8].push('D');
        bottles[8].push('B');

        break;

    case 13:
        bottles.resize(9); // 7 playable bottles + 2 empty bottles
        bottles[0].push('C');
        bottles[0].push('O');
        bottles[0].push('G');
        bottles[0].push('O');

        bottles[1].push('C');
        bottles[1].push('O');
        bottles[1].push('R');
        bottles[1].push('C');

        bottles[2].push('G');
        bottles[2].push('Y');
        bottles[2].push('B');
        bottles[2].push('O');

        bottles[3].push('B');
        bottles[3].push('G');
        bottles[3].push('C');
        bottles[3].push('P');

        bottles[4].push('B');
        bottles[4].push('R');
        bottles[4].push('Y');
        bottles[4].push('P');

        bottles[5].push('R');
        bottles[5].push('Y');
        bottles[5].push('B');
        bottles[5].push('P');

        bottles[6].push('Y');
        bottles[6].push('R');
        bottles[6].push('G');
        bottles[6].push('P');

        break;

    case 14:
        bottles.resize(10); // 8 playable bottles + 2 empty bottles
        bottles[0].push('S');
        bottles[0].push('Y');
        bottles[0].push('C');
        bottles[0].push('R');

        bottles[1].push('C');
        bottles[1].push('G');
        bottles[1].push('R');
        bottles[1].push('S');

        bottles[2].push('P');
        bottles[2].push('R');
        bottles[2].push('P');
        bottles[2].push('Y');

        bottles[3].push('O');
        bottles[3].push('P');
        bottles[3].push('B');
        bottles[3].push('C');

        bottles[4].push('O');
        bottles[4].push('O');
        bottles[4].push('S');
        bottles[4].push('B');

        bottles[5].push('O');
        bottles[5].push('B');
        bottles[5].push('Y');
        bottles[5].push('P');

        bottles[6].push('G');
        bottles[6].push('C');
        bottles[6].push('G');
        bottles[6].push('G');

        bottles[7].push('Y');
        bottles[7].push('S');
        bottles[7].push('R');
        bottles[7].push('B');

        break;

    case 15:
        bottles.resize(12); // 10 playable bottles + 2 empty bottles
        bottles[0].push('M');
        bottles[0].push('Y');
        bottles[0].push('G');
        bottles[0].push('G');

        bottles[1].push('G');
        bottles[1].push('D');
        bottles[1].push('R');
        bottles[1].push('M');

        bottles[2].push('S');
        bottles[2].push('M');
        bottles[2].push('Y');
        bottles[2].push('C');

        bottles[3].push('S');
        bottles[3].push('C');
        bottles[3].push('D');
        bottles[3].push('Y');

        bottles[4].push('C');
        bottles[4].push('C');
        bottles[4].push('R');
        bottles[4].push('Y');

        bottles[5].push('P');
        bottles[5].push('P');
        bottles[5].push('P');
        bottles[5].push('O');

        bottles[6].push('O');
        bottles[6].push('S');
        bottles[6].push('S');
        bottles[6].push('R');

        bottles[7].push('O');
        bottles[7].push('O');
        bottles[7].push('M');
        bottles[7].push('R');

        bottles[8].push('D');
        bottles[8].push('G');
        bottles[8].push('B');
        bottles[8].push('P');

        bottles[9].push('B');
        bottles[9].push('B');
        bottles[9].push('B');
        bottles[9].push('D');

        break;

    case 16:
        bottles.resize(11); // 9 playable bottles + 2 empty bottles
        bottles[0].push('G');
        bottles[0].push('B');
        bottles[0].push('R');
        bottles[0].push('G');

        bottles[1].push('G');
        bottles[1].push('R');
        bottles[1].push('C');
        bottles[1].push('Y');

        bottles[2].push('S');
        bottles[2].push('O');
        bottles[2].push('R');
        bottles[2].push('O');

        bottles[3].push('C');
        bottles[3].push('D');
        bottles[3].push('S');
        bottles[3].push('S');

        bottles[4].push('P');
        bottles[4].push('Y');
        bottles[4].push('B');
        bottles[4].push('B');

        bottles[5].push('D');
        bottles[5].push('C');
        bottles[5].push('R');
        bottles[5].push('Y');

        bottles[6].push('D');
        bottles[6].push('P');
        bottles[6].push('O');
        bottles[6].push('O');

        bottles[7].push('B');
        bottles[7].push('G');
        bottles[7].push('P');
        bottles[7].push('C');

        bottles[8].push('Y');
        bottles[8].push('S');
        bottles[8].push('D');
        bottles[8].push('P');

        break;

    case 17:
        bottles.resize(10); // 8 playable bottles + 2 empty bottles
        bottles[0].push('C');
        bottles[0].push('G');
        bottles[0].push('O');
        bottles[0].push('R');

        bottles[1].push('P');
        bottles[1].push('O');
        bottles[1].push('R');
        bottles[1].push('G');

        bottles[2].push('O');
        bottles[2].push('Y');
        bottles[2].push('B');
        bottles[2].push('S');

        bottles[3].push('B');
        bottles[3].push('P');
        bottles[3].push('G');
        bottles[3].push('S');

        bottles[4].push('R');
        bottles[4].push('B');
        bottles[4].push('P');
        bottles[4].push('G');

        bottles[5].push('R');
        bottles[5].push('Y');
        bottles[5].push('C');
        bottles[5].push('S');

        bottles[6].push('Y');
        bottles[6].push('C');
        bottles[6].push('O');
        bottles[6].push('B');

        bottles[7].push('Y');
        bottles[7].push('P');
        bottles[7].push('C');
        bottles[7].push('S');

        break;

    case 18:
        bottles.resize(8); // 6 playable bottles + 2 empty bottles
        bottles[0].push('P');
        bottles[0].push('O');
        bottles[0].push('R');
        bottles[0].push('G');

        bottles[1].push('B');
        bottles[1].push('P');
        bottles[1].push('O');
        bottles[1].push('Y');

        bottles[2].push('B');
        bottles[2].push('G');
        bottles[2].push('P');
        bottles[2].push('R');

        bottles[3].push('R');
        bottles[3].push('P');
        bottles[3].push('Y');
        bottles[3].push('O');

        bottles[4].push('R');
        bottles[4].push('B');
        bottles[4].push('Y');
        bottles[4].push('B');

        bottles[5].push('Y');
        bottles[5].push('G');
        bottles[5].push('O');
        bottles[5].push('G');

        break;

    case 19:
        bottles.resize(9); // 7 playable bottles + 2 empty bottles
        bottles[0].push('C');
        bottles[0].push('P');
        bottles[0].push('B');
        bottles[0].push('G');

        bottles[1].push('C');
        bottles[1].push('R');
        bottles[1].push('Y');
        bottles[1].push('R');

        bottles[2].push('P');
        bottles[2].push('O');
        bottles[2].push('G');
        bottles[2].push('O');

        bottles[3].push('O');
        bottles[3].push('P');
        bottles[3].push('G');
        bottles[3].push('B');

        bottles[4].push('G');
        bottles[4].push('B');
        bottles[4].push('Y');
        bottles[4].push('Y');

        bottles[5].push('R');
        bottles[5].push('C');
        bottles[5].push('P');
        bottles[5].push('C');

        bottles[6].push('R');
        bottles[6].push('B');
        bottles[6].push('O');
        bottles[6].push('Y');

        break;

    case 20:
        bottles.resize(8); // 6 playable bottles + 2 empty bottles
        bottles[0].push('O');
        bottles[0].push('P');
        bottles[0].push('Y');
        bottles[0].push('R');

        bottles[1].push('O');
        bottles[1].push('G');
        bottles[1].push('P');
        bottles[1].push('Y');

        bottles[2].push('O');
        bottles[2].push('B');
        bottles[2].push('G');
        bottles[2].push('Y');

        bottles[3].push('B');
        bottles[3].push('P');
        bottles[3].push('B');
        bottles[3].push('G');

        bottles[4].push('B');
        bottles[4].push('R');
        bottles[4].push('G');
        bottles[4].push('Y');

        bottles[5].push('R');
        bottles[5].push('O');
        bottles[5].push('P');
        bottles[5].push('R');

        break;

    default:
        cout << "INVALID LEVEL !!!\n";
        break;
    }
}
