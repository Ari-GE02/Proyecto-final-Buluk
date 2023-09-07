#include <iostream>
#include<ctime>

void delay(int secs) {
    for(int i = (time(0) + secs); time(0)!= i; time(0));
} //Esta función sevirá para la simulación de correr los motores por un cierto tiempo


//Creamos funciones de movimiento del robot
//En todos los motores {1} atras, {-1} adelante

float adelante(){

    float metros{};
    float tiempo{};

    std::cout<< "Metros a avanzar: "<< std::endl;
    std::cin >> metros;

    // tiempo = velocidad- peso, torque, llanta


    int motor_FD{-1}; //motor frente derecho
    int motor_FI{-1}; //motor frente izquierdo
    int motor_AD{-1}; //motor atras derecho
    int motor_AI{-1}; //motor atras izquierdo
    delay(tiempo);

    //int motor_FD{0};
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0}; //Motores en 0 para que se paren de mover


    std::cout <<  "Ha avanzado "<< metros << " m"<< " en "<< tiempo<<" seg"<< std::endl;
    return tiempo;
}

float atras(){

    float metros{};
    float tiempo{};

    std::cout<< "Metros a retroceder: "<< std::endl;
    std::cin >> metros;

    // tiempo = velocidad- peso, torque, llanta

    int motor_FD{1}; //motores hipoteticos conectados a puerto ...
    int motor_FI{1};
    int motor_AD{1};
    int motor_AI{1};

    delay(tiempo);

    //int motor_FD{0};
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0};


    std::cout <<  "Ha retrocedido  "<< metros << " m"<< " en " << tiempo << " segs"<<std::endl;
    return tiempo;
}

int derecha(){

    float centimetros{};
    int tiempo{};

    std::cout << "Tiempo a rotar en segundos: "<< std::endl;
    std::cin >> tiempo;

    int motor_FD{1};
    int motor_FI{-1};
    int motor_AD{1};
    int motor_AI{-1};

    delay(tiempo);

    //int motor_FD{0};
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0};

    //centimetros == velocidad;

    std::cout <<  "Ha girado  "<< centimetros << " cm a la derecha"<< std::endl;
    return tiempo;
}

int izquierda(){

    float centimetros{};
    int tiempo{};

    std::cout << "Tiempo a rotar en segundos: "<< std::endl;
    std::cin >> tiempo;


    int motor_FD{-1};
    int motor_FI{1};
    int motor_AD{-1};
    int motor_AI{1};
    delay(tiempo);

    //int motor_FD{0};
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0};

    //centimetros == torque, tiempo, peso;

    std::cout <<  "Ha rotado  "<< centimetros << " cm a la izquierda"<< std::endl;
    return tiempo;
}


//Funciones para los mecanismos

int elevador(){

    float cm;
    float tiempo{};
    int input{}; //Elección del usuario

    std::cout << "1. Subir "<< std::endl;
    std::cout << "2. Bajar "<< std::endl;

    std::cin>>input;

    // tiempo = RPM - tuerca tamaño

    if (input==1) {

        std::cout << "Centímetros a elevarse: " << std::endl;
        std::cin >> cm;

        int motor_e1{1}; //motor para polea 1
        int motor_e2{1}; //motor para polea 2
        delay(tiempo);

        //int motor_e1{0};
        //int motor_e2{0};

        std::cout << "Se elevó " << cm<<" cm en "<<tiempo <<" seg"<<std::endl;


    } else if (input==2){
        std::cout << "Centímetros a descender: " << std::endl;
        std::cin >> cm;

        int motor_e1{-1}; //motor para polea 1
        int motor_e2{-1}; //motor para polea 2
        delay(tiempo);

        //int motor_e1{0};
        //int motor_e2{0};

        std::cout << "Descendió " << cm<<" cm en "<<tiempo <<" seg"<<std::endl;


    } else {
        std::cout << "Inválido"<< std::endl;
    }

    return tiempo;
}


bool piston(bool abierto){

    int input{}; //Elección del usuario

    std::cout << "1. Abrir "<< std::endl;
    std::cout << "2. Cerrar "<< std::endl;
    std::cin >> input;


    if (input == 1){

        bool abierto = true;
        std::cout <<  "El pistón se abrió"<< std::endl;

    } else if (input == 2){


        bool abierto = false;
        std::cout <<  "El pistón se cerró"<< std::endl;
    } else{
        std::cout << "Invalido" << std::endl;

    }

    return abierto;

}

int main (){

    double tiempo_total{};

    bool Piston = false;  // Representación de válvula que mueve el pistón
                            //Este si se inicia desde el principio para asegurarnos que este cerrado


    //Aútonomo aun no esta aqui


    //Teleoperado
    std::cout << "Fase de teleoperado" << std::endl;

    int seleccion_boton{};


    while (seleccion_boton != 4) {


        std::cout << "1. Stick: Delante, Atrás, Giro Izquierda, Giro Derecha" << std::endl;
        std::cout << "2. Botón A: Mover Brazo" << std::endl;
        std::cout << "3. Botón B: Mover Pistón" << std::endl;
        std::cout << "4. Alto" << std::endl;
        std::cin >> seleccion_boton;

        if (seleccion_boton == 1) {
            double selecc2{};
            std::cout << "1.1 Delante" << std::endl;
            std::cout << "1.2 Atrás" << std::endl;
            std::cout << "1.3 Giro Izquierda" << std::endl;
            std::cout << "1.4 Giro Derecha" << std::endl;
            std::cin >> selecc2;

            if (selecc2 == 1.1) {
                float tiempo(adelante());
                tiempo_total = tiempo_total + tiempo;
                std::cout << tiempo_total;

            } else if (selecc2 == 1.2) {
                float tiempo(atras());
                tiempo_total = tiempo_total + tiempo;
                std::cout << tiempo_total;

            } else if (selecc2 == 1.3) {
                float tiempo(izquierda());
                tiempo_total = tiempo_total + tiempo;
                std::cout << tiempo_total;

            } else if (selecc2 == 1.4) {
                float tiempo(derecha());
                tiempo_total = tiempo_total + tiempo;
                std::cout << tiempo_total;

            } else {
                std::cout << "Inválido" << std::endl;
            }

        } else if (seleccion_boton == 2) {
            int tiempo(elevador());
            tiempo_total = tiempo_total + tiempo;
            std::cout << tiempo_total;

        } else if (seleccion_boton == 3) {
            piston(Piston);
            tiempo_total = tiempo_total + 1;
            std::cout << tiempo_total;

        } else if (seleccion_boton == 4){
            std::cout << "El tiempo total ha sido de " << tiempo_total << " seg" << std::endl;
            exit(0);
        }
        else{
            std::cout << "Inválido" << std::endl;
        }


    }


}
