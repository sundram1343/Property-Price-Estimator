#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include <unistd.h>// for implementing delay
void printestimator(int estimated_price,int total_price)  //It prints the estimated price and total price
{
    printf("\nThe estimated price is ");
    printf("\n₹%d-₹%d",estimated_price,total_price);
}
int getarea()                                             //It takes the input of the area from the user
{
    int area;
    printf("\nEnter the area of property in square feet ");
    scanf("%d",&area);
    while(getchar() != '\n');
    return area;
}
int getrooms()                                           //It takes the input of no of rooms from the user
{
    int rooms;
    printf("\nEnter no of rooms ");
    scanf("%d",&rooms);
    while(getchar() != '\n');
    return rooms;
}
int estimator(int total_price)                        //It caluacte the 5% error of the price calculator making the range of property
{
    int estimate=total_price*0.05;
    return total_price-estimate;
}
int pricecalculator(int price_per_squarefeet,int price_per_room,int area_property,int no_room){ //It calucates the price    
    int total_price;
    total_price=area_property*price_per_squarefeet;
    total_price+=price_per_room*no_room;
    return total_price;
}
bool Check(char cityname1[100],char cityname2[100])    //It checks the input command matches the desired one
{
    if(strlen(cityname1)!=strlen(cityname2))
    {
        return false;
    }
    int n=strlen(cityname1);
    for(int i=0;i<n;i++)
    {
        if(tolower(cityname1[i])!=tolower(cityname2[i]))
        {
            return false;
        }
    }
    return true;
}
int main()                    //Main function of the program
{
    char cityname[100];
    printf("\nWelcome to property price estimator\n");
    sleep(1);
    for(int i=0;i<40;i++)
    {
        printf("-");
    }
    printf("\nRightnow only four cities are available:-\nThe cities are as follows\n1.Delhi\n2.Mumbai\n3.Chennai\n4.Bengaluru");
    sleep(2);
    char choice[50]="0";
    do
    {
        int city_valid=0;
        while(city_valid!=1)
        {
            printf("\nEnter the city name from the above mentioned cities ");
            fgets(cityname,sizeof(cityname),stdin);
            cityname[strcspn(cityname,"\n")]='\0';
            int no_room;
            if(Check(cityname,"Delhi"))
            {
                printf("\nEnterd city name is Delhi ");
                sleep(1);
                no_room=getrooms();
                sleep(1);
                int area_property=getarea();
                sleep(1);
                int price_per_squarefoot=10000;
                int price_per_room=1000;
                int total_price=pricecalculator(price_per_squarefoot,price_per_room,area_property,no_room);
                int estimated_price=estimator(total_price);
                printestimator(estimated_price,total_price);
                city_valid=1;
            }
            else if(Check(cityname,"Mumbai"))
            {
                printf("\nEnterd city name is Mumbai ");
                sleep(1);
                no_room=getrooms();
                sleep(1);
                int area_property=getarea();
                sleep(1);
                int price_per_squarefoot=22000;
                int price_per_room=2200;
                int total_price=pricecalculator(price_per_squarefoot,price_per_room,area_property,no_room);
                int estimated_price=estimator(total_price);
                printestimator(estimated_price,total_price);
                city_valid=1;
            }
            else if(Check(cityname,"Chennai"))
            {
                printf("\nEnterd city name is Chennai ");
                sleep(1);
                no_room=getrooms();
                sleep(1);
                int area_property=getarea();
                sleep(1);
                int price_per_squarefoot=8543;
                int price_per_room=855;
                int total_price=pricecalculator(price_per_squarefoot,price_per_room,area_property,no_room);
                int estimated_price=estimator(total_price);
                printestimator(estimated_price,total_price);
                city_valid=1;
            }
            else if(Check(cityname,"Bengaluru"))
            {
                printf("\nEnterd city name is Bengluru ");
                sleep(1);
                no_room=getrooms();
                sleep(1);
                int area_property=getarea();
                sleep(1);
                int price_per_squarefoot=15200;
                int price_per_room=1520;
                int total_price=pricecalculator(price_per_squarefoot,price_per_room,area_property,no_room);
                int estimated_price=estimator(total_price);
                printestimator(estimated_price,total_price);
                city_valid=1;
            }
            else 
            {
                printf("\nEnterd city name is %s ",cityname);
                printf("\nEntered Name is wrong.\nPlease recheck and enter again");
            }
        }    
        printf("\nDo you want to continue(y/n) ");
        fgets(choice,sizeof(choice),stdin);
        choice[strcspn(choice,"\n")]='\0';
        if(Check(choice,"N"))
        {
            printf("Exiting");
            for(int i=0;i<5;i++)
            {
                printf(".");
            }
        }   
    }while(!Check(choice,"N"));
    return 0;
}
