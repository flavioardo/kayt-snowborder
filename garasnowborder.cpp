#include <iostream>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;


struct s_snow
{
    int matricola;
    string cognome;
    int x[30];
    int y[30];
    int kmt;
} snow, vet_snow[20];

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
        cout<<endl<<vet_snow[i].matricola<<" "<<vet_snow[i].cognome<<" ";
    }
}

void leggi_agg(int giri)
{
    //carica_vet();
    
    cout<<"La gara e' :"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<endl<<vet_snow[i].matricola<<" "<<vet_snow[i].cognome<<" ";
        
        for(int j=0; j<giri; j++)
        {
            cout<<"("<<vet_snow[i].x[j]<<";"<<vet_snow[i].y[j]<<") ";
        }
    }
}

void pulisci()
{
    ofstream file("gara.txt");
    if (file.is_open())
    {
        file.clear();
        //file.close();
    }
    
    //ofstream fout("gara.txt");
    
    for(int i=0; i<5; i++)
    {
        file<<endl<<vet_snow[i].matricola<<" "<<vet_snow[i].cognome;
    }
    
    file.close();
}


void file_agg()
{
    ofstream fout("gara.txt");
    
    srand(time(NULL));
    int x1=0,y1=0,x=0,y=0,dist1=0,dist=0,giri=0;
    
    for(int i=0; i<5; i++)
    {
        fout<<endl<<vet_snow[i].matricola<<" "<<vet_snow[i].cognome<<" ";
        giri=rand()%5+25;
        for(int j=0; j<giri; j++)
        {
            vet_snow[i].x[j]=x;
            fout<<vet_snow[i].x[j]<<" ";
            vet_snow[i].y[j]=y;
            fout<<vet_snow[i].y[j]<<" ";
            x=rand()%101;
            y=rand()%101;
            dist1=sqrt((pow(x-x1,2))+(pow(y-y1,2)));
            x1=x;
            y1=y;
            dist=dist+dist1;
        }
        
        vet_snow[i].kmt=dist;
        fout<<vet_snow[i].kmt;
        
    }
    
    leggi_agg(giri);
    
    fout.close();
}

void podio()
{
    int primo=vet_snow[0].kmt;
    int secondo=0;
    int terzo=0;
    int a=0,b=0,c=0;
    
    for(int i=0; i<5; i++)
    {
        if(vet_snow[i].kmt>primo)
        {
            primo=vet_snow[i].kmt;
            a=i;
        }
    }
    
    cout<<endl<<"Primo: "<<vet_snow[a].matricola<<" "<<vet_snow[a].cognome<<" Distanza percorsa: "<<vet_snow[a].kmt;
    
    for(int i=0; i<5; i++)
    {
        if(vet_snow[i].kmt<primo)
        {
            secondo=vet_snow[i].kmt;
            for(int i=0; i<5; i++)
            {
                if(vet_snow[i].kmt>secondo && vet_snow[i].kmt<primo)
                {
                    secondo=vet_snow[i].kmt;
                    b=i;
                }
            }
            
        }
    }
    
    cout<<endl<<"Secondo: "<<vet_snow[b].matricola<<" "<<vet_snow[b].cognome<<" Distanza percorsa: "<<vet_snow[b].kmt;
    
    for(int i=0; i<5; i++)
    {
        if(vet_snow[i].kmt<secondo)
        {
            terzo=vet_snow[i].kmt;
            for(int i=0; i<5; i++)
            {
                if(vet_snow[i].kmt>terzo && vet_snow[i].kmt<secondo)
                {
                    terzo=vet_snow[i].kmt;
                    c=i;
                }
            }
            
        }
    }
    
    cout<<endl<<"Terzo: "<<vet_snow[c].matricola<<" "<<vet_snow[c].cognome<<" Distanza percorsa: "<<vet_snow[c].kmt;
    
    pulisci();
    
}

int main()
{
    
     
    
    int scelta;
        do
        {
            cout<<endl<<"===== MENU ====="<<endl;
            cout<<"1) Visualizza partecipanti"<<endl;
            cout<<"2) Genera gara"<<endl;
            cout<<"3) Visualizza il podio"<<endl;
            cout<<"4)USCITA "<<endl;
            cout<<"Inserire una scelta: "<<endl;
            cin>>scelta;
            switch(scelta){
                case 1:
                        leggi();
                        break;
                case 2:
                        file_agg();
                        break;
                case 3:
                        podio();
                        break;
            }

        }while(scelta!=4);
        

    return 0;
}
