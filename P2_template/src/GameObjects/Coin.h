//
//  Coin.h
//  P2_template
//
//  Created by Miguel Valero Espada on 19/4/23.
//

#ifndef Coin_h
#define Coin_h
#include "../Structure/GameObject.h"

class Coin : public GameObject {
private:

public:
    Coin(Game* game, glm::vec3 pos, glm::vec3 dim);

    void receiveCarCollision(Player* car) override;
};

#endif /* Coin_h */
