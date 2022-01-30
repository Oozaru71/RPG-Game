#include "OrgClasses.h"

Gamer::Gamer()
{
	gamerHP=0;
	gamerEXP=0;
	gamerName="Null";
	gamerAttack=0;
	gamerLVL=0;
	gamerMaxHP=0;
	gamerMaxEXP = 0;
	critChance = 0;
	itemCost1=0;
	itemCost2=0;
	itemCost3=0;
	itemCost4=0;
	itemCost5 = 0;
	
}

Gamer::Gamer(string name)
{
	if (name == "Kindred")
	{
		gamerEXP = 0;
		gamerName = name;
		gamerAttack = 20;
		gamerLVL = 1;
		gamerMaxHP = 1000;
		gamerHP = gamerMaxHP;
		gamerMaxEXP = 20;
		gamerGold = 1000;
		critChance = 1;
		itemCost1 = 10;
		itemCost2 = 10;
		itemCost3 = 5;
		itemCost4 = 27;
		itemCost5 = 15;
	}
	else {
		gamerEXP = 0;
		gamerName = name;
		gamerAttack = 5;
		gamerLVL = 1;
		gamerMaxHP = 22;
		gamerHP = gamerMaxHP;
		gamerMaxEXP = 20;
		gamerGold = 0;
		critChance = 1;
		itemCost1 = 10;
		itemCost2 = 10;
		itemCost3 = 5;
		itemCost4 = 27;
		itemCost5 = 15;
	}
}

int Gamer::getItemCost(int item)
{
	if (item == 1)
	{
		return itemCost1;
	}
	if (item == 2)
	{
		return itemCost2;
	}
	if (item == 3)
	{
		return itemCost3;
	}
	if (item == 4)
	{
		return itemCost4;
	}
	if (item == 5)
	{
		return itemCost5;
	}
}

int Gamer::getGamerAttack()
{
	return gamerAttack;
}

int Gamer::getCurrentHp()
{
	return gamerHP;
}

int Gamer::getCritChance()
{
	return critChance;
}

void Gamer::takeGold(int gold)
{
	gamerGold = gamerGold + gold;
}

void Gamer::wonGame()
{
	cout << "           --------------------" << endl;

		cout << "THE ELDER DRAGON IS SLAIN!" << endl;
		cout << "YOU HAVE BEATEN THE GAME!" << endl;

	cout << "           --------------------" << endl;
}

bool Gamer::takeDamage(int attack)
{	
	gamerHP = gamerHP - attack ;
	bool death;
	if (gamerHP <= 0)
	{
		death=true;
		cout << "		You have died!" << endl;
		cout << "		Your adventure is over, you must run the program again to start a new!" << endl;
	}
	else
		death = false;
	return death;
}

void Gamer::levelUp()
{	
	gamerMaxHP = gamerMaxHP+3;
	gamerAttack = gamerAttack + 2;
	gamerHP = gamerMaxHP;
	gamerEXP = 0;
	gamerMaxEXP = gamerMaxEXP+10;
	gamerGold++;
	gamerLVL++;
	cout <<" HP + 3"<<"\n"
		 <<" Attack + 2"<<"\n"
		 <<" Level: "<<gamerLVL<<"\n"
		 <<" You have been completely healed!"<<endl;
}

//void Gamer::hpUP(int val)
//{
//}

//void Gamer::setMaxHP(int val)
//{
//}

void Gamer::expUP(int val)
{
	gamerEXP = gamerEXP + val;
	if (gamerEXP >= gamerMaxEXP) 
	{
		cout << " You leveled up! " << endl;
		levelUp();
	}
}

void Gamer::displayStats()
{
	cout << gamerName << "'s stats" << "\n"
		<< " HP: " << gamerHP <<"/"<< gamerMaxHP << "\n"
		<< " Attack: " << gamerAttack << "\n"
		<< " Level: " << gamerLVL << "\n" 
		<< " Gold: "<< gamerGold<<"\n"
		<< " CritRoll: " << critChance << "\n"
		<< " Exp: "<< gamerEXP<<"/"<< gamerMaxEXP<< endl;
}

bool Gamer::gamerShop(int itemChoice)
{
	if (itemChoice==1)
	{
		if (itemCost1 > gamerGold) {
			cout << " You don't have enought gold!" << endl;
			cout << "\n";
			return true;
		}
		else {
			gamerAttack = gamerAttack + 3;
			cout << " You bought the Orb of might!" << endl;
			gamerGold = gamerGold - itemCost1;
			itemCost1=itemCost1+5;
			return false;

		}
	}
	else if (itemChoice == 2)
	{
		if (itemCost2 > gamerGold) {
			cout << " You don't have enought gold!" << endl;
			cout << "\n";
			return true;
		}
		else {
			gamerMaxHP = gamerMaxHP + 4;
			cout << " You bought the Orb of the giant!" << endl;
			gamerGold = gamerGold - itemCost2;
			itemCost2 = itemCost2 + 5;
			return false;
		}
	}
	else if (itemChoice == 3)
	{
		
		if (itemCost3 > gamerGold) {
			cout << " You don't have enought gold!" << endl;
			cout << "\n";
			return true;
		}
		else {
			gamerHP = gamerHP + 5;
			gamerGold = gamerGold - itemCost3;
			cout << " You bought the Druid blessing!" << endl;
			return false;
		}
	}
	else if (itemChoice == 4)
	{
		
		if (itemCost4 > gamerGold) {
			cout << " You don't have enought gold!" << endl;
			cout << "\n";
			return true;
		}
		else {
			critChance++;
			gamerGold = gamerGold - itemCost4;
			cout << " You bought the Cloack of luck!" << endl;
			itemCost4 = itemCost4 + 10;
			return false;
		}
	}
	else if (itemChoice == 5)
	{

		if (itemCost5 > gamerGold)
		{
			cout << " You don't have enought gold!" << endl;
			cout << "\n";
			return true;
		}
		else
		{
			gamerHP = gamerHP + 20;
			cout << " You bought the Paladin's light!" << endl;
			gamerGold = gamerGold - itemCost5;

			return false;
		}
	}
	else if (itemChoice == 6)
		{
			return false;
		}
	else {
			cout << "THAT'S NOT A VALID OPTION FOOL!";
	}

}

///void Gamer::battleEnd()
//{
//}

//EnemyFunctions


Enemy::Enemy()
{
	//cout << "Null" << endl;
	enemyName="Null";
	enemyMaxHP=0;
	enemyDropExp=0;
	enemyAttack=0;
	enemyHP = 0;
}

Enemy::Enemy(string name)
{
	enemyName=name;
	if (enemyName=="Slime")
	{
		enemyMaxHP=10;
		enemyDropExp=10;
		enemyAttack=4;
		enemyHP = enemyMaxHP;
		enemyGold = 5;
	}
	if (enemyName =="Skeleton")
	{
		enemyMaxHP=20;
		enemyDropExp=15;
		enemyAttack=9;
		enemyHP = enemyMaxHP;
		enemyGold = 10;
	}
	if (enemyName =="Dragon")
	{
		enemyMaxHP=35;
		enemyDropExp = 40;
		enemyAttack=12;
		enemyHP = enemyMaxHP;
		enemyGold = 25;
	}
	if (enemyName == "Elder Dragon") 
	{
		enemyMaxHP = 150;
		enemyDropExp = 100;
		enemyAttack = 20;
		enemyHP = enemyMaxHP;
		enemyGold = 1000;

	}
	
}

string Enemy::getEnemyName()
{
	//cout << enemyName << endl;
	return enemyName;
}

int Enemy::getEnemyAttack()
{
    return enemyAttack;
}

int Enemy::getEnemyDropExp()
{
    return enemyDropExp;
}

int Enemy::getEnemyHP()
{
    return enemyHP;
}

int Enemy::getEnemyMaxHP()
{
	return enemyMaxHP;
}

int Enemy::getEnemyGold()
{
	return enemyGold;
}

void Enemy::takeDamage(int attack)
{
	enemyHP = enemyHP - attack;
}

void Enemy::displayEnemyStats()
{
	cout << enemyName << "'s stats" << "\n"
		<< " HP: " << enemyHP<< "/" <<enemyMaxHP << "\n"
		<< " Attack: " << enemyAttack << "\n"
		<< " Gold drop: " << enemyGold << "\n"
		<< " Exp drop: " << enemyDropExp<< endl;
	if (enemyName=="Elder Dragon")
	{
		cout << " Beware, the Elder Dragon has a chance to crit for double damage!" << endl;
	}
}
