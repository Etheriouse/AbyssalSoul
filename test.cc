#include <iostream>
#include <vector>

using namespace std;

// static constexpr int X_max_map = 64;
// static constexpr int Y_max_map = 64;

// class cam
// {

// public:
//     cam();
//     cam(int x, int y);
//     vector<vector<int>> surface;
//     int map[64][64];
//     int x;
//     int y;
//     void update();

// private:
// };

// cam::cam()
// {
//     this->surface = vector<vector<int>>();
//     surface.push_back(vector<int>());
//     this->x = 0;
//     this->y = 0;
//     for (int i = 0; i < 64; i++)
//     {
//         for (int y = 0; y < 64; y++)
//         {
//             this->map[i][y] = 0;
//         }
//     }
// }

// cam::cam(int x, int y)
// {
//     this->surface = vector<vector<int>>(y, vector<int>(x, 0));
//     this->x = x / 2;
//     this->y = y / 2;
//     for (int i = 0; i < 64; i++)
//     {
//         for (int z = 0; z < 64; z++)
//         {
//             this->map[i][z] = i + z;
//         }
//     }
// }

// void cam::update()
// {
//     int startX = x - 16;
//     int endX = x + 16;
//     int startY = y - 9;
//     int endY = y + 9;

//     if (x - 16 < 0)
//     {
//         startX -= (x - 16);
//         endX -= (x - 16);
//     }
//     else if (x + 16 > X_max_map)
//     {
//         startX += (X_max_map - x - 16);
//         endX += (X_max_map - x - 16);
//     }

//     if (y - 9 < 0)
//     {
//         startY -= (y - 9);
//         endY -= (y - 9);
//     }
//     else if (y + 9 > Y_max_map)
//     {
//         startY += (Y_max_map - y - 9);
//         endY += (Y_max_map - y - 9);
//     }

//     cout << "pos Player: " << x << " " << y << endl;

//     cout << "X: " << startX << " to " << endX << endl;
//     cout << "Y: " << startY << " to " << endY << endl;

//     for (int i = startY, a = 0; i < endY; a++, i++)
//     {
//         for (int z = startX, b = 0; z < endX; b++, z++)
//         {
//             this->surface[a][b] = this->map[i][z];
//         }
//     }
// }

// void show(cam c)
// {
//     int a = 0;
//     int b = 0;
//     for (auto &i : c.surface)
//     {
//         for (auto &y : i)
//         {
//             if (a == c.y && b == c.x)
//             {
//                 cout << "+ ";
//             }
//             else
//             {

//                 cout << y << " ";
//             }
//             b++;
//         }
//         a++;
//         cout << endl;
//         b = 0;
//     }
//     a = 0;
//     cout << endl;
//     cout << "center: " << c.x << ", " << c.y << endl;
// }

int main(int argc, char const *argv[])
{

    int countI = 0;
    int countY = 0;
    for (int i = 0; i < 201; i += 1)
    {
        for (int y = 0; y < 201; y += 1)
        {
            //cout << countI << " " << countY << endl;
            if(countI == 25 && countY == 25) {
                cout << "#";
            }
            if(countI == 25) {
                countI = 0;
            }
            countI++;
        }
        if(countY == 25) {
            cout << endl;
            countY = 0;
        }
        countY++;
    }
    return 0;
}