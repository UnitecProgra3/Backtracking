#include <iostream>

using namespace std;

int fibo(int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 1;

    int a = fibo(n-1);
    int b = fibo(n-2);

    int c=a+b;

    return c;
}

const int SIZE_X=5;
const int SIZE_Y=5;
bool puedoLLegar(int x_inicio,int y_inicio,
                 int x_final, int y_final,
                 char tablero[SIZE_X][SIZE_Y],
                 int pasos)
{
    if(pasos<0)
        return false;

    if(tablero[x_final][y_final]=='#'
       || tablero[x_inicio][y_inicio]=='#')
        return false;

    if(x_inicio<0 || x_inicio>=SIZE_X
       || y_inicio<0 || y_inicio>=SIZE_Y)
       return false;

    if(x_final<0 || x_final>=SIZE_X
       || y_final<0 || y_final>=SIZE_Y)
       return false;

    if(x_inicio==x_final && y_inicio==y_final)
        return true;

    if(puedoLLegar(x_inicio+1,y_inicio,x_final,y_final,tablero,pasos-1))
        return true;
    if(puedoLLegar(x_inicio-1,y_inicio,x_final,y_final,tablero,pasos-1))
        return true;
    if(puedoLLegar(x_inicio,y_inicio+1,x_final,y_final,tablero,pasos-1))
        return true;
    if(puedoLLegar(x_inicio,y_inicio-1,x_final,y_final,tablero,pasos-1))
        return true;

    return false;

}

int main()
{
    char tablero[SIZE_X][SIZE_Y]={{'_','_','#','_','_'},
                                  {'#','_','#','_','_'},
                                  {'_','_','#','_','#'},
                                  {'_','#','#','_','_'},
                                  {'_','_','_','_','_'}
                                 };
    tablero[4][0]='x';
    for(int x=0;x<SIZE_X;x++)
    {
        for(int y=0;y<SIZE_Y;y++)
        {
            cout<<tablero[x][y]<<' ';
        }
        cout<<endl;
    }



    cout<<puedoLLegar(0,0,
                     0,4,
                     tablero,
                     13);

    return 0;
}
