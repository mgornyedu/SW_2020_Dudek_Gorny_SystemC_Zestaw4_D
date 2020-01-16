#include "SignalWrite.h"

#include <iostream>
using namespace std;

char SingleBottomLeftCorner = 192;
char SingleBottomRightCorner = 217;
char SingleTopLeftCorner = 218;
char SingleTopRightCorner = 191;
char SingleFloor = 196;
char SingleFloorUp = 194;
char SingleFloorDown = 193;
char SingleWall = 179;
char SingleWallLeft = 195;
char SingleWallRight = 180;
char SingleCross = 197;

char DoubleBottomLeftCorner = 200;
char DoubleBottomRightCorner = 188;
char DoubleTopLeftCorner = 201;
char DoubleTopRightCorner = 187;
char DoubleFloor = 205;
char DoubleFloorUp = 203;
char DoubleFloorDown = 202;
char DoubleWall = 186;
char DoubleWallLeft = 204;
char DoubleWallRight = 185;
char DoubleCross = 206;

const char AreaLight = 176;
const char AreaMedium = 177;
const char AreaSolid = 178;

void Write(int sw, int lights) {
    system("cls");

    WriteLights(lights);
    WriteSliders(sw);

    cout << endl << "NACIŒNIJ KLAWISZE [1] [2] [3] ABY PRZELACZYC SLIDERY.";
}

void WriteSliders(int sw)
{
    cout << "            " << SingleTopLeftCorner << SingleFloor << SingleFloor << SingleFloor
        << SingleFloor << SingleFloor << SingleFloor << SingleFloor
        << SingleFloor << SingleFloor << SingleFloor << SingleFloor
        << SingleTopRightCorner << endl;
    cout << "            " << SingleWall << "  SLIDERS  " << SingleWall << endl;
    cout << "            " << SingleWallLeft << SingleFloor << SingleFloor << SingleFloor
        << SingleFloorUp << SingleFloor << SingleFloor << SingleFloor
        << SingleFloorUp << SingleFloor << SingleFloor << SingleFloor
        << SingleWallRight << endl;
    cout << "            " << SingleWall
        << (sw & 4 ? "ON " : "   ") << SingleWall
        << (sw & 2 ? "ON " : "   ") << SingleWall
        << (sw & 1 ? "ON " : "   ") << SingleWall
        << endl;
    cout << "            " << SingleWall
        << (!(sw & 4) ? "OFF" : "   ") << SingleWall
        << (!(sw & 2) ? "OFF" : "   ") << SingleWall
        << (!(sw & 1) ? "OFF" : "   ") << SingleWall
        << endl;
    cout << "            " << SingleWallLeft << SingleFloor << SingleFloor << SingleFloor
        << SingleCross << SingleFloor << SingleFloor << SingleFloor
        << SingleCross << SingleFloor << SingleFloor << SingleFloor
        << SingleWallRight << endl;
    cout << "            " << SingleWall
        << " 3 " << SingleWall
        << " 2 " << SingleWall
        << " 1 " << SingleWall
        << endl;
    cout << "            " << SingleBottomLeftCorner << SingleFloor << SingleFloor << SingleFloor
        << SingleFloorDown << SingleFloor << SingleFloor << SingleFloor
        << SingleFloorDown << SingleFloor << SingleFloor << SingleFloor
        << SingleBottomRightCorner << endl;
}

void WriteLight1stLine(bool isOn, ostream& stream)
{
    if (isOn)
    {
        char res[] = { AreaLight, AreaMedium, AreaSolid, AreaSolid, AreaMedium, AreaLight, '\0' };
        stream << res;
    }
    else
        stream << "      \0";
}
void WriteLight2ndLine(bool isOn, ostream& stream)
{
    if (isOn)
    {
        char res[] = { AreaMedium, AreaSolid, AreaSolid, AreaSolid, AreaSolid, AreaMedium, '\0' };
        stream << res;
    }
    else
        stream << "      \0";
}
void WriteLight3rdLine(bool isOn, ostream& stream)
{
    if (isOn)
    {
        char res[] = { AreaLight, AreaMedium, AreaSolid, AreaSolid, AreaMedium, AreaLight, '\0' };
        stream << res;
    }
    else
        stream << "      \0";
}


void WriteLights(int sw)
{
    cout << endl << "   " << DoubleTopLeftCorner << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << "NS" << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleTopRightCorner
        << "    " << DoubleTopLeftCorner << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << "WE" << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleTopRightCorner << endl;

    cout << "   " << DoubleWall << "            " << DoubleWall << "    " << DoubleWall << "            " << DoubleWall << endl;

    cout << "   " << DoubleWall << "   ";
    WriteLight1stLine(sw == 0x0 || sw == 0x4 || sw == 0x2, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight1stLine(sw == 0x3 || sw == 0x7 || sw == 0x6, cout);
    cout << "   " << DoubleWall << endl;
    cout << "   " << DoubleWall << "   ";
    WriteLight2ndLine(sw == 0x0 || sw == 0x4 || sw == 0x2, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight2ndLine(sw == 0x3 || sw == 0x7 || sw == 0x6, cout);
    cout << "   " << DoubleWall << endl;
    cout << "   " << DoubleWall << "   ";
    WriteLight3rdLine(sw == 0x0 || sw == 0x4 || sw == 0x2, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight3rdLine(sw == 0x3 || sw == 0x7 || sw == 0x6, cout); cout << "   " << DoubleWall << endl;

    cout << "   " << DoubleWall << "            " << DoubleWall << "    " << DoubleWall << "            " << DoubleWall << endl;

    cout << "   " << DoubleWall << "   "; WriteLight1stLine(sw == 0x2 || sw == 0x6 || sw == 0x1 || sw == 0x5, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight1stLine(sw == 0x2 || sw == 0x6 || sw == 0x1 || sw == 0x5, cout);
    cout << "   " << DoubleWall << endl;
    cout << "   " << DoubleWall << "   ";
    WriteLight2ndLine(sw == 0x2 || sw == 0x6 || sw == 0x1 || sw == 0x5, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight2ndLine(sw == 0x2 || sw == 0x6 || sw == 0x1 || sw == 0x5, cout);
    cout << "   " << DoubleWall << endl;
    cout << "   " << DoubleWall << "   ";
    WriteLight3rdLine(sw == 0x2 || sw == 0x6 || sw == 0x1 || sw == 0x5, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight3rdLine(sw == 0x2 || sw == 0x6 || sw == 0x1 || sw == 0x5, cout);
    cout << "   " << DoubleWall << endl;

    cout << "   " << DoubleWall << "            " << DoubleWall << "    " << DoubleWall << "            " << DoubleWall << endl;

    cout << "   " << DoubleWall << "   ";
    WriteLight1stLine(sw == 0x3 || sw == 0x7, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight1stLine(sw == 0x0 || sw == 0x4, cout);
    cout << "   " << DoubleWall << endl;
    cout << "   " << DoubleWall << "   ";
    WriteLight2ndLine(sw == 0x3 || sw == 0x7, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight2ndLine(sw == 0x0 || sw == 0x4, cout);
    cout << "   " << DoubleWall << endl;
    cout << "   " << DoubleWall << "   ";
    WriteLight3rdLine(sw == 0x3 || sw == 0x7, cout);
    cout << "   " << DoubleWall << "    " << DoubleWall << "   ";
    WriteLight3rdLine(sw == 0x0 || sw == 0x4, cout);
    cout << "   " << DoubleWall << endl;

    cout << "   " << DoubleWall << "            " << DoubleWall << "    " << DoubleWall << "            " << DoubleWall << endl;

    cout << "   " << DoubleBottomLeftCorner << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleBottomRightCorner
        << "    " << DoubleBottomLeftCorner << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleFloor << DoubleBottomRightCorner << endl << endl;
}

