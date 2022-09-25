
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Car
{
private:
    string Car_Brand;
    string Car_Type;
    string  Car_Plate;
    int Speed;
    int Year_Model;
public:
    Car()
    {
        Car_Brand = "";
        Car_Type = "";
        Car_Plate = "";
        Speed = 0;
        Year_Model = 0;
    }
    Car(string Car_Brand1, int Max_Speed2, int Year_Model3,string Car_Type4, string  Car_Plate5)
    {
        Car_Brand = Car_Brand1;
        Speed = Max_Speed2;
        Year_Model = Year_Model3;
        setCartype(Car_Type4);
        setCarplate(Car_Plate5);
    }
    void setCarbrand(string Car_Brand0)
    {
        Car_Brand = Car_Brand0;
    }
    void setCartype(string Car_Type0)
    {   
        while ((Car_Type0 != "Bus") && (Car_Type0 != "Private") && (Car_Type0 != "Motorcycle") && (Car_Type0 != "Truck"))
        {
            cout << "Car type is invalid, please enter again the car type: ";
            cin >> Car_Type0;}
        Car_Type = Car_Type0;
    }
    
    void setCarplate(string  Car_Plate0)
    {
        while (Car_Plate0.length() != 6)
        {
            cout << "Car plate in invalid, please enter again the car plate: " << endl;
            cin >> Car_Plate0;
        }
        Car_Plate = Car_Plate0;
    }
    void setSpeed(int Speed0)
    {
        Speed = Speed0;
    }
    void setYearmodel(int Year_Model0)
    {
        Year_Model = Year_Model0;
    }
    string getCarBrand()
    {
        return Car_Brand;
    }
    string getCartype()
    {
        return Car_Type;
    }
    string getCarplate()
    {
        return Car_Plate;
    }
    int getSpeed()
    {
        return Speed;
    }
    int getYearmodel()
    {
        return Year_Model;
    }

};


class Road
{

public:
    Road()
    {
        Road_Type = ' ';
        Speed_Limit = 0;
        CountA = 0;
        CountB = 0;
        CountC = 0;
    }

    Road(char Road_Type1, int Speed_Limit1)
    {
        setRoadtype (Road_Type1);
        Speed_Limit = Speed_Limit1;
        CountA = 0;
        CountB = 0;
        CountC = 0;
    }

    bool Radar(int car_speed, char Road_Type)
    {
        if ((Road_Type == 'A') || (Road_Type == 'B') || (Road_Type == 'C'))
        {
            if (car_speed > Speed_Limit) {
                return true;
                
            }
            
        }
         return false;
    }


    void allow(string Car_type)
    {
        if ((Car_type == "Private" )|| (Car_type =="Motorcycle"))
        {
            cout << "Road A and B are allowed, but not C" << endl;
            CountA++ ;
            CountB++ ;
        }
        else if (Car_type == "Truck")
        {
            cout << "Road C and B are allowed"<< endl;
             CountC++;
             CountB++;
        }
       else  
        {
            cout << "Road B is allowed, but not A and C"<< endl;
            CountB++;
        }
        
    }

    int getage(int Yearmodel)   
    {   
        int currentage = 2022 - Yearmodel;
        return currentage;
    }
    void setRoadtype(char Road_typeT)
    {
        while ((Road_typeT != 'A') && (Road_typeT != 'B') && (Road_typeT != 'C'))
        {
            cout << "Road is invalid, please enter a valid Road (A, B, or C): "<< endl;
            cin >> Road_typeT;
        }
        Road_Type = Road_typeT;
    }
    void setSpeedlimit(int Speed_limitL)
    {
        Speed_Limit = Speed_limitL;
    }
    void setcountA(int CountAa)
    {
        CountA = CountAa;
    }
    void setCountB(int CountBb)
    {
        CountB = CountBb;
    }
    void setCountC(int CountCc)
    {
        CountC = CountCc;
    }
    char getRoadtype()
    {
        return Road_Type;
    }
    int getSpeedlimit()
    {
        return Speed_Limit;
    }
    int getCountA()
    {
        return CountA;
    }
    int getCountB()
    {
        return CountB;
    }
    int getCountC()
    {
        return CountC;
    }
private:
    char Road_Type;
    int Speed_Limit;
     int CountA;
      int CountB;
     int CountC;

};

int main()
{

    double efficiency;
    queue<Car> Queueq;
    Road A ('A', 90),B ('B', 110),C('C', 70);


    
    Queueq.push(Car("Mercedes", 150, 1993, "Bus", "hgd148"));
    Queueq.push(Car ("Chevrolet", 140, 2018, "Private", "hsh390"));
    Queueq.push(Car ("Toyota", 60, 2013, "Truck", "hju990"));
    Queueq.push(Car ("Suzuky", 160, 2020, "Motorcycle", "yej837"));
    Queueq.push(Car ("BMW", 100, 2016, "Private", "jol265"));
    Queueq.push(Car ("Kia", 70, 2015, "Private", "hsl265"));
    Queueq.push(Car ("Jelly", 100, 2015, "Truck", "ueh921"));
    Queueq.push(Car ("Peugot", 180, 2019, "Motorcycle", "abl630"));



    for (int i = 0; i < 8; i++)
    {   
        A.allow(Queueq.front (). getCartype () );
        cout << endl;
        
        cout << "The current age of car "<< i+1 << " is " << A.getage( Queueq.front().getYearmodel() ) << endl;
        cout << endl;
        if (A.Radar(Queueq.front ().getSpeed(), A.getRoadtype())) // car was caught by the radar
        {  
            cout << "Car " << i + 1 << " was caught on the radar\n" << "Car details:\n"
                << "car brand: " << Queueq.front ().getCarBrand() << endl; // display the rest of car info
            cout << "car type: " << Queueq.front (). getCartype () << endl;
            cout  << "car plate: " << Queueq.front ().getCarplate() << endl;
            cout << "car speed: " << Queueq.front ().getSpeed() << endl;
            cout << "car year model: "<< Queueq.front ().getYearmodel() << endl;
              cout << endl;

        }
          
         else if (B.Radar(Queueq.front ().getSpeed(), B.getRoadtype())) // car was caught by the radar
        {
            cout << "Car " << i + 1 << " was caught on the radar\n" << "Car details:\n"
                << "car brand: " <<  Queueq.front ().getCarBrand() << endl; // display the rest of car info
            cout << "car type: " << Queueq.front (). getCartype () << endl;
            cout  << "car plate: " << Queueq.front ().getCarplate() << endl;
            cout << "car speed: " << Queueq.front ().getSpeed() << endl;
            cout << "car year model: "<< Queueq.front ().getYearmodel() << endl;
              cout << endl;
        }
        
         else if (C.Radar(Queueq.front ().getSpeed(), C.getRoadtype())) // car was caught by the radar
        {
            cout << "Car " << i + 1 << " was caught on the radar\n" << "Car details:\n"
                << "car brand: " <<  Queueq.front ().getCarBrand() << endl; // display the rest of car info
            cout << "car type: " << Queueq.front (). getCartype () << endl;
            cout  << "car plate: " << Queueq.front ().getCarplate() << endl;
            cout << "car speed: " << Queueq.front ().getSpeed() << endl;
            cout << "car year model: "<< Queueq.front ().getYearmodel() << endl;
              cout << endl;
        }
        Queueq.pop();
        
}
   

int countA = A.getCountA();
int countB = A.getCountB();
int countC = A.getCountC();

cout << "The number of cars passed by Road A is : " <<countA << endl;
cout << "The number of cars passed by Road B is : "<< countB << endl;
cout << "The number of cars passed by Road C is : " <<countC << endl;

   efficiency = (countA * 100 / countB);
            
cout << "The efficiency of Road A: " << endl;
cout <<  efficiency;
cout << "%"<< endl;
efficiency = (countB * 100 / countB);
cout << "The efficiency of Road B: " << endl;
cout <<  efficiency;
cout << "%"<< endl;
efficiency = (countC * 100 / countB);
cout << "The efficiency of Road C: " << endl;
cout <<  efficiency;
cout << "%"<< endl;


    return 0;
}