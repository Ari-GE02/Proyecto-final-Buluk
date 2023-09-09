
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


    int motor_FD{-1}; //motor frente derecho --> puerto 15
    int motor_FI{-1}; //motor frente izquierdo --> puerto 18
    int motor_AD{-1}; //motor atras derecho --> puerto 0
    int motor_AI{-1}; //motor atras izquierdo --> puerto 19
    //delay(tiempo);

    //int motor_FD{0};//Motores en 0 para que se paren de mover
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0};



    std::cout <<  "Ha avanzado "<< metros << " m"<< " en "<< tiempo<<" seg"<< std::endl;
    return tiempo;
}

float atras(float metros){

    float tiempo{};

    tiempo = metros/1.43;

    int motor_FD{1};
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

double derecha(double tiempo){

    double centimetros{};

    int motor_FD{1};
    int motor_FI{-1};
    int motor_AD{1};
    int motor_AI{-1};

    delay(tiempo);

    //int motor_FD{0};
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0};

    centimetros = tiempo * 143;

    std::cout <<  "Ha girado  "<< centimetros << " cm a la derecha"<< std::endl;
    return tiempo;
}

double izquierda(double tiempo){

    double centimetros{};


    int motor_FD{-1};
    int motor_FI{1};
    int motor_AD{-1};
    int motor_AI{1};
    delay(tiempo);

    //int motor_FD{0};
    //int motor_FI{0};
    //int motor_AD{0};
    //int motor_AI{0};

    centimetros = tiempo * 143;

    std::cout <<  "Ha girado  "<< centimetros << " cm a la izquierda"<< std::endl;
    return tiempo;
}

//Funciones para los mecanismos

int elevador_subir(float cm){

    float tiempo{};
    tiempo = cm / 47;


    int motor_e1{1}; //motor para polea 1 --> puerto 16
    int motor_e2{1}; //motor para polea 2 --> puerto 17
    delay(tiempo);

    //int motor_e1{0};
    //int motor_e2{0};

    std::cout << "El elevador se elevó " << cm<<" cm en "<<tiempo <<" seg"<<std::endl;


    return tiempo;
}
int elevador_descender(float cm){

    float tiempo{};
    tiempo = cm / 47;

    int motor_e1{-1}; //motor para polea 1 --> puerto 16
    int motor_e2{-1}; //motor para polea 2 --> puerto 17
    delay(tiempo);

    //int motor_e1{0};
    //int motor_e2{0};

    std::cout << "El elevador descendió " << cm<<" cm en "<<tiempo <<" seg"<<std::endl;

    return tiempo;

}


int main () {

    bool Piston = false;  // Representación de válvula que mueve el pistón, solo dos valores --> puerto 3 (true) puerto 4 (false)
    //Se inicia desde el principio para asegurarnos que este cerrado


    //Aútonomo
    //Van a depender tambien de la posición incial del robot en la cancha

    int selecc_autonomo{};
    std::cout << "Fase autónomo" << std::endl;
    std::cout << "Ingresa un número" << std::endl;
    std::cout << "1. Quitar llanta delantera izquierda de coche " << std::endl;
    std::cout << "2. Traer llanta de garage" << std::endl;
    std::cout << "3. Quitar llanta delantera derecha de coche" << std::endl;
    std::cin >> selecc_autonomo;

    if (selecc_autonomo == 1) {
        //Las medidas son de acuerdo a la cancha

        //Instrucciones
        float tiempo1(adelante(4.558));
        float tiempo2(izquierda(0.4));
        float tiempo3(elevador_descender(16)); //Pues su posicion incial ya es arriba, se baja para tomar la llanta
        (Piston = true); //+1 de tiempo
        float tiempo5(atras(0.10)); //Toma la llanta
        float tiempo6(derecha(0.4));
        float tiempo7(adelante(4.72));
        float tiempo8(izquierda(0.4));
        float tiempo9(adelante(0.95));
        float tiempo10(derecha(0.4));
        float tiempo11(adelante(3.06)); //Deja la llanta en garage
        (Piston = false); //+1 de tiempo


        double tiempo_auto{
                15 - tiempo1 - tiempo2 - tiempo3 - tiempo5 - tiempo6 - tiempo7 - tiempo8 - tiempo9 - tiempo10 -
                tiempo11 + 2};
        std::cout
                << "El robot ha avanzado y quitado la rueda delantera izquierda del coche, se dirigió hacia el gaarage y la soltó"
                << std::endl;
        std::cout << "Ha sobrado " << tiempo_auto << " seg del autónomo" << std::endl;
        delay(10); //Esto solo es por fines estéticos en la terminal

    } else if (selecc_autonomo == 3) {

        //Instrucciones
        float tiempo1(adelante(4.558));
        float tiempo2(derecha(0.4));
        float tiempo3(elevador_descender(16));
        (Piston = true); //+1 de tiempo
        float tiempo5(atras(0.10));
        float tiempo6(izquierda(0.4));
        float tiempo7(adelante(4.72));
        float tiempo8(derecha(0.4));
        float tiempo9(adelante(0.44));
        float tiempo10(izquierda(0.4));
        float tiempo11(adelante(3.06));
        (Piston = false); //+1 de tiempo


        double tiempo_auto{
                15 - tiempo1 - tiempo2 - tiempo3 - tiempo5 - tiempo6 - tiempo7 - tiempo8 - tiempo9 - tiempo10 -
                tiempo11 + 2};
        std::cout
                << "El robot ha avanzado y quitado la rueda delantera derecha del coche, se dirigió hacia el gaarage y la soltó"
                << std::endl;
        std::cout << "Ha sobrado " << tiempo_auto << " seg del autónomo" << std::endl;
        delay(10); //Esto solo es por fines estéticos en la terminal


    } else if (selecc_autonomo == 2) {
        float tiempo1(adelante(9.71)); //Se posiciono enfrente de garage
        float tiempo2(elevador_subir(11)); //Coloca la altura para tomar la llanta
        float tiempo3(adelante(3.06));
        (Piston = true); //+1 de tiempo
        float tiempo4(atras(0.10));

        double tiempo_auto{15 - tiempo1 - tiempo2 - tiempo3 - tiempo4};
        std::cout << "El robot ha avanzado hasta el garage, acomodado la altura para tomar la llanta y retrocedió 10 cm"
                  << std::endl;
        std::cout << "Ha sobrado " << tiempo_auto << " seg del autónomo" << std::endl;
        delay(10); //Esto solo es por fines estéticos en la terminal



    }


    //Teleoperado

    std::cout << "Fase de teleoperado" << std::endl;
    std::cout << "Ingresa un número" << std::endl;

    int seleccion_boton{};
    double tiempo_total{135};


    while (tiempo_total != 0) {


        //Recomendaciones
        if (tiempo_total < 10 && tiempo_total > 5) {
            std::cout << "Últimos 10 segundos" << std::endl;
        }
        if (tiempo_total < 5) {
            std::cout << "Últimos 5 segundos" << std::endl;
        }

        if (tiempo_total < 20 && tiempo_total > 10) {
            std::cout << "Recomendación: 20 segundos restantes, sigue al end game" << std::endl;
        }

        if (tiempo_total < 60 && tiempo_total > 50) {
            std::cout << "Recomendación; 1 min restante, sigue a la fase 2" << std::endl;
        }

        //Menu de botones

        std::cout << "1. Stick: Delante, Atrás, Giro Izquierda, Giro Derecha" << std::endl;
        std::cout << "2. Botón A: Mover Brazo" << std::endl;
        std::cout << "3. Botón B: Mover Pistón" << std::endl;

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

                std::cout << "Metros a avanzar: " << std::endl;
                std::cin >> metros;
                float tiempo(adelante(metros));
                tiempo_total = tiempo_total - tiempo;


            } else if (selecc2 == 1.2) {
                float metros{};

                std::cout << "Metros a retroceder: " << std::endl;
                std::cin >> metros;

                float tiempo(atras(metros));
                tiempo_total = tiempo_total - tiempo;


            } else if (selecc2 == 1.3) {

                double tiempo{};

                std::cout << "Al rotar 0.4 seg alrededor de 90º " << std::endl;
                std::cout << "Tiempo a rotar en segundos: " << std::endl;
                std::cin >> tiempo;

                izquierda(tiempo);
                tiempo_total = tiempo_total - tiempo;


            } else if (selecc2 == 1.4) {

                double tiempo{};

                std::cout << "Al rotar 0.4 seg alrededor de 90º " << std::endl;
                std::cout << "Tiempo a rotar en segundos: " << std::endl;
                std::cin >> tiempo;

                derecha(tiempo);
                tiempo_total = tiempo_total - tiempo;


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
                tiempo_total = tiempo_total - tiempo;


            } else if (elecc_elevador == 2.2) {

                float cm;
                std::cout << "Centímetros a descender: " << std::endl;
                std::cin >> cm;

                int tiempo(elevador_descender(cm));
                tiempo_total = tiempo_total - tiempo;


            } else {
                std::cout << "Inválido" << std::endl;
            }

        } else if (seleccion_boton == 3) {
            double selecc_piston{};

            std::cout << "3.1. Abrir " << std::endl;
            std::cout << "3.2. Cerrar " << std::endl;
            std::cin >> selecc_piston;


            if (selecc_piston == 3.1) {

                bool abierto = true;
                std::cout << "El pistón se abrió" << std::endl;

            } else if (selecc_piston == 2) {

                bool abierto = false;
                std::cout << "El pistón se cerró" << std::endl;

            } else {
                std::cout << "Invalido" << std::endl;

            }

            tiempo_total = tiempo_total + 1;


        } else {
            std::cout << "Inválido" << std::endl;
        }


    }

    std::cout << "Se terminó el match" << std::endl;
    return 0;

}