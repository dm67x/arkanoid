#ifndef BALL_NUMBER_COMPONENT_H
#define BALL_NUMBER_COMPONENT_H

/**
 *  \file ball_number.h
 *  \brief Composant pour connaitre le nombre de balle
 *  \version 1.0
 */

#include "component.h"

/**
 * \namespace Components
 */
namespace Components
{
    /**
     * \class BallNumber
     * \brief composant permettant de connaitre 
     * le nombre de balle que possède un joueur
     */
    class BallNumber : public Component
    {
    public:
        /**
         * \brief Constructeur
         */
        BallNumber() : number(0) { }

        int number;

        std::string name() const override { return "ball_number"; }
    };
}

#endif