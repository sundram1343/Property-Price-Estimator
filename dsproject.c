#include<iostream>
#include<string>
#include<vector>
#include<unistd.h>
using namespace std;
class Node
{
    public:
    int val;
    Node*next;
    Node(int data)
    {
        val=data;
        next=NULL;
    }
};
class ListNode
{
    Node*head;
    Node*tail;
    public:
    ListNode()
    {
        head=tail=NULL;
    }
    void push(int val)
    {
        Node*newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=head;
        }
        else{   
            tail->next=newNode;
            newNode->next=NULL;
        }
    }
    Node*gethead()
    {
        return head;
    }
};
class PropertyData{
    private:
    int rooms;
    int area;
    public:
    void read(int r,int a){
        rooms=r;
        area=a;
    }
    int getarea()
    {
        int a=0;
        while (a<=0)
        {
            cout<<"\nEnter the area of the property in square feet ";
            cin>>a;
            if(a<=0)
            {
                cout<<"\nEnter a vaild value.Please try again ";
            }
        }   
        return a;
    }
    int getrooms()
    {
        int r=0;
        while(r<=0)
        {
            cout<<"\nEnter the no of rooms ";
            cin>>r;
            if(r<=0)
            {
                cout<<"\nEnter a vaild value.Please try again ";
            }
        }
        return r;
    }
    void getdata(vector<int>&data)
    {
        area=getarea();
        data.push_back(area);
        sleep(1);
        rooms=getrooms();
        data.push_back(rooms);
        sleep(1);
    }
};
int Price_Calculator(Node*head,vector<int>data){
    Node*ptr=head;
    int total_price=0;
    total_price+=(ptr->val)*data[0];
    ptr=ptr->next;
    total_price+=(ptr->val)*data[1];
    return total_price;
}
bool Check(string cityname1,string cityname2)
{
    if(cityname1.size()!=cityname2.size())
    {
        return false;
    }
    for(int i=0;i<cityname1.size();i++)
    {
        if(tolower(cityname1[i])!=tolower(cityname2[i]))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string cityname;
    cout<<"\nWelcome to property price estimator ";
    cout<<"\n";
    sleep(1);
    for(int i=0;i<60;i++)
    {
        cout<<"-";
    }
    cout<<"\nRightnow only four cities are available\nThe cities are as follows:-\n1.Delhi\n2.Mumbai\n3.Chennai\n4.Bengaluru";
    sleep(2);
    string Choice;
    do
    {
        vector<int>data;
        PropertyData d;
        d.getdata(data);
        int valid_city=0;
        while(valid_city!=1)
        {
            cout<<"\nEnter the City name from the above  mentioned cities ";
            cin>>cityname;
            sleep(1);
            if(Check(cityname,"Delhi"))
            {
                cout<<"\nEntered city name is Delhi ";
                ListNode Delhi;
                Delhi.push(10000);
                Delhi.push(1000);
                int total_price=Price_Calculator(Delhi.gethead(),data);
                int error =total_price*0.05;
                int estimated_price=total_price-error;
                sleep(1);
                cout<<"\nThe estimated price of the property wih the data is ₹"<<estimated_price<<" - "<<"₹"<<total_price;
                valid_city=1;
            }
            else if(Check(cityname,"Mumbai"))
            {
                cout<<"\nEntered city name is Mumbai ";
                ListNode Mumbai;
                Mumbai.push(22000);
                Mumbai.push(2200);
                int total_price=Price_Calculator(Mumbai.gethead(),data);
                int error =total_price*0.05;
                int estimated_price=total_price-error;
                sleep(1);
                cout<<"\nThe estimated price of the property wih the data is ₹"<<estimated_price<<" - "<<"₹"<<total_price;
                valid_city=1;
            }
            else if(Check(cityname,"Chennai"))
            {
                cout<<"\nEntered city name is Chennai ";
                ListNode Chennai;
                Chennai.push(8543);
                Chennai.push(855);
                int total_price=Price_Calculator(Chennai.gethead(),data);
                int error =total_price*0.05;
                int estimated_price=total_price-error;
                sleep(1);
                cout<<"\nThe estimated price of the property wih the data is ₹"<<estimated_price<<" - "<<"₹"<<total_price;
                valid_city=1;
            }
            else if(Check(cityname,"Bengaluru"))
            {
                cout<<"\nEntered city name is Bengaluru ";
                ListNode Bengaluru;
                Bengaluru.push(22000);
                Bengaluru.push(2200);
                int total_price=Price_Calculator(Bengaluru.gethead(),data);
                int error =total_price*0.05;
                int estimated_price=total_price-error;
                sleep(1);
                cout<<"\nThe estimated price of the property wih the data is ₹"<<estimated_price<<" - "<<"₹"<<total_price;
                valid_city=1;
            }
            else
            {
                cout<<"\nPlease Enter a Vaild Name. Try again";
                continue;
            }
            int internalCondition=0;
            while(internalCondition!=1)
            {
                cout<<"\nDo you want continue (y/n) ";
                cin>>Choice;
                if(Check(Choice,"y")||Check(Choice,"Yes"))
                {
                    string internalCheck;
                    cout<<"\nDo you want to continue with same data and only want to change the city (y/n) ";
                    cin>>internalCheck;
                    if(Check(internalCheck,"y")||Check(internalCheck,"Yes"))
                    {
                        valid_city=0;
                    }
                    internalCondition=1;
                }
                else if(Check(Choice,"No")||Check(Choice,"n"))
                {
                    cout<<"\nExiting";
                    for(int i=0;i<5;i++)
                    {
                        cout<<".";
                        sleep(1);
                    }
                    internalCondition=1;
                }
                else{
                    cout<<"\nEnter a vaild answer ";
                }
            }
        }
    }while (Check(Choice,"y") || Check(Choice,"Yes"));
    return 0;
}
