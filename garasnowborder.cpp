#include <iostream>
#include <cmath>
using namespace std;
srand(time(NULL));

struct s_snow
{
    int matricola;
    string cognome;
    int x;
    int y;
}

int genera()
{
    int x1=0;
    int y1=0;
    
    for(int i=0; i<30; i++)
    {
        x=rand()%100;
        y=rand()%100;
        calcola(x,y);
        dist1=sqrt((pow(x,2)-pow(x1,2))+(pow(y,2)-pow(y1,2)))
        x1=x;
        y1=y;
        dist=dist+dist1;
    }
}

void gara()
{
    string scelta="";
    int c=1;
    
    do{
    
        cout<<"Inserire cognome partecipante: ";
        //cin>>cognome;
        cout<<"Vuole inserire un altro partecipante(si/no)";
        //cin>>scelta;
        
    
    }while(scelta!="no");
}


int main()
{
    
    int scelta;
        do
        {
            cout<<endl<<"MENU'"<<endl;
            cout<<"1) Genera gara"<<endl;
            cout<<"2) Visualizza risultato"<<endl;
            cout<<"3)USCITA "<<endl;
            cout<<"Inserire una scelta: "<<endl;
            cin>>scelta;
            switch(scelta){
                case 1:
                        gara();
                        break;
                    case 2:
                        
                        
                        break;
            }

        }while(scelta!=3);
        

    return 0;
}

