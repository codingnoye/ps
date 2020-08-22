#include <iostream>
using namespace std;
const int U = 0;
const int D = 1;
const int F = 2;
const int B = 3;
const int L = 4;
const int R = 5;
const int X = 6;
char colors[] = {'w', 'y', 'r', 'o', 'g', 'b'};
int cube[7][3][3];
int rotater[8] = {0, 1, 2, 5, 8, 7, 6, 3};
int rev_rotater[8] = {0, 3, 6, 7, 8, 5, 2, 1};
void rotate(int side) {
    cube[X][0][0] = cube[side][0][0];
    cube[X][0][1] = cube[side][0][1];
    cube[X][0][2] = cube[side][0][2];

    cube[X][1][0] = cube[side][0][0];
    cube[side][0][0] = cube[side][2][0];
    cube[side][0][1] = cube[side][1][0];
    cube[side][0][2] = cube[X][1][0];

    cube[X][1][0] = cube[side][2][0];
    cube[side][2][0] = cube[side][2][2];
    cube[side][1][0] = cube[side][2][1];
    cube[side][0][0] = cube[X][1][0];

    cube[X][1][0] = cube[side][2][2];
    cube[side][2][2] = cube[side][0][2];
    cube[side][2][1] = cube[side][1][2];
    cube[side][2][0] = cube[X][1][0];

    cube[side][0][2] = cube[X][0][0];
    cube[side][1][2] = cube[X][0][1];
    cube[side][2][2] = cube[X][0][2];
}
void solve(char side, bool clockwise) {
    const int t = clockwise?1:3;
    for (int k=0; k<t; k++) {
        if (side=='U') {
            rotate(U);
            cube[X][0][0] = cube[F][0][0];
            cube[X][0][1] = cube[F][0][1];
            cube[X][0][2] = cube[F][0][2];

            cube[F][0][0] = cube[R][0][0];
            cube[F][0][1] = cube[R][0][1];
            cube[F][0][2] = cube[R][0][2];

            cube[R][0][0] = cube[B][0][0];
            cube[R][0][1] = cube[B][0][1];
            cube[R][0][2] = cube[B][0][2];

            cube[B][0][0] = cube[L][0][0];
            cube[B][0][1] = cube[L][0][1];
            cube[B][0][2] = cube[L][0][2];

            cube[L][0][0] = cube[X][0][0];
            cube[L][0][1] = cube[X][0][1];
            cube[L][0][2] = cube[X][0][2];
        } else if (side=='D') {
            rotate(D);
            cube[X][2][0] = cube[F][2][0];
            cube[X][2][1] = cube[F][2][1];
            cube[X][2][2] = cube[F][2][2];
            cube[F][2][0] = cube[L][2][0];
            cube[F][2][1] = cube[L][2][1];
            cube[F][2][2] = cube[L][2][2];
            cube[L][2][0] = cube[B][2][0];
            cube[L][2][1] = cube[B][2][1];
            cube[L][2][2] = cube[B][2][2];
            cube[B][2][0] = cube[R][2][0];
            cube[B][2][1] = cube[R][2][1];
            cube[B][2][2] = cube[R][2][2];
            cube[R][2][0] = cube[X][2][0];
            cube[R][2][1] = cube[X][2][1];
            cube[R][2][2] = cube[X][2][2];
        } else if (side=='F') {
            rotate(F);
            cube[X][0][0] = cube[U][2][0];
            cube[X][0][1] = cube[U][2][1];
            cube[X][0][2] = cube[U][2][2];

            cube[U][2][0] = cube[L][2][2]; 
            cube[U][2][1] = cube[L][1][2];
            cube[U][2][2] = cube[L][0][2];

            cube[L][2][2] = cube[D][2][0];
            cube[L][1][2] = cube[D][2][1];
            cube[L][0][2] = cube[D][2][2];

            cube[D][2][0] = cube[R][0][0];
            cube[D][2][1] = cube[R][1][0];
            cube[D][2][2] = cube[R][2][0];

            cube[R][0][0] = cube[X][0][0];
            cube[R][1][0] = cube[X][0][1];
            cube[R][2][0] = cube[X][0][2];
        } else if (side=='R') {
            rotate(R);
            cube[X][0][2] = cube[U][0][2];
            cube[X][1][2] = cube[U][1][2];
            cube[X][2][2] = cube[U][2][2];

            cube[U][0][2] = cube[F][0][2]; 
            cube[U][1][2] = cube[F][1][2];
            cube[U][2][2] = cube[F][2][2];

            cube[F][0][2] = cube[D][2][0];
            cube[F][1][2] = cube[D][1][0];
            cube[F][2][2] = cube[D][0][0];

            cube[D][2][0] = cube[B][2][0];
            cube[D][1][0] = cube[B][1][0];
            cube[D][0][0] = cube[B][0][0];

            cube[B][2][0] = cube[X][0][2];
            cube[B][1][0] = cube[X][1][2];
            cube[B][0][0] = cube[X][2][2];
        } else if (side=='B') {
            rotate(B);
            cube[X][0][0] = cube[U][0][0];
            cube[X][0][1] = cube[U][0][1];
            cube[X][0][2] = cube[U][0][2];

            cube[U][0][0] = cube[R][0][2]; 
            cube[U][0][1] = cube[R][1][2];
            cube[U][0][2] = cube[R][2][2];

            cube[R][0][2] = cube[D][0][0];
            cube[R][1][2] = cube[D][0][1];
            cube[R][2][2] = cube[D][0][2];

            cube[D][0][0] = cube[L][2][0];
            cube[D][0][1] = cube[L][1][0];
            cube[D][0][2] = cube[L][0][0];

            cube[L][2][0] = cube[X][0][0];
            cube[L][1][0] = cube[X][0][1];
            cube[L][0][0] = cube[X][0][2];
        } else if (side=='L') {
            rotate(L);
            cube[X][0][0] = cube[U][0][0];
            cube[X][1][0] = cube[U][1][0];
            cube[X][2][0] = cube[U][2][0];

            cube[U][0][0] = cube[B][2][2]; 
            cube[U][1][0] = cube[B][1][2];
            cube[U][2][0] = cube[B][0][2];

            cube[B][2][2] = cube[D][2][2];
            cube[B][1][2] = cube[D][1][2];
            cube[B][0][2] = cube[D][0][2];

            cube[D][2][2] = cube[F][0][0];
            cube[D][1][2] = cube[F][1][0];
            cube[D][0][2] = cube[F][2][0];

            cube[F][0][0] = cube[X][0][0];
            cube[F][1][0] = cube[X][1][0];
            cube[F][2][0] = cube[X][2][0];
        } 
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    for (int t=0; t<T; t++) {
        for (int s=0; s<6; s++) for (int i=0; i<9; i++) cube[s][i/3][i%3] = s;
        int Q; cin>>Q;
        string tmp;
        for (int q=0; q<Q; q++) {
            cin>>tmp;
            char side = tmp.at(0);
            bool clockwise = tmp.at(1) == '+';
            solve(side, clockwise);
        }
        for (int y=0; y<3; y++) {
            for (int x=0; x<3; x++) {
                cout<<colors[cube[U][y][x]];
            }
            cout<<'\n';
        }
    }
}