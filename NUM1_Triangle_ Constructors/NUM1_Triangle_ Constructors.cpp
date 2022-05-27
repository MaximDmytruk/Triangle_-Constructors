/*1. Class - тип трикутника
Написати клас Triangle (трикутник), що містить поля координати вершин трикутника цілого типу x1,y1,x2,y2,x3,y3.
Реалізувати конструктори:
по замовчуванню, що обнулює координати вершин трикутника;
з парамитрами, що отримує координати цілого типу вершин трикутника і ініціаліхує їх.
Реалізувати методи які перевітяють тип трикутника.
Реалізуйте меню для користувача: 
1 - Введення даних
2 - Виведення даних
0 - Вихід*/

/*2.Реалізувати методи :
void Out() - виводить координати трикутника через пропуск;
double area() - повертає площу трикутника;
double perimeter() - повертає периметр трикутника;
double inscribedRadius() - повертає радіус вписаного кола;
double describedRadius() - повертає радіус описаного кола;*/

#include <iostream>
#include <math.h>
using namespace std;

class Triangle {
private:
    int x1; int y1; int x2; int y2; int x3; int y3;
    double AB; double BC; double AC;
    double p; //периметр
    double S;//Площа
    double radIn;//Радіус вписаного кола в трикутник 
    double radOut;//Радіус описаного кола в трикутник 
public:
    Triangle() { x1 = 0; y1 = 0; x2 = 0;  y2 = 0; x3 = 0; y3 = 0;}    //конструктор по замовчуванню який обнулює координати 
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {         //конструктор який приймає координати напряму
        this->x1=x1; this->y1= y1; this->x2 =x2; this->y2=x2 ; this->x3=x3; this->y3=y3;
    }
    void SetPoints();       //метод для введеня координат трикутника 
    void GetPoint();        //метод виведення координат трикутника 
    void Side();            //метод визначення довжини сторін
    void GetSide();         //метод вивдення довжин сторін 
    bool YorNTri();         //метод перевірки чи можна утоврити трикутник 
    double perimeter();     //метод визначення периметру трикутника 
    double Area();          //метод визначення площі трикутника
    double TypeTriAngel();  //метод взначення типу трикутника по кутам
    double TypeTriSide();   //метод визначення типу трикутника по сторонам
    double inscribedRadius();//метод визначення радіусу кола вписаного в трикутника 
    double describedRadius();//метод визначення радіусу кола описаного навколо трикутника 
    void printMenu();
    ~Triangle(){}   
};

int main()
{

    int player; //для вибору меню.

    Triangle tria;      //створюємо клас
    cout << "\t--Triangle--" << endl;
    tria.printMenu();   //виводимо меню
    while (true)    //бесукінечний цикл 
    {
        cin >> player;      //вибір дії від користувача 

        if (player == 1) {      //далі варінти дій в залежності від вибуору коричтувача 
            tria.SetPoints();       //вводимо точки 
            if (tria.YorNTri()==true) { cout << "Let's go" << endl; }   //перевірка чи можливо створити трикутник 
            else cout << "This is not triangle, please enter '1' and set new coordinates" << endl;
            
        }
        if (player == 2) { tria.GetPoint(); }       //вивести точки 
        if (player == 3) { tria.GetSide(); }        //вивести довжину сторін 
        if (player == 4) { cout << "Perimetr = " << tria.perimeter(); } //периметр 
        if (player == 5) { cout << "Area = " << tria.Area(); }  //площа 
        if (player == 6) {  //тип трикутника відносно углів 
            cout << "Type triangle relative to the angle - ";
            if (tria.TypeTriAngel() == 1) { cout << "Right " << endl; }
            if (tria.TypeTriAngel() == 2) { cout << "Acute " << endl; }
            if (tria.TypeTriAngel() == 3) { cout << "Obtuse" << endl; }
        }
        if (player == 7) {  //тип трикутника відносно сторін 
            cout << "Type triangle relative to the sides - ";
            if (tria.TypeTriSide() == 4) { cout << "Equilateral" << endl; }
            if (tria.TypeTriSide() == 5) { cout << "Isosceles" << endl; }
            if (tria.TypeTriSide() == 6) { cout << "Scalene" << endl; }
        }
        if (player == 8) { cout << "The radius of a circle inscribed in a triangle = " << tria.inscribedRadius(); } //радіуси кола вписаного 
        if (player == 9) { cout << "The radius of a circle described in a triangle = " << tria.describedRadius(); } //радіус описаного 
        if (player == 10)   //все і одразу 
        {
            tria.GetPoint();
            tria.GetSide();
            cout << "Perimetr = " << tria.perimeter()<<endl;
            cout << "Area = " << tria.Area() << endl;
            cout << "Type triangle relative to the angle - ";
            if (tria.TypeTriAngel() == 1) { cout << "Right " << endl; }
            if (tria.TypeTriAngel() == 2) { cout << "Acute " << endl; }
            if (tria.TypeTriAngel() == 3) { cout << "Obtuse" << endl; }
            cout << "Type triangle relative to the sides - ";
            if (tria.TypeTriSide() == 4) { cout << "Equilateral" << endl; }
            if (tria.TypeTriSide() == 5) { cout << "Isosceles" << endl; }
            if (tria.TypeTriSide() == 6) { cout << "Scalene" << endl; }
            cout << "The radius of a circle inscribed in a triangle = " << tria.inscribedRadius() << endl;
            cout << "The radius of a circle described in a triangle = " << tria.describedRadius() << endl;
        }
        if (player == 0)break;      //вихід
    }

}

void Triangle:: SetPoints() {
    cout << "Enter coordinates of points x1,y1 = ";
    cin >> this->x1 >> this->y1;
    cout << "Enter coordinates of points x2,y2 = ";
    cin >> this->x2 >> this->y2;
    cout << "Enter coordinates of points x3,y3 = ";
    cin >> this->x3 >> this->y3;
    Side(); //одразу вираховуємо довжину сторін.
}
void Triangle::GetPoint() {
    cout << "x1,y1 = " << x1 << " " << y1 << endl;
    cout << "x2,y2 = " << x2 << " " << y2 << endl;
    cout << "x3,y3 = " << x3 << " " << y3 << endl;
}
void Triangle:: Side() {
    this->AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    this->BC = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    this->AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
};

void Triangle::GetSide() {
    cout << "Side AB = " << AB << endl;
    cout << "Side BC = " << BC << endl;
    cout << "Side AC = " << AC << endl;
}

bool Triangle::YorNTri() {
    if (AB + BC > AC && BC + AC > AB && AC + AB > BC)
    {
        return true;
    }
    else false;
    
}

double Triangle::perimeter() { this->p = AB + BC + AC; return this->p; } //Метод для розрахунку периметра трикутника 

double Triangle::Area() {                               //метод для ррзрахунку площі трикутника 
    int pp = perimeter() / 2;
    this->S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
    return S;
}

double Triangle::TypeTriAngel() {     //тип трикутника відносно кутів.
    if (AB > BC && AB > AC) {
        if (AB * AB == BC * BC + AC * AC) { return 1; }//прямокутний  Right
        if (AB * AB < BC * BC + AC * AC) { return 2; }//Гострий Acute
        if (AB * AB > BC * BC + AC * AC) { return 3; }//тупокутний Obtuse
    }
    if (BC > AB && BC > AC) {
        if (AB * AB == BC * BC + AC * AC) { return 1; }//прямокутний 
        if (AB * AB < BC * BC + AC * AC) { return 2; }//гострий
        if (AB * AB > BC * BC + AC * AC) { return 3; }//тупокутний 
    }
    if (AC > AB && AC > BC) {
        if (AB * AB == BC * BC + AC * AC) { return 1; }//прямокутний 
        if (AB * AB < BC * BC + AC * AC) { return 2; }//гострий 
        if (AB * AB > BC * BC + AC * AC) { return 3; }//тупокутний
    }
}
double Triangle::TypeTriSide() {
    if (AB == AC == BC) { return 4; } //рівносторонній  Equilateral Triangle
    if (AB == AC != BC || AB == BC != AC || AC == BC != AB) { return 5; } //рівнобедрений Isosceles triangle
    if (AB != AC != BC) { return 6; }//різносторонній Scalene triangle
}
double Triangle:: inscribedRadius() { this->radIn = 2 * this->S / p; return radIn; }
double Triangle:: describedRadius() { this->radOut = (AB * BC * AC) / (4 * S); return radOut; }
void Triangle::printMenu() {
    cout << "\t-Menu-" << endl;
    cout << " 1 - Set new coordinates." << endl;
    cout << " 2 - Print the coordinates." << endl;
    cout << " 3 - Print the length of the side" << endl;
    cout << " 4 - Perimeter" << endl;
    cout << " 5 - Area" << endl;
    cout << " 6 - Type triangle relative to the angle" << endl;
    cout << " 7 - Type triangle relative to the sides" << endl;
    cout << " 8 - The radius of a circle inscribed in a triangle" << endl;
    cout << " 9 - the radius of a circle described in a triangle" << endl;
    cout << " 10 - All at Once" << endl;
    cout << " 0 - Exit" << endl;
    cout << endl;
}