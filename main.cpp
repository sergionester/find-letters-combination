#include <iostream>
#include <string>
#include <fstream>
#include <QCoreApplication>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{   int n = 0;
    QCoreApplication a(argc, argv);
    string textin = "";
    string buff[2048];
    string slog[2048];
    int letter=0;
    QString path_in = QCoreApplication::applicationDirPath() + "/example.txt";
    QString path_out= QCoreApplication::applicationDirPath() + "/example_out.txt";
    ifstream in(path_in.toLatin1().data());
    ofstream out(path_out.toLatin1().data());
    if (!in.fail())
      {
        while (!in.eof())
        {
         textin += in.get();
            if (in.eof()) break;
            if (textin != " ")
                        {
                            if ((textin == ".") || (textin == ",") || (textin == "?") || (textin == "!") || (textin == ":"))
                               {
                               buff[n] = "";
                               n++;
                               }
                            else if (textin == "\n")
                               { }
                            else
                               {
                                buff[n] = textin;
                                textin = "";
                                letter++;
                                n++;
                               }
                        }
                        else
                        {
                            buff[n] = " ";
                            n++;
                            textin = "";
                        }
        }
       in.close();
    }
     else cout<<"error open";

        for(int i=0;i<n-1;i++)
            {
                if (buff[i+1]==" ") i++;
                     else slog[i]=buff[i]+buff[i+1];

                //cout<<i<<"\t"<<slog[i]<<endl;
            }

    int m=0; // переменная для цикла перебора одинаковых буквосочетаний
    int l = 2;//если встретили одиноковое буквосочетание, значит их уже 2
    string counter_slog[1024];//сюда пишем слоги
    int counter[512];//сюда пишем кол-во каждого буквосочетания
            for (unsigned int i = 0; i < n-1; i++) //n = 11 //i<n-1
            {
                l=2;//новый счетчик
                for(m=0;m<n;m++)
                {
                    if ((slog[m] == slog[i])&&(m!=i)&&(slog[m]!="") &&(slog[i]!="")  ) //нельзя сравнивать само с собой
                    {
                    counter_slog[i]=slog[m]; //пишем повторяющийся слог
                    counter[i]=l; // считаем кол-во повторений
                    l++;
                    }
                }

            }
    cout<<endl;
            //найдем максимальное кол-во повторений и по индексу найдем этот слог
    int a_max=0;
    string s = "";
    for (int i = 0; i<n-1; i++)
    {
        if (counter[i]>a_max)
           {
            a_max = counter[i];
            s = counter_slog[i];
           }
    }
        cout<<a_max<<" "<<s<<endl;

}
