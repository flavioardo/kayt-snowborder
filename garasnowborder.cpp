#include <iostream>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;


struct s_snow
{
    int matricola;
    string cognome;
    int x;
    int y;
    int kmt;
} snow, vet_snow[20];

int genera()
{
    srand(time(NULL));
    int x1=0,y1=0,x=0,y=0,dist1=0,dist=0,giri=0;
    giri=rand()%5+25;
    
  
    for(int i=0; i<giri; i++)
    {
        //vet_snow[n].x[i]=x;
        //vet_snow[n].y[i]=y;
        x=rand()%100;
        y=rand()%100;
        dist1=sqrt((pow(x,2)-pow(x1,2))+(pow(y,2)-pow(y1,2)));
        x1=x;
        y1=y;
        dist=dist+dist1;
    }
        
    return dist;
}

void carica_vet()
{
    ifstream fin("gara.txt",ios::in);
    string app;
    while(!fin.eof())
    {
        getline(fin,app);
        for(int i=0; i<5; i++)
        {
            fin>>vet_snow[i].matricola>>vet_snow[i].cognome;
        }
    }
    fin.close();
}

void leggi()
{
    carica_vet();
    
    cout<<"I partecipanti sono :"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<vet_snow[i].matricola<<" "<<vet_snow[i].cognome<<" "<<endl;
    }
}

void file_agg()
{
    ofstream fout("gara.txt");
    
    for(int i=0; i<5; i++)
    {
        fout<<endl<<vet_snow[i].matricola<<" "<<vet_snow[i].cognome;
        
    }
    
    fout.close();
}

int main()
{
    
     
    
    int scelta;
        do
        {
            cout<<endl<<"===== MENU ====="<<endl;
            cout<<"1) Visualizza partecipanti"<<endl;
            cout<<"2) Genera gara e visualizza il risultato"<<endl;
            cout<<"3)USCITA "<<endl;
            cout<<"Inserire una scelta: "<<endl;
            cin>>scelta;
            switch(scelta){
                case 1:
                        leggi();
                        break;
                    case 2:
                        
                        
                        break;
            }

        }while(scelta!=3);
        

    return 0;
}