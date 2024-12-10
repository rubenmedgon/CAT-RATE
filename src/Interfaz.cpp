#include "Interfaz.hpp"

Interfaz::Interfaz(){
    if (!font.loadFromFile("./assets/Minecraft.ttf"))
    cout << "Error al cargar la fuente" << endl;
    
    //setFont
    fuego1Text.setFont(font);
    agua1Text.setFont(font);
    planta1Text.setFont(font);

    fuego2Text.setFont(font);
    agua2Text.setFont(font);
    planta2Text.setFont(font);

    resultadoText.setFont(font);
    rondaText.setFont(font);

    //setPosition
    fuego1Text.setPosition(50,50);
    agua1Text.setPosition(200,50);
    planta1Text.setPosition(350,50);

    fuego2Text.setPosition(630,50);
    agua2Text.setPosition(780,50);
    planta2Text.setPosition(930,50);

    resultadoText.setPosition(260,420);
    rondaText.setPosition(50,100);

    //Escalas
    fuego1Text.setCharacterSize(40);
    agua1Text.setCharacterSize(40);
    planta1Text.setCharacterSize(40);

    fuego2Text.setCharacterSize(40);
    agua2Text.setCharacterSize(40);
    planta2Text.setCharacterSize(40);

    resultadoText.setCharacterSize(50);
    rondaText.setCharacterSize(30);
    
    pantallaNegra.setSize(Vector2f(1080, 900));
    pantallaNegra.setFillColor(Color::Black);
    mostrarPantallaNegra = false;
}

void Interfaz::Update(){
    rondaText.setString("Round: " + to_string(ronda));
    rondaText.setFillColor(Color::White);

    if(fuego1>9 && fuego2>9){
        fuego1Text.setString("F: "+to_string(fuego1));
        fuego2Text.setString("F: "+to_string(fuego2));
    }else{
        fuego1Text.setString("F: 0"+to_string(fuego1));
        fuego2Text.setString("F: 0"+to_string(fuego2));
    } 

    if(agua1>9 && agua2>9){
        agua1Text.setString("A: "+to_string(agua1));
        agua2Text.setString("A: "+to_string(agua2));
    }else{
        agua1Text.setString("A: 0"+to_string(agua1));
        agua2Text.setString("A: 0"+to_string(agua2));
    } 

    if(planta1>9 && planta2>9){
        planta1Text.setString("P: "+to_string(planta1));
        planta2Text.setString("P: "+to_string(planta2));
    }else{
        planta1Text.setString("P: 0"+to_string(planta1));
        planta2Text.setString("P: 0"+to_string(planta2));
    } 

    //Mensaje de ganador
    if((fuego1==3) || (agua1==3) || (planta1==3) || (fuego1 > 0 && agua1 > 0 && planta1 > 0)) {
        mostrarPantallaNegra = true;
        resultadoText.setString("PLAYER 1 YOU'VE WON!");
        resultadoText.setFillColor(Color::Green);
    }
    if((fuego2==3) || (agua2==3) || (planta2==3) || (fuego2 > 0 && agua2 > 0 && planta2 > 0)) {
        mostrarPantallaNegra = true;
        resultadoText.setString("PLAYER 2 YOU'VE WON!");
        resultadoText.setFillColor(Color::Green);
    }
}

void Interfaz::CambiarRonda(int crum){
    ronda+=crum;
}

void Interfaz::CambiarFuego1(int mod){
    fuego1+=mod;
}

void Interfaz::CambiarAgua1(int mod){
    agua1+=mod;
}

void Interfaz::CambiarPlanta1(int mod){
    planta1+=mod;
}

int Interfaz::ConsultarFuego1(){
    return fuego1;
}

int Interfaz::ConsultarAgua1(){
    return agua1;
}

int Interfaz::ConsultarPlanta1(){
    return planta1;
}

void Interfaz::CambiarFuego2(int mod){
    fuego2+=mod;
}

void Interfaz::CambiarAgua2(int mod){
    agua2+=mod;
}

void Interfaz::CambiarPlanta2(int mod){
    planta2+=mod;
}

int Interfaz::ConsultarFuego2(){
    return fuego2;
}

int Interfaz::ConsultarAgua2(){
    return agua2;
}

int Interfaz::ConsultarPlanta2(){
    return planta2;
}

void Interfaz::draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(fuego1Text,rs);
    rt.draw(agua1Text,rs);
    rt.draw(planta1Text,rs);

    rt.draw(fuego2Text,rs);
    rt.draw(agua2Text,rs);
    rt.draw(planta2Text,rs);
    rt.draw(rondaText,rs);

    if (mostrarPantallaNegra) {
        rt.draw(pantallaNegra, rs);
        rt.draw(resultadoText, rs);
    }
}