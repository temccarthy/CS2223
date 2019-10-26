/*
 * Game.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Tim
 */

#ifndef GAME_H_
#define GAME_H_



class Game{
public:
	int colors[3];

	Game();
	virtual ~Game();

	void makeMove(int color, int numTake);
	void makeRandomMove();
	void makeComputerMove();

private:
	int findNimSum();
};

#endif /* GAME_H_ */
