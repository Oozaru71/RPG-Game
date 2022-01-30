#include "OrgClasses.h"
#include <ctime>
#include<limits>
#include <Windows.h>

int main()
{
	srand(time(NULL));
	cout << "\n" << endl;
	cout << "                Welcome to my tavern traveler! My name is Peter and I will be your guide." << endl;
	cout << "                Would you like to know your mission? Y/N " << endl;
	string mission;
	cin >> mission;
	bool missionCheck=false;
	do {
		if (mission == "Y" || mission == "Yes" || mission == "yes" || mission == "YES" || mission == "y")
		{
			cout << "		You are about to embark on a dangerous journey. Your goal is to kill the Elder Dragon." << "\n"
				<< "		Legends say that the Elder Dragon is the guardian of the 5 elemental dragons..." << "\n"
				<< "		... perhaps slaying them will wake it from its slumber...." << endl;
			break;
		}
		else if (mission == "N" || mission == "NO" || mission == "no" || mission == "n" || mission == "No")
			break;
		else
		{
			cout << "		Thats not a valid answer! Try again." << endl;
			cin >> mission;
		}
	} while (missionCheck == false);


	cout << "                Would you like a quick tutorial? Y/N " << endl;
	string tuto;
	cin >> tuto;
	bool tutoCheck = false;
	do {
		if (tuto == "Y" || tuto == "Yes" || tuto == "yes" || tuto == "YES" || tuto == "y")
		{
			cout << "		You are will find three different types of enemies that you will encounter randomly in this world: Slimes, Skeletons, and Dragons" << "\n"
				<< "		Slimes are the weakest and Dragons are strongest, also if you meet a certain condition you will always encounter a legendary beast" << "\n"
				<< "		While in combat you may attack (keep in mind an enemy always attacks first), run (running has a small chance of failing)," << "\n"
				<< "		you may see your stats(and the enemy's), you may buy items from the shop (except for healing items, items will always go up in price eveytime you buy them)." << "\n"
				<< "		Your stats will go up and you will heal back up to max health when you level up, also performing a crititcal attack doubles your damage." << "\n"

				<< "		I hope this infomation will be helpful on your journey." << endl;
			break;
		}
		else if (tuto == "N" || tuto == "NO" || tuto == "no" || tuto == "n" || tuto == "No")
			break;
		else
		{
			cout << "		Thats not a valid answer! Try again." << endl;
			cin >> tuto;
		}
	} while (tutoCheck == false);
	
		cout <<"		Before you begin, tell me your name so I can spread your tale across the land! "<< endl;
	string x;
	//Enemy e2 = Enemy("Dragon");
	//cout << e2.getEnemyName() << endl;
	bool nameCheck=false;
	cin >> x;
	do
	{
		int check = 0;
		
		for (int i = 0; i < x.length(); i++)
		{
			if (!(isalpha(x[i])))
			{
				check++;
			}
		}
		if (check == 0) 
		{	
			break;
		}
		else
		{
			cout << "		Your name cannot have numbers or special characters!" << endl;
			cin >> x;
		}

	} while (nameCheck==false);
	Gamer p1 = Gamer(x);
	bool scene = true;
	int dragonKills = 0;
	int slimeCount=0;
	int skelyCount=0;
	int enemyCount = 0;
	bool lastEnemyDrag = false;
	while (scene == true)
	{
		cout << "		-------------------------------------------------------------------------------" << endl;
		cout << "		Get ready " << x << ", an enemy is nearby!" << endl;
		//int enemyChoice= (rand()%10)+1;
		bool enemyDecided=false;
	//	cout << "enemy "<<enemyChoice << endl;
		string k;
		while (enemyDecided==false) {
			int enemyChoice = (rand() % 10) + 1;
			//cout << "enemy " << enemyChoice << endl;
			if (dragonKills >= 5)
			{
				k = "Elder Dragon";
				enemyDecided = true;
			}
			else if ((enemyChoice >= 0 && enemyChoice <= 5) && (slimeCount < 3)&&enemyCount!=10)
			{
				slimeCount++;
				enemyCount++;
				skelyCount = 0;
				k = "Slime";
				//cout << "enemy " << enemyCount << endl;
				enemyDecided = true;
			}
			else if ((enemyChoice >= 6 && enemyChoice <= 8) && (skelyCount < 3)&&enemyCount!=10)
			{
				skelyCount++;
				enemyCount++;
				slimeCount = 0;
				k = "Skeleton";
				//cout << "enemy " << enemyCount << endl;
				enemyDecided = true;
			}
			else if ((enemyChoice > 8) && lastEnemyDrag == false||(enemyCount==10))
			{
				enemyCount=0;
				enemyCount++;
				skelyCount = 0;
				slimeCount = 0;
				k = "Dragon";
				//cout << "enemy " << enemyCount << endl;
				enemyDecided = true;
			}
			else
				enemyDecided = false;
		}
		Enemy e1 = Enemy(k);
		cout << "		A mighty "<< e1.getEnemyName() << " approaches!" << endl;
		cout << "		-------------------------------------------------------------------------------" << endl;
		bool battle = true;
		while (battle == true) {
			cout << "		What will you do? " << endl;
			cout << "		1) Attack    2)Run    3)See stats    4)Shop    5)Quit adventure" << endl;
			int choice;
			cin >> choice;
			
			int dodgeChance = (rand() % 4) + 1;
			int counter = 0;
			int critChance;
			while (counter!=p1.getCritChance())
			{	
				critChance = (rand() % 10) + 1;
				if (critChance==7)
				{
					break;
				}
				else
				counter++;
			}
			int enemyDodgeChance = (rand() % 20) + 1;
			bool shop = true;
			//cout << dodgeChance << endl;
			switch (choice) {
			case 1:
				if (e1.getEnemyHP() >= 0) {
					cout << "		The enemy attacks!" << endl;
					int attack = e1.getEnemyAttack();
					if (e1.getEnemyName() == "Elder Dragon") 
					{
						int dragonCrit = (rand() % 10) + 1;
						if (dragonCrit == 7)
						{
							attack=attack*2;
							cout << "		The Elder Dragon has crit!" << endl;
							cout << "		You took " << attack<< " point of damage! " << endl;
						}
					}
					else {
						cout << "		You took " << attack << " point of damage! " << endl;
					}
					if (p1.takeDamage(attack) == true) 
					{
						Sleep(5000);
						exit(0);
					}
					else
						cout << "		WOW! That look like it hurt!"<<"\n" << endl;
						
					if (enemyDodgeChance==10)
					{
						cout << "		The enemy has dodge your attack!" << endl;
						cout << "		You can hear it mock you in a strange language!" << endl;
						cout << "\n";
					}
					else {
						if (critChance == 7)
						{
							cout << "		You got a crit!  That means double damage!" << endl;
							cout << "		You deal " << p1.getGamerAttack() * 2 << " damage!" << endl;
							cout << "		Enemy has " << e1.getEnemyHP() - (p1.getGamerAttack() * 2) << "/" << e1.getEnemyMaxHP() << " hp left!" << endl;
							e1.takeDamage(p1.getGamerAttack() * 2);
							cout << "\n";
						}
						else
						{
							cout << "		You deal " << p1.getGamerAttack() << " damage!" << endl;
							cout << "		Enemy has " << e1.getEnemyHP() - p1.getGamerAttack() << "/" << e1.getEnemyMaxHP() << " hp left!" << endl;
							e1.takeDamage(p1.getGamerAttack());
							cout << "\n";
						}
					}

					
				}
				if(e1.getEnemyHP() <= 0)
				{
					cout << "		You have defeated the enemy!" << endl;
					cout << "		You gained "<< e1.getEnemyDropExp() <<" exp!" << endl;
					if (e1.getEnemyName() == "Dragon")
					{
						dragonKills++;
						lastEnemyDrag=true;
					}
					//else if (e1.getEnemyName() == "Slime")
						//slimeCount++;
					//else if (e1.getEnemyName() == "Skeleton")
						//skelyCount++;
					if (e1.getEnemyName() == "Elder Dragon") 
					{
						p1.wonGame();
						Sleep(5000);
						exit(0);

					}

					p1.takeGold(e1.getEnemyGold());
					p1.expUP(e1.getEnemyDropExp());
					battle = false;
				}
				
				break;
			case 2:
				
				if (dodgeChance<4)
				{
					cout << "		You ran from combat!" << endl;
					battle = false;
					break;
				}
				if (dodgeChance==4)
				{
					cout << "		You failed your dodge!The enemy threw an attack!" << endl;
					cout << "		You took " << e1.getEnemyAttack() << " point of damage! " << endl;
					if (p1.takeDamage(e1.getEnemyAttack()) == true) {
						Sleep(5000);
						exit(0);
					}
					else
						cout << "		WOW! That look like it hurt!" <<"\n" <<endl;

					break;
				}
				
			case 3:
				cout << "\n";
				p1.displayStats();
				cout << "\n";
				e1.displayEnemyStats();
				break;
			case 4:
				
				while (shop == true)
				{
					cout << "		What would you like to buy?" << "\n"
						<< "		1) Orb of might  (Attack +3)   " << p1.getItemCost(1)<<"g" << "\n"
						<< "		2) Orb of the giant  (Max HP +4)   " << p1.getItemCost(2) << "g" << "\n"
						<< "		3) Druid blessing  (Heal +5)   " << p1.getItemCost(3) << "g" << "\n"
						<< "		4) Cloack of luck  (CritRoll +1)   " << p1.getItemCost(4) << "g" << "\n"
						<< "		5) Paladin's light  (Heal +20)   " << p1.getItemCost(5) << "g" << "\n"
						<< "		6) Return to action menu" << endl;
					int y;
					cin >> y;
					shop=p1.gamerShop(y);
				}
				break;
			case 5:
				cout << "Goodbye " << x << ", I hope you enjoyed your adventure!" << endl;
				Sleep(5000);
				exit(0);

			default:
				cout << "			THAT'S NOT A VALID OPTION FOOL!" << endl;
				break;
			}
		}
	}
	
	return 0;
}