//
// Created by Ariana González on 07/09/23.
//
#include <iostream>
#include<ctime>

void delay(int secs) {
    for(int i = (time(NULL) + secs); time(NULL)!= i; time(NULL));
} //Esta función sevirá para la simulación de correr los motores por un cierto tiempo

//Creamos funciones de movimiento del robot
//En todos los motores {1} atras, {-1} adelante

float adelante(float metros){


    float tiempo{};

    tiempo = metros/1.43;


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

float atras(float metros){

    float tiempo{};

    tiempo = metros/1.43;

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

int derecha(int tiempo){

    float centimetros{};

    int motor_FD{1};
    int motor_FI{-1};
    int motor_AD{1};
    int motor_AI{-1};

    delay(tiempo);

    //int motor_FD{0};
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0};

    centimetros = tiempo * 1.43;

    std::cout <<  "Ha girado  "<< centimetros << " cm a la derecha"<< std::endl;
    return tiempo;
}

int izquierda(int tiempo){

    float centimetros{};


    int motor_FD{-1};
    int motor_FI{1};
    int motor_AD{-1};
    int motor_AI{1};
    delay(tiempo);

    //int motor_FD{0};
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0};

    centimetros = tiempo * 14.3;

    std::cout <<  "Ha rotado  "<< centimetros << " cm a la izquierda"<< std::endl;
    return tiempo;
}

//Funciones para los mecanismos


int elevador_subir(float cm){

    float tiempo{};
    // tiempo = RPM - tuerca tamaño


    int motor_e1{1}; //motor para polea 1
    int motor_e2{1}; //motor para polea 2
    delay(tiempo);

    //int motor_e1{0};
    //int motor_e2{0};

    std::cout << "Se elevó " << cm<<" cm en "<<tiempo <<" seg"<<std::endl;


    return tiempo;
}
int elevador_descender(float cm){

    float tiempo{};
    // tiempo = RPM - tuerca tamaño

    int motor_e1{-1}; //motor para polea 1
    int motor_e2{-1}; //motor para polea 2
    delay(tiempo);

    //int motor_e1{0};
    //int motor_e2{0};

    std::cout << "Descendió " << cm<<" cm en "<<tiempo <<" seg"<<std::endl;

    return tiempo;

}


int main (){

    double tiempo_total{};

    bool Piston = false;  // Representación de válvula que mueve el pistón, solo dos valores
    //Se inicia desde el principio para asegurarnos que este cerrado


    //Aútonomo
    //Van a depender tambien de la posición incial del robot

    int selecc_autonomo{};
    std::cout << "Fase autónomo" << std::endl;
    std::cout << "1. Quitar llanta delantera izquierda de coche " << std::endl;
    std::cout << "2. Traer llanta de garage" << std::endl;
    std::cout << "3. Quitar llanta delantera derecha de coche" << std::endl;
    std::cin >> selecc_autonomo;

    if (selecc_autonomo==1){

        float tiempo1 (adelante (4.558));
        float tiempo2 (izquierda(4));
        float tiempo3 (elevador_subir(25));
        float tiempo4 (Piston=true);
        float tiempo5 (atras(0.10));


        double tiempo_auto{15-tiempo1-tiempo2-tiempo3-tiempo4-tiempo5};
        std::cout << "El robot ha avanzado hasta posicionarse delante de la rueda delantera izquierda del coche, y la ha quitado, se alejo 10 cm del coche"<< std::endl;
        std::cout << "Ha sobrado "<< tiempo_auto << " seg del autónomo" << std::endl;
        delay(10); //Esto solo es por fines estéticos en la terminal

    } else if (selecc_autonomo==3){

        float tiempo1 (adelante (4.558));
        float tiempo2 (derecha(4));
        float tiempo3 (elevador_subir(25));
        float tiempo4 (Piston=true);
        float tiempo5 (atras(0.10));


        double tiempo_auto{15-tiempo1-tiempo2-tiempo3-tiempo4-tiempo5};
        std::cout << "El robot ha avanzado hasta posicionarse delante de la rueda delantera derecha del coche, y la ha quitado, se alejo 10 cm del coche"<< std::endl;
        std::cout << "Ha sobrado "<< tiempo_auto << " seg del autónomo" << std::endl;
        delay(10); //Esto solo es por fines estéticos en la terminal


    }


    //Teleoperado
    std::cout << "Fase de teleoperado" << std::endl;

    int seleccion_boton{};


    while (seleccion_boton != 4) {

        //Recomendaciones

        if (tiempo_total > 130 && tiempo_total < 140){
            std::cout << "Tu tiempo de teleoperado es mayor a 2 minutos, apresura al end game" << std::endl;
        }

        if (tiempo_total > 90 && tiempo_total < 100){
            std::cout << "Llevas " << tiempo_total << " seg de teleoperado, sigue al reto 2" << std::endl;
        }

        //Menu de botones

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
                float metros{};

                std::cout<< "Metros a avanzar: "<< std::endl;
                std::cin >> metros;
                float tiempo(adelante(metros));
                tiempo_total = tiempo_total + tiempo;


            } else if (selecc2 == 1.2) {
                float metros{};

                std::cout<< "Metros a retroceder: "<< std::endl;
                std::cin >> metros;

                float tiempo(atras(metros));
                tiempo_total = tiempo_total + tiempo;


            } else if (selecc2 == 1.3) {

                int tiempo{};

                std::cout << "Tiempo a rotar en segundos: "<< std::endl;
                std::cin >> tiempo;

                izquierda(tiempo);
                tiempo_total = tiempo_total + tiempo;


            } else if (selecc2 == 1.4) {

                int tiempo{};

                std::cout << "Tiempo a rotar en segundos: "<< std::endl;
                std::cin >> tiempo;

                derecha(tiempo);
                tiempo_total = tiempo_total + tiempo;


            } else {
                std::cout << "Inválido" << std::endl;
            }

        } else if (seleccion_boton == 2) {

            double elecc_elevador{};
            std::cout << "2.1 Elevar " << std::endl;
            std::cout << "2.1 Descender" << std::endl;
            std::cin >> elecc_elevador;

            if (elecc_elevador == 2.1) {

                float cm;
                std::cout << "Centímetros a elevarse: " << std::endl;
                std::cin >> cm;

                int tiempo(elevador_subir(cm));
                tiempo_total = tiempo_total + tiempo;


            } else if (elecc_elevador == 2.2){

                float cm;
                std::cout << "Centímetros a descender: " << std::endl;
                std::cin >> cm;

                int tiempo(elevador_descender(cm));
                tiempo_total = tiempo_total + tiempo;


            } else{
                std::cout << "Inválido" << std::endl;
            }

        } else if (seleccion_boton == 3) {
            double selecc_piston{};

            std::cout << "3.1. Abrir "<< std::endl;
            std::cout << "3.2. Cerrar "<< std::endl;
            std::cin >> selecc_piston;


            if (selecc_piston == 3.1){

                bool abierto = true;
                std::cout <<  "El pistón se abrió"<< std::endl;

            } else if (selecc_piston == 2){

                bool abierto = false;
                std::cout <<  "El pistón se cerró"<< std::endl;

            } else{
                std::cout << "Invalido" << std::endl;

            }

            tiempo_total = tiempo_total + 1;


        } else if (seleccion_boton == 4){ //Para terminar fase teleoperado

            std::cout << "El tiempo total ha sido de " << tiempo_total << " seg" << std::endl;
            exit(0);
        }
        else{
            std::cout << "Inválido" << std::endl;
        }


    }
    return 0;

}