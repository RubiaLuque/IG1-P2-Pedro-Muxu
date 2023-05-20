#pragma once
#include "../Structure/GameObject.h"

class CrazyBow : public GameObject {
private:
    const int TIMER = 5;
    const int BANNER_WIDTH = 600;
    const int BANNER_HEIGHT = 200;
    const int BANNER_LETTER_SIZE = 75;
    const int BANNER_CIRCLE_RADIUS = 70;

    int blockSize;
    int nBlocksLong;
    int nBlocksHigh;
    int nRandomCoins;
    int nMaxCoins;
    bool canPass;
    float elapsedTime;
    // frame buffer object que funciona como un contenedor de texturas
    // se dibuja en el buffer como si se tratara de la pantalla y luego, se pinta
    // lo que hay en el buffer en la pantalla en el lugar que se quiera
    // se puede pintar en el frame buffer object en cualquier momento
    ofFbo fbo;
    ofTexture texture;
    ofTrueTypeFont font;

    void bannerText(int num);

public:
    CrazyBow(Game* game, glm::vec3 pos, glm::vec3 dim, int nBlocksLong, int nBlocksHigh, int blockSize, glm::vec4 rotation, int nMaxCoins);

    virtual void update();

    virtual void draw();

    virtual void receiveCarCollision(Player* car);
};