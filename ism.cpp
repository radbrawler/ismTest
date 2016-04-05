#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int vehcount,vehdatcount,check,slotcount[100]={0};

class VehicleDatabase
{
    private:
        string registrationNo;
        string driverName;
        string color;
        int slot;
        int mark;

    public:
        string getRegistrationNo()              //!To get Reg No
        {
            return registrationNo;
        }
        string getDriverName()
        {
            return driverName;

        }
        int isMarked()
        {
            return mark;
        }
        void setRegistrationNo(string X)
        {
            registrationNo = X;
        }
        void setDriverName(string X)
        {
            driverName = X;
        }
        void setColor(string X)
        {
            color = X;
        }
        int setSlot()
        {
            int i;
            for(i=0;i<100;i++)
            {
                if(slotcount[i]== 0)
                {
                    slot = i;
                    slotcount[i]=1;
                    check++;
                    return i;
                }
            }
           cout<<"The security personnel first vehicle entered. So not present inside log"<<endl;
           return -1;
        }
        int getSlot()
        {
            return slot;
        }
        int freeSlot(int X)
        {
            slotcount[X]=0;
            check--;
            return 1;
        }
        string getColor()
        {
            return color;
        }
        void entryReq();
        void exitReq();
}vehdat[100];

class Vehicle
{
    private:
        string registrationNo;
        string driverName;
        string color;
        int status;
        int type;   //!0-Normal 1-Police 2-Fire
    public:
        Vehicle()
        {
            status = 0;
        }
        int mark;   //!0-Not marked  1-Marked
        int isStatusIn()
        {
            return status;
        }
        int ifMarked()
        {
            return mark;
        }
        void entryReq();
        int ifUnmarked()
        {
            return !mark;
        }
}veh;

class Guard
{
private:
    int position;  //!Checkpoint Number (0-3)
    string id;
    int attendance;  //!0-Absent 1-Present
    int type;  //!0-Normal  1-Backup
public:
    Guard()
    {
       id = rand()%100000;
       attendance = 1;
       type = 0;
    }

    Guard(int X)
    {
        attendance = 1;
        type = 1;
    }

    void setPositioning(int b)
    {
        position = b;
    }

     int getPositioning()
    {
        return position ;
    }

}guard[10];

int mains()
{
//    guard1 = new Guard(1);
    int choice,mark,choice1,ok,take;
    string pass,input[4];
    string def = "asdf";
    while(choice != 7)
    {   
        cout<<"Choose what is happening?"<<endl<<"1.Vehicle Entry  2.Vehicle Exit  3.Number of vehicles inside  4.Emergency Vehicle  5.Get all normal vehicle details  6.Guard Positioning  7.Close"<<endl;
        cin>>choice;
        if (choice == 1)
        {
            cout<<"Is vehicle marked?"<<endl;
            cin>>veh.mark;
            if(veh.ifMarked())
            {
                int temp1 = vehdat[vehdatcount].setSlot();
                cout<<"Enter registration Number"<<endl;
                cin>>input[0];
                vehdat[temp1].setRegistrationNo(input[0]);

                cout<<"Slot is : "<<temp1<<endl;
            }

            else
            {
                int temp = vehdat[vehdatcount].setSlot();
                cout<<"Enter registration Number"<<endl;
                cin>>input[1];
                vehdat[temp].setRegistrationNo(input[1]);

                cout<<"Enter driver name"<<endl;
                cin>>input[2];
                vehdat[temp].setDriverName(input[2]);

                cout<<"Enter color"<<endl;
                cin>>input[3];
                vehdat[temp].setColor(input[3]);

                cout<<"Slot is : "<<temp<<endl;

            }

            vehdatcount++;
        }

        else if(choice == 2)
        {
            cout<<"Enter slot of car"<<endl;
            cin>>choice1;
            cout<<"Confirm the registration number"<<endl;
            cout<<vehdat[choice1].getRegistrationNo()<<endl<<"1.Yes 0.No"<<endl;
            cin>>ok;
            if(ok==1)
            {
                vehdat[vehdatcount].freeSlot(choice1);
            }
            else continue;
        }

        else if(choice == 3)
            cout<<"Number of vehicles currently inside = "<<check<<endl;


        else if (choice == 4)
            cout<<"Emergency vehicle is entered. Allow free movement of the vehicle."<<endl;

        else if(choice ==5)
        {
            int j;
            for(j=0;j<100;j++)
            {
                if(slotcount[j]!=0)
                {
                    cout<<"Registration number: "<<vehdat[j].getRegistrationNo()<<" Driver Name: "<<vehdat[j].getDriverName()<<" Color: "<<vehdat[j].getColor()<<endl;
                }
            }
        }

        else if(choice == 6)
        {
            int r;
            cout<<"If admin enter password, otherwise enter 'qwer'"<<endl;
            cin>>pass;

            if (pass==def)
            {
                cout<<"To set positions- 1    To get positions - 2"<<endl;
                cin>>take;
                if(take==1)
                {
                    cout<<"Enter positions of guard from positions 0-3 and 3 is back up "<<endl;
                    for(int k=0;k<10;k++)
                    {
                            cout<<"Guard  "<<k+1<<" has position : "<<endl;
                            cin>>r;
                            if(r>=0 && r<4)
                                {
                                    guard[k].setPositioning(r);

                                }
                            else
                            {
                                cout<<"Improper position entry. Enter again"<<endl;
                                k--;
                            }
                    }
                }

                else if(take == 2)
                {
                    int v;
                    for(v=0;v<10;v++)
                    {
                        cout<<"Position of guard "<<v<<"is : "<<guard[v].getPositioning()<<endl;
                    }
                }

            }

        }

    }
    return 0;
}


