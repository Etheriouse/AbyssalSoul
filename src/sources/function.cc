#include <iostream>


/**
 * @param coordonnée
 * @return la parti x de la coordonnée
*/
int getX(int xy) {
    return (int) xy/100;
}

/**
 * @param coordonnée
 * @return la parti y de la coordonnée
*/
int getY(int xy) {
    return xy%100;
}