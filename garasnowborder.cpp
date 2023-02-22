#include <iostream>
#include <cmath>
using namespace std;


struct s_snow
{
    int matricola;
    string cognome;
    int kmt;
} snow, vet_snow[20];;

int genera()
{
    srand(time(NULL));
    int x1=0,y1=0,x=0,y=0,dist1=0,dist=0,giri=0;
    giri=rand()%5+25;
    
    for(int i=0; i<giri; i++)
    {
        x=rand()%100;
        y=rand()%100;
        dist1=sqrt((pow(x,2)-pow(x1,2))+(pow(y,2)-pow(y1,2)));
        x1=x;
        y1=y;
        dist=dist+dist1;
    }
    
    return dist;
}

void gara()
{
    int n=0,dista=0;
    
    cout<<"Quanti partecipanti si vuole far gareggiare? "<<endl;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        vet_snow[i].matricola=i+1;
        
        cout<<"Inserire cognome partecipante "<<i+1;
        cin>>vet_snow[i].cognome;
        
        vet_snow[i].kmt=genera();
    }
        
    
    
}


int main()
{
    
     
    
    int scelta;
        do
        {
            cout<<endl<<"===== MENU ====="<<endl;
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

