#include<iostream>
#include "Table.h"

using namespace std;

int main()
{
    Ball b;
    Table t;
    while(1)
    {
        int a;
        cout << "0 ---> Quit" << endl;
        cout << "1 ---> Enter ball:" << endl;
        cout << "2 ---> Enter Table four point: " << endl;
        cout << "3 ---> Enter Table width height start point: " << endl;
        cout << "4 ---> Strike" << endl;
        cout << "5 ---> print ball position" << endl;


        cin >> a;

        if(a == 0)
            break;

        if(a == 1)
        {
            float x, y, d;
            cout << "Enter x, y, d" << endl;
            cin >> x >> y >> d;
            b = Ball({x, y}, d);
            if(t.get_is_valid())
                t.change_ball(b);
            else
                cout << "Table is not valid" << endl;
        }


        if(a == 2)
        {
            Point p[4];
            for(int i = 0;i < 4;i++)
            {
                cout << "Enter: x, y" << endl;
                cin >> p[i].x >> p[i].y;
            }

            float x, y, d;
            cout << "Enter x, y, d" << endl;
            cin >> x >> y >> d;
            b = Ball({x, y}, d);

            t = Table(p[0], p[1], p[2], p[3], b);

        }

        if(a == 3)
        {
            int w, h;
            float x, y;
            cout << "Enter: width, height, x, y" << endl;
            cin >> w >> h >> x >> y;

            float x1, y1, d;
            cout << "Enter x, y, d" << endl;
            cin >> x >> y >> d;
            b = Ball({x1, y1}, d);

            t = Table({x, y}, w, h, b);
        }

        if(a == 4)
        {
            if(!t.get_is_valid())
            {
                cout << "Table is not valid" << endl;
                continue;
            }

            float x, y, power;
            cout << "Enter: x, y, power" << endl;

            cin >> x >> y >> power;
            t.strike({x, y}, power);
        }

        if(a == 5)
            t.get_ball().print();

    }
    return 0;
}