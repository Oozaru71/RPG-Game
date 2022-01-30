#include <iostream>

using namespace std;

class Gamer {
private:
	int gamerHP;
	int gamerEXP;
	string gamerName;
	int gamerAttack;
	int gamerLVL;
	int gamerMaxHP;
	int gamerMaxEXP;
	int gamerGold;
	int critChance;
	int itemCost1;
	int itemCost2;
	int itemCost3;
	int itemCost4;
	int itemCost5;
public:
	Gamer();
	Gamer(string name);
	int getItemCost(int item);
	int getGamerAttack();
	int getCurrentHp();
	int getCritChance();
	void takeGold(int gold);
	void wonGame();
	bool takeDamage(int attack);
	void levelUp();
	void expUP(int val);
	void displayStats();
	bool gamerShop(int itemChoice);

};

class Enemy {
private:
	string enemyName;
	int enemyHP;
	int enemyDropExp;
	int enemyAttack;
	int enemyMaxHP;
	int enemyGold;
	
public:
	Enemy();
	Enemy(string name);
	string getEnemyName();
	int getEnemyAttack();
	int getEnemyDropExp();
	int getEnemyHP();
	int getEnemyMaxHP();
	int getEnemyGold();
	void takeDamage(int attack);
	void displayEnemyStats();
};


