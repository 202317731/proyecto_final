#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
using namespace System;
#define s 10
#define l 30
#define r 30

struct libro
{
	int code;
	string name;
	string gen;
	int cost;
};

struct sede
{
	int code;
	string dis;
};

struct reservas
{
	int DNI;
    int code;
	int codesede;
    string sede;
    string gen;
	int dia;
	int mes;
	int hora;
    int anio;
    int multa;
    int mesd;
    int diad;
    int aniod;
    int horad;
};


void imprimir_inicio()
{
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "                                                " << endl;
    cout << "                     11                         " << endl;
    cout << "                    111                         " << endl;
    cout << "           11      1111          11             " << endl;
    cout << "          11      111111          11            " << endl;
    cout << "         111      11111111         11           " << endl;
    cout << "         111       11111111        111          " << endl;
    cout << "        1111        11111111       111          " << endl;
    cout << "        1111         1111111      1111          " << endl;
    cout << "        11111         11111      11111          " << endl;
    cout << "         111111         111    1111111          " << endl;
    cout << "          11111111      11   11111111           " << endl;
    cout << "           1111111111111111111111111            " << endl;
    cout << "             111111111111111111111              " << endl;
    cout << "               1111111111111111                 " << endl;
    cout << "                  11111111111                   " << endl;
    cout << "                                                " << endl;
    cout << "                                                " << endl;
    Console::ForegroundColor = ConsoleColor::Cyan;
    cout << "Creditos: " << endl;
    cout << "- Carrasco Tuiro, Molly Laydy (u202318553)" << endl;
    cout << "- Crispin Aguilar, Alessandra Michelle (u202317258)" << endl;
    cout << "- Gonzales Ruiz, Leonardo Joel (u202317731)" << endl;
    cout << endl;
    cout << endl;

    Console::ForegroundColor = ConsoleColor::Yellow;
    cout << "------------Cafe Libreria de El Fondo------------" << endl;
}

int menu_libreria()
{
    int opc;
    cout << "Menu principal de Cafe Libreria de El Fondo: " << endl;
    cout << endl;
    cout << "1. Menu administradores" << endl;
    cout << "2. Menu clientes" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    do {
        cout << "Selecciones la opcion que desee: " << endl;
        cin >> opc;
    } while (opc < 1 && opc>3);
    return opc;
}

int menu_administradores()
{
    int opc;
    cout << "Menu SOLO para Administradores" << endl;
    cout << "1.- Registrar libros" << endl;
    cout << "2.- Imprimir libros" << endl;
    cout << "3.- Registrar sedes" << endl;
    cout << "4.- Imprimir sedes" << endl;
    cout << "5.- Reportes" << endl;
    cout << "6.- Volver al menu principal" << endl;
    do {
        cout << "Que opcion desea ? : ";
        cin >> opc;
    } while (opc < 1 && opc > 6);
    return opc;
}

int menu_clientes()
{
    int opc;
    cout << "Menu para clientes" << endl;
    cout << "1.- Reserva de libro" << endl;
    cout << "2.- Devolucion de libro" << endl;
    cout << "3.- Volver al menu principal" << endl;
    do {
        cout << "Que opcion desea ? : ";
        cin >> opc;
    } while (opc < 1 && opc > 3);
    return opc;
}

int menu_reportes()
{
    int opc;
    cout << "Menu de reportes" << endl;
    cout << "1.- Reporte de recaudacion semanal" << endl;
    cout << "2.- Porcentaje de libros entregados a tiempo, tarde y perdidos" << endl;
    cout << "3.- Cantidad de libros reservados por genero" << endl;
    cout << "4.- d" << endl;
    cout << "5.- Volver al menu anterior" << endl;
    do {
        cout << "Que opcion desea ? : ";
        cin >> opc;
    } while (opc < 1 && opc > 5);
    return opc;
}


void generar_codigol(sede* b, libro* a, int numgen, int nsedes)
{
    string titulos[15] = { "Don Quijote","El Gran Gatsby","Tiempo perdido","El guardián",
    "Guerra y paz","El enano","El instinto","La paciente","Sherlock Holmes","Loba negra",
    "Elfo Oscuro","El Talisman","Hielo y Fuego","Mata Reyes","Rueda Temporal" };
    string distritos[4] = { "MIRAFLORES" ,"SAN BORJA" ,"SAN ISIDRO","SURCO   " };
    Random dado;
    for (int i = 0;i < numgen; i++)
    {
        bool repetido;
        string title;
        a[i].code = dado.Next(100, 500 + 1);
        a[i].cost = dado.Next(40, 200 + 1);
        _sleep(50);

        do
        {
            repetido = false;
            title = titulos[dado.Next(0, 14 + 1)];
            for (int j = 0; j < i; ++j)
            {
                if (a[j].name == title)
                {
                    repetido = true;
                    break;
                }
            }
        } while (repetido);
        a[i].name = title;

        if (a[i].name == "Don Quijote" || a[i].name == "El Gran Gatsby" || a[i].name == "Tiempo perdido" || a[i].name == "El guardián" || a[i].name == "Guerra y paz")
            a[i].gen = "NOVELA  ";
        if (a[i].name == "El enano" || a[i].name == "El instinto" || a[i].name == "La paciente" || a[i].name == "Sherlock Holmes" || a[i].name == "Loba negra")
            a[i].gen = "MISTERIO";
        if (a[i].name == "Elfo Oscuro" || a[i].name == "El Talisman" || a[i].name == "Hielo y Fuego" || a[i].name == "Mata Reyes" || a[i].name == "Rueda Temporal")
            a[i].gen = "FANTASIA";
    }

    for (int i = 0;i < nsedes; i++)
    {
        b[i].code = dado.Next(1000, 9999 + 1);
        bool repetido;
        string sede;
        do
        {
            repetido = false;
            sede = distritos[dado.Next(0, 3 + 1)];
            for (int j = 0; j < i; ++j)
            {
                if (b[j].dis == sede)
                {
                    repetido = true;
                    break;
                }
            }
        } while (repetido);
        b[i].dis = sede;
    }
}

void registrar_un_libro(libro* a, int nlibros)
{
    cout << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "Ingrese el nombre del libro (no mas de 11 letras): ";
    cin >> a[nlibros].name;
    cout << endl;
    do {
        cout << "Ingrese codigo del libro (no mas de 3 digitos): ";
        cin >> a[nlibros].code;
    } while (a[nlibros].code < 100 && a[nlibros].code>999);
    cout << endl;
    do {
        cout << "Ingrese el genero del libro en mayusculas (NOVELA, MISTERIO, FANTASIA): ";
        cin >> a[nlibros].gen;
        cout << endl;
    } while (!(a[nlibros].gen == "NOVELA" || a[nlibros].gen == "MISTERIO" || a[nlibros].gen == "FANTASIA"));
    cout << "Ingrese el costo del libro: ";
    cin >> a[nlibros].cost;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void imprimir_libros(libro* a, int nlibros)
{
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Listado de libros: " << endl;
    cout << "Titulos:     " << '\t' << '\t' << '\t' << "Genero: " << '\t' << "Codigos: " << '\t' << "Costo: " << endl;
    for (int i = 0;i < nlibros;i++)
    {
        cout << a[i].name  << '\t' << '\t' << '\t' << a[i].gen << '\t' << a[i].code << '\t' << '\t' << a[i].cost << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void registrar_una_sede(sede* b, int nlibros)
{
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Ingrese el distrito de la sede: ";
    cin >> b[nlibros].dis;
    cout << endl;
    do {
        cout << "Ingrese codigo del libro (no mas de 4 digitos): ";
        cin >> b[nlibros].code;
    } while (b[nlibros].code < 1000 && b[nlibros].code>9999);
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void imprimir_sede(sede* b, int nlibros)
{
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Listado de libros: " << endl;
    cout << "Distrito: " << '\t' << '\t' << "Codigos: " << endl;
    for (int i = 0;i < nlibros;i++)
    {
        cout << b[i].dis << '\t' << '\t' << b[i].code << '\t' << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void reserva(sede* b, libro* a, reservas* c, int nlibros, int nsedes, int nreservas)
{
    int aux1, enl, ens;
     do {
        cout << endl;
        cout << "---------------------------------" << endl;
        cout << "Seleccione genero del libro: " << endl;
        cout << "1.NOVELA" << endl;
        cout << "2.MISTERIO" << endl;
        cout << "3.FANTASIA" << endl;
        cout << "---------------------------------" << endl;
        cout << "Genero (numero): " << endl;
        cin >> aux1;
        cout << endl;
        if (aux1 == 1)
        {
           cout << "------------------------------------------------------------------" << endl;
           cout << "Lista de libros de novelas: " << "\t\t" << "Codigos: " << endl;
           for (int i = 0;i < nlibros;i++)
           {
               if (a[i].name == "Don Quijote" || a[i].name == "El Gran Gatsby" || a[i].name == "Tiempo perdido" || a[i].name == "El guardián" || a[i].name == "Guerra y paz")
               {
                  cout << a[i].name << "\t\t\t\t" << a[i].code << endl;
                  c[nreservas].gen = "NOVELA";
               }
                     
           }
           cout << "------------------------------------------------------------------" << endl;
           cout << endl;
        }
        if (aux1 == 2)
        {
           cout << "------------------------------------------------------------------" << endl;
           cout << "Lista de libros de misterio: " << "\t\t" << "Codigos: " << endl;
           for (int i = 0;i < nlibros;i++)
           {
               if (a[i].name == "El enano" || a[i].name == "El instinto" || a[i].name == "La paciente" || a[i].name == "Sherlock Holmes" || a[i].name == "Loba negra")
               {
                  cout << a[i].name << "\t\t\t\t" << a[i].code << endl;
                  c[nreservas].gen = "MISTERIO";
               }
           }
           cout << "------------------------------------------------------------------" << endl;
           cout << endl;
        }
        if (aux1 == 3)
        {
           cout << "------------------------------------------------------------------" << endl;
           cout << "Lista de libros de fantasia: " << "\t\t" << "Codigos: " << endl;
           for (int i = 0;i < nlibros;i++)
           {
               if (a[i].name == "Elfo Oscuro" || a[i].name == "El Talisman" || a[i].name == "Hielo y Fuego" || a[i].name == "Mata Reyes" || a[i].name == "Rueda Temporal")
               {
                  cout << a[i].name << "\t\t\t\t" << a[i].code << endl;
                  c[nreservas].gen = "FANTASIA";
               }
           }
           cout << "------------------------------------------------------------------" << endl;
        }
        do {
           cout << endl;
           cout << "Codigo del libro a elegir: ";
           cin >> c[nreservas].code;
           for (int i = 0; i < nlibros; i++)
           {
               if (c[nreservas].code == a[i].code)
                   enl = c[nlibros].code;
           }
        } while (c[nlibros].code != enl);    
        cout << endl;
     } while (aux1 < 1 || aux1>3);
     cout << endl;
     cout << "--------------Sedes--------------" << endl;
     cout << "Distrito:" << "\t\t" << "Codigo:" << endl;
     for (int i = 0; i < nsedes; i++)
     {
         cout << b[i].dis << "\t\t" << b[i].code << endl;
     }
     cout << "---------------------------------" << endl;
     do {
        cout << endl;
        cout << "Ingrese codigo de la sede de recogida: ";
        cin >> c[nreservas].codesede;
        for (int i = 0; i < nsedes; i++)
        {
            if (c[nreservas].codesede == b[i].code)
            {
                ens = c[nreservas].codesede;
                c[nreservas].sede = b[i].dis;
            }
        }
     } while (c[nreservas].codesede != ens);
     cout << endl;
     cout << "Ingrese fecha de reserva: " << endl;
     cout << endl;
     do {
         cout << "Dia (1 a 28):         (Los fines de mes se hace inventario)" << endl;
        cin >> c[nreservas].dia;
     } while (c[nreservas].dia <= 0 || c[nreservas].dia > 28);
     cout << endl;
     do {
         cout << "Mes:          (En diciembre solo se aceptan devoluciones)" << endl;
        cin >> c[nreservas].mes;
     } while (c[nreservas].mes <= 0 || c[nreservas].mes > 11);
     cout << endl;
     do {
         cout << "Anio (4 digitos): " << endl;
         cin >> c[nreservas].anio;
         cout << endl;
     } while (c[nreservas].anio <= 2022);
     cout << "Horario de atencion (9 h - 21 h)" << endl;
     cout << endl;
     do {
        cout << "Hora:";
        cin >> c[nreservas].hora;
     } while (c[nreservas].hora <= 8 || c[nreservas].hora >= 22);
     cout << endl;
     do {
        cout << "Ingrese su numero DNI: ";
        cin >> c[nreservas].DNI;
     } while (c[nreservas].DNI < 9999999 || c[nreservas].DNI >= 99999999);
     cout << endl;
     cout << "--------RESERVA REALIZADA EXITOSAMENTE--------" << endl;
     cout << endl;
     cout << "Genero del libro: " << c[nreservas].gen << endl;
     cout << "Codigo del libro: " << c[nreservas].code << endl;
     cout << "Distrito de la sede: " << c[nreservas].sede << endl;
     cout << "Codigo de la sede: " << c[nreservas].codesede << endl;
     cout << "Fecha de reserva: " << c[nreservas].dia << "/" << c[nreservas].mes << "/" << c[nreservas].anio << " a las " << c[nreservas].hora << " horas." << endl;
     cout << "Fecha limite de devolución: " << c[nreservas].dia + 3 << "/" << c[nreservas].mes << "/" << c[nreservas].anio << " a las " << c[nreservas].hora << " horas." << endl;
     cout << "DNI del cliente: " << c[nreservas].DNI << endl;
     _getch();
    
}

void devolucion(sede* b, libro* a, reservas* c, int nlibros, int nsedes, int nreservas)
{
    if (nreservas == 0)
    {
        cout << endl;
        cout << "No se puede realizar la accion ya que no hay reservas registradas" << endl;
    }
    else {
        int dni, cost;
        bool encontrado = false;
        string ans;
        do {
            cout << endl;
            cout << "Ingrese DNI: ";
            cin >> dni;
            for (int i = 0; i < nreservas; i++)
                if (dni == c[i].DNI)
                {
                    encontrado == true;
                    cout << endl;
                    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "Codigo del libro:" << '\t' << "Codigo de sede:" << '\t' << "Fecha de devolucion: " << '\t' << "Hora de devolucion:" << endl;
                    cout << c[i].code << '\t' << '\t' << '\t' << c[i].codesede << '\t' << '\t' << c[i].dia + 3 << "/" << c[i].mes << "/" << c[i].anio << '\t' << '\t' << c[i].hora << endl;
                    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << endl;

                    cout << "Posee el libro? (SI / NO): ";
                    cin >> ans;
                    if (ans == "SI" || ans == "Si" || ans == "si")
                    {
                        cout << "Ingresa la fecha y hora exacta de la devolucion" << endl;
                        do {
                            cout << "Dia:";
                            cin >> c[nreservas].diad;
                        } while (c[nreservas].diad <= 0 || c[nreservas].diad > 31);
                        cout << endl;
                        do {
                            cout << "Mes:";
                            cin >> c[nreservas].mesd;
                        } while (c[nreservas].mesd <= 0 || c[nreservas].mesd > 12);
                        cout << endl;
                        do {
                            cout << "Anio:";
                            cin >> c[nreservas].aniod;
                        } while (c[nreservas].aniod <= 2022);
                        cout << endl;
                        cout << "Horario de atencion (9 h - 21 h)" << endl;
                        cout << endl;
                        do {
                            cout << "Hora:";
                            cin >> c[nreservas].horad;
                        } while (c[nreservas].horad <= 5 || c[nreservas].horad >= 23);

                        if (c[nreservas].diad <= c[i].dia + 3 && c[nreservas].mesd <= c[i].mes && c[nreservas].mesd <= c[i].hora && c[nreservas].aniod <= c[i].anio)
                        {
                            cout << "---------DEVOLUCION REALIZADA EXITOSAMENTE--------" << endl;
                            c[nreservas].multa = 0;
                        }
                        else
                        {
                            cout << "---------DEVOLUCION TARDIA--------" << endl;
                            c[nreservas].multa = 10;
                            cout << "El valor de la multa es: S/." << c[nreservas].multa;
                        }
                    }
                    if (ans == "NO" || ans == "No" || ans == "no")
                    {
                        if (c[i].code == a[i].code)
                        {
                            c[nreservas].multa = a[i].cost;
                            cout << "---------LIBRO PERDIDO--------" << endl;
                            cout << "El valor de la multa es: S/." << c[nreservas].multa << endl;
                        }
                        
                    }
 
                }
        } while (encontrado == false);
    }
}

void reporte_recaudacion_semanal(reservas* c, sede* b, int nreservas, int nsedes)
{
    int sede, suma1 = 0, suma2 = 0, suma3 = 0, suma4 = 0, mes, en;
    do {
        cout << "Codigo de la sede a evaluar: ";
        cin >> sede;
        for (int i = 0; i < nsedes; i++)
        {
            if (sede == b[i].code)
                en = sede;
        }
    } while (sede != en);
    do {
        cout << "Mes especifico a evaluar: ";
        cin >> mes;
    } while (mes < 0 || mes>12);
    for (int i = 0; i < nreservas; i++)
    {
        if (sede == c[i].codesede && mes == c[i].mesd && (c[i].diad >= 1 || c[i].diad <= 7))
            suma1 = suma1 + c[i].multa;
        if (sede == c[i].codesede && mes == c[i].mesd && (c[i].diad >= 8 || c[i].diad <= 15))
            suma2 = suma2 + c[i].multa;
        if (sede == c[i].codesede && mes == c[i].mesd && (c[i].diad >= 16 || c[i].diad <= 23))
            suma3 = suma3 + c[i].multa;
        if (sede == c[i].codesede && mes == c[i].mesd && (c[i].diad >= 24 || c[i].diad <= 31))
            suma4 = suma4 + c[i].multa;
    }
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << "Recaudacion semanal: " << endl;
    cout << "Semana 1: " << suma1 << endl;
    cout << "Semana 2: " << suma2 << endl;
    cout << "Semana 3: " << suma3 << endl;
    cout << "Semana 4: " << suma4 << endl;
    cout << "---------------------------------" << endl;
}

void porcentajes(reservas* c, int nreservas)
{
    int cont1 = 0, cont2 = 0, cont3 = 0;
    for (int i = 0; i < nreservas; i++)
    {
        if (c[i].multa == 0)
        {
            cont1++;
        }
        if (c[i].multa == 10)
        {
            cont2++;
        }
        if (c[i].multa > 10)
        {
            cont3++;
        }
    }
    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Porcentajes de libros entregados a tiempo, tarde y perdidos" << endl;
    cout << "Entregas puntuales: " << cont1 * 100.0 / nreservas << endl;
    cout << "Entregas tardias: " << cont2 * 100.0 / nreservas << endl;
    cout << "Libros perdidos: " << cont3 * 100.0 / nreservas << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
}

void reservado_por_genero(reservas* c, int nreservas)
{
    int cont1 = 0, cont2 = 0, cont3 = 0;
    for (int i = 0; i < nreservas; i++)
    {
        if (c[i].gen == "NOVELA  ")
        {
            cont1++;
        }
        if (c[i].gen == "MISTERIO")
        {
            cont2++;
        }
        if (c[i].gen == "FANTASIA")
        {
            cont3++;
        }
    }
    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Libros reservados por genero: " << endl;
    cout << "NOVELAS: " << cont1 << endl;
    cout << "MISTERIO: " << cont2 << endl;
    cout << "FANTASIA: " << cont3 << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
}

void main()
{
    int opcion, nlibros = 0, nsedes = 0, nreservas = 0, ndevoluciones = 0;
    libro* a = new libro[l];
    sede* b = new sede[s];
    reservas* c = new reservas[r];
    imprimir_inicio();
    cout << "Precione cualquier tecla para continuar..." << endl;
    _getch();
    Console::Clear();
    generar_codigol(b, a, 15, 4);nlibros = 15;nsedes = 4;
    do {
        opcion = menu_libreria();
        Console::Clear();
        switch (opcion)
        {
        case 1:
            do
            {
                Console::Clear();
                opcion = menu_administradores();
                switch (opcion)
                {
                case 1:registrar_un_libro(a, nlibros); nlibros++;break;
                case 2:imprimir_libros(a, nlibros);break;
                case 3:registrar_una_sede(b, nlibros);nsedes++;break;
                case 4:imprimir_sede(b, nlibros);break;
                case 5:do {
                    Console::Clear();
                    menu_reportes();
                    switch (opcion)
                    {
                    case 1:reporte_recaudacion_semanal(c, b, nreservas, nsedes);break;
                    case 2:porcentajes(c, nreservas);break;
                    case 3:reservado_por_genero(c, nreservas);break;
                    }
                }while(opcion != 5);break;
                }
                cout << endl;
                cout << "Precione cualquier tecla para continuar..." << endl;
                _getch();
                Console::Clear();
            } while (opcion != 6);break;
        case 2:
            do
            {
                Console::Clear();
                opcion = menu_clientes();
                switch (opcion)
                {
                case 1:reserva(b, a, c, nlibros, nsedes, nreservas);nreservas++;break;
                case 2:devolucion(b, a, c, nlibros, nsedes, nreservas);ndevoluciones++;break;
                }
                cout << endl;
                cout << "Precione cualquier tecla para continuar..." << endl;
                _getch();
                Console::Clear();
            } while (opcion != 3);break;
        }
        _getch();
    } while (opcion != 3);
    _getch();

    delete[]a;
    delete[]b;
    delete[]c;
}