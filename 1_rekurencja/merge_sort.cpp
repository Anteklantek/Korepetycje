#include<iostream>
using namespace std;
int tab[3]={30,29,28};
void merg(int pocz, int sro ,int kon)
{
    int j=0,k=0,x=0;
    int dlu_lewa=(sro-pocz)+1;
    int lewa[dlu_lewa];
    int dlu_prawa=kon-sro;
    int prawa[dlu_prawa];
    for(int i=pocz;i<=sro;i++)
    {
        lewa[j]=tab[i];
        j++;
    }
    for(int i=sro+1;i<=kon;i++)
    {
        prawa[k]=tab[i];
        k++;
    }
    j=0;
    k=0;
    while(dlu_prawa>j&&dlu_lewa>k)
    {
        if(prawa[j]<=lewa[k])
        {
            tab[x]=prawa[j];
            x++;
            j++;
        }
        else
        {
            tab[x]=lewa[k];
            x++;
            k++;
        }
    }
    while(dlu_prawa>j)
    {
        tab[x]=prawa[j];
        j++;
        x++;
    }
    while(dlu_lewa>k)
    {
        tab[x]=lewa[k];
        k++;
        x++;

    }
}
void mergs(int pocz, int kon)
{
    int sro=(pocz+kon)/2;
    if(pocz<kon){
        mergs(pocz,sro);
        mergs(sro+1,kon);
        merg(pocz,sro,kon);
    }


}
int main()
{
    mergs(0,2);
    for(int i=0;i<3;i++)
    {
        cout<<tab[i]<<" ";
    }
}
