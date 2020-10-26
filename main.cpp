#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex> //protege el recurso compartido de cout evitando que los dos hilos accedan a la vez
using namespace std;

#define N 10
mutex m; //variable global

void cuentaAtras(string nombre)
{

    for (int contador = N; contador >= 0; contador--)
    {
        m.lock();
        cout << "Cuenta atras" << nombre << ": " << contador << endl;
        cout.flush(); //fuerza a que cout escriba en la pantalla lo que tenga en memoria
        m.unlock();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main(int, char **)
{
    thread t1(cuentaAtras, " prueba1");
    thread t2(cuentaAtras, " prueba2");

    t1.join();
    t2.join();

    //return 0;
}
