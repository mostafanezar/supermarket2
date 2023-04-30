#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
    class supermarket{
        public:
        int id;
        double price;
        int expirydate;
        char productname[20];
void writerecord()
{
     ofstream out;
    out.open("supermarket.txt",ios::app);
    if(out.is_open()){
   supermarket s;
    int j;
    do{
    cout<<"\t\tEnter id\n\n"<<endl;
    cin>>s.id;
     cout<<"\t\tEnter productname\n\n"<<endl;
    cin>>s.productname;
     cout<<"\t\tEnter price\n\n"<<endl;
    cin>>s.price;
    cout<<"\t\tEnter expirydate\n\n"<<endl;
    cin>>s.expirydate;
    out.write((char*)&s,sizeof(s));
    cout<<"\t\t\t Enter 0 to exit :: Enter 1 to add\n\n";
    cin>>j;
    }
    while(j==1);
    out.close();
    }else{
        cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
     }
  }
  void readrecord()
  {
      supermarket s;
      ifstream in("supermarket.txt",ios::in);
      if(in.is_open())
      {
          cout<<"\tid\tname\tprice\texpirydate\n\n"<<endl;
          while(!in.eof()){
            in.read((char*)&s,sizeof(s));
            cout<<"\t"<<s.id<<"\t"<<s.productname<<"\t"<<s.price<<"\t"<<s.expirydate<<endl;
          }
          in.close();

      }
          else{
        cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
     }
      }
void searchitem()
{
    char str[20];
    cout<<"\t\t\tenter productname to search\n\n";
    cin>>str;

      supermarket s;
      ifstream in("supermarket.txt");
      if(in.is_open())
      {
          while(!in.eof()){
            in.read((char*)&s,sizeof(s));
            if(strcmp(s.productname,str)==0){
                cout<<"\tid\t\tname\t\tprice\t\texpirydate\n\n"<<endl;
                cout<<"\t"<<s.id<<"\t\t"<<s.productname<<"\t\t"<<s.price<<"\t\t"<<s.expirydate<<"\n\n\n";
            break;
          }
          }
          in.close();
          if(strcmp(s.productname,str)!=0)
            cout<<"not foundddd"<<endl;

      }
          else{
            cout<<"\t\t\tcannot open\n\n"<<endl;
          }

}
void delrcord()
{
    ifstream in("supermarket.txt",ios::in);
    ofstream out("temp.txt",ios::out);
    if(in.is_open())
      {
          supermarket s;
          char str[20];
          cout<<"delete"<<endl;
          cin>>str;
          while(in.read((char*)&s,sizeof(s)))
            {
                if(strcmp(str,s.productname)!=0)
                {
                    out.write((char*)&s,sizeof(s));
                }
                in.close();
                out.close();
                remove("supermarket.txt");
                rename("temp.txt","supermarket.txt");

            }
            readrecord();
      }
}
void filelength()
{
fstream y("supermarket.txt",ios::in);
    if(y.is_open())
    {
        y.seekg(0,ios::end);
        cout<<"file length is "<<y.tellg();

    }
    y.close();

}
void copyfile()
{
    char ch;
    fstream in("supermarket.txt",ios::in);
    fstream out("supermarket2.txt",ios::out);
    if(in.is_open())
    {
        while(in.get(ch))
            out.put(ch);
        in.close();
        out.close();
    }

}
void streamstate()
{
    fstream in("supermarket.txt",ios::in);
    cout<<in.fail()<<endl;
    cout<<in.eof()<<endl;
    cout<<in.good()<<endl;
    char q;
    in.get(q);
    cout<<in.fail()<<endl;
    cout<<in.eof()<<endl;
    cout<<in.good()<<endl;
    in.clear();
    cout<<in.fail()<<endl;
    cout<<in.eof()<<endl;
    cout<<in.good()<<endl;
}
void update()
{
    supermarket s;
    fstream f("supermarket.txt",ios::in | ios::out);
    if(f.is_open()){
    char str[20];
    cout<<"enter product name to update"<<endl;
    cin>>str;
    bool found = false;
    while(!f.eof())
    {
        f.read((char*)&s,sizeof(s));
        if(strcmp(str,s.productname)==0)
        {
            cout<<"enter new name to update"<<str<<" "<<endl;
            cin>>s.productname;
            int curpos = f.tellg();
            int supermarketsize = sizeof(s);
            f.seekp(curpos-supermarketsize,ios::beg);
            f.write((char*)&s,sizeof(s));
            found = true;
            break;
        }
    }
    f.close();
    if(!found)
        cout<<"product not exist"<<endl;

}
}
   };
int main()
{
  supermarket x;
    int y;
    do{
     cout<<"\n\t\t===============SuperMarket================\n\n"<<endl;
     cout<<"\t\t\tMAIN MENU\n\n"<<endl;
     cout<<"\t\t\t 1-Show all items\n\n"<<endl;
     cout<<"\t\t\t 2-Add new item\n\n"<<endl;
     cout<<"\t\t\t 3-Search for item\n\n"<<endl;
     cout<<"\t\t\t 4-Delete item\n\n"<<endl;
     cout<<"\t\t\t 5-Copy file\n\n"<<endl;
     cout<<"\t\t\t 6-File length\n\n"<<endl;
     cout<<"\t\t\t 7-Streamstste\n\n"<<endl;
     cout<<"\t\t\t 9-Update record\n\n"<<endl;
     cout<<"\t\t\t 8-exit\n\n"<<endl;
     cin>>y;
    switch(y){
           case 1:
           x.readrecord();
           break;
           case 2:
           x.writerecord();
           break;
           case 3:
           x.searchitem();
           break;
           case 8:
           cout<<"$$$$$$$$$$$$$$$$$$$ EXIT $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
           break;
           case 4:
           x.readrecord();
           x.delrcord();
           cout<<"after deletion"<<endl;
           x.readrecord();
           break;
           case 5:
           x.copyfile();
           break;
           case 6:
           x.filelength();
           break;
           case 7:
           x.streamstate();
           break;
           case 9:
           x.readrecord();
           x.update();
           x.readrecord();
           break;
        default:
        cout<<"\t\t\t!!!!!!error!!!!!!!"<<endl;
        exit(0);
    }
    }while(y!=8);

    return 0;
//hi
}
