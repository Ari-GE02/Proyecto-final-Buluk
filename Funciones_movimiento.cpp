
#include<iostream>
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


    std::cout <<  "Ha avanzado  "<< metros << "m"<< "en "<< tiempo<<" seg"<< std::endl;
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


    std::cout <<  "Ha retrocedido  "<< metros << "m"<< "en" << tiempo << " segs"<<std::endl;
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

int main () {
    int selecc;
    std::cout << "Empezamos"  << std::endl;

    std::cin >> selecc;
    if (selecc ==1){
        izquierda();
    } else if (selecc ==2){
        derecha();
    }
};