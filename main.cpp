/******************************************************************************

⠀⠀⠀⠀⠀⠀⠀⢀⠀⠔⡀⠀⢀⠞⢰⠂⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⠘⢰⡃⠔⠩⠤⠦⠤⢀⡀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⠄⢒⠒⠺⠆⠈⠀⠀⢐⣂⠤⠄⡀⠯⠕⣒⣒⡀⠀
⠀⠀⢐⡡⠔⠁⠆⠀⠀⠀⠀⠀⢀⠠⠙⢆⠀⠈⢁⠋⠥⣀⣀
⠈⠉⠀⣰⠀⠀⠀⠀⡀⠀⢰⣆⢠⠠⢡⡀⢂⣗⣖⢝⡎⠉⠀
⢠⡴⠛⡇⠀⠐⠀⡄⣡⢇⠸⢸⢸⡇⠂⡝⠌⢷⢫⢮⡜⡀⠀
⠀⠀⢰⣜⠘⡀⢡⠰⠳⣎⢂⣟⡎⠘⣬⡕⣈⣼⠢⠹⡟⠇⠀
⠀⠠⢋⢿⢳⢼⣄⣆⣦⣱⣿⣿⣿⣷⠬⣿⣿⣿⣿⠑⠵⠀⠀
⠀⠀⠀⡜⢩⣯⢝⡀⠁⠀⠙⠛⠛⠃⠀⠈⠛⠛⡿⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣿⠢⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀
⠀⠀⠀⠀⢀⣀⡇⠀⠑⠀⠀⠀⠀⠐⢄⠄⢀⡼⠃⠀⠀⠀⠀
⠀⠀⠀⠀⢸⣿⣷⣤⣀⠈⠲⡤⣀⣀⠀⡰⠋⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣶⣤⣙⣷⣅⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣾⣿⣿⣿⣿⣻⢿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀
⠀⡠⠟⠁⠙⠟⠛⠛⢿⣿⣾⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>


int main() {

	int numeroLinha=0,numeroColuna=0, jogadaX=0, jogadaY=0;


	std::string matrizJogada[10][10];
	std::string matrizComBombas[10][10];

	unsigned seed = time(0);
	srand(seed);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrizJogada[i][j] = "- ";
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrizComBombas[i][j] = "- ";
		}
	}



	std::cout << "" << std::endl;

	bool jogouBomba = false;
	int jogadas=0;
	int numBombas=99;
	int bombas=0;

	std::cout << "Digite o numero de bombas que deseja" << std::endl;
	std::cin >> numBombas;
	

	while(bombas<numBombas) {
		numeroLinha = rand()%10;
		numeroColuna = rand()%10;

		if(matrizComBombas[numeroLinha][numeroColuna]!="O ") {
			matrizComBombas[numeroLinha][numeroColuna]="O ";
			bombas++;
		}
	}





	while(jogouBomba==false) {

		std::cout << "    " ;

		for(int k=0; k<10; k++) {
			std::cout << " " << k << "";
		}

		std::cout << "" << std::endl;

		for(int k=0; k<35; k++) {
			std::cout << "_";
		}

		std::cout << "" << std::endl;

		for (int i = 0; i < 10; i++) {
			std::cout << ""<< i << "|   ";
			for (int j = 0; j < 10; j++) {
				std::cout << matrizJogada[i][j];
			}
			std::cout << std::endl;
		}

		std::cout << "" << std::endl;
		


		std::cout << "Digite a posicao Y da sua jogada (de 0 a 9)" << std::endl;
		std::cin >> jogadaX;

		std::cout << "Digite a posicao X da sua jogada (de 0 a 9)" << std::endl;
		std::cin >> jogadaY;


		int bombasPerto=0;

		if(matrizComBombas[jogadaX][jogadaY]=="O ") {
			std::cout << "Voce clicou na bomba" << std::endl;
			jogouBomba=true;
		} else {
			if(matrizComBombas[jogadaX-1][jogadaY-1]=="O ") {
				bombasPerto++;
			}
			if(matrizComBombas[jogadaX-1][jogadaY]=="O ") {
				bombasPerto++;
			}
			if(matrizComBombas[jogadaX-1][jogadaY+1]=="O ") {
				bombasPerto++;
			}
			if(matrizComBombas[jogadaX][jogadaY-1]=="O ") {
				bombasPerto++;
			}
			if(matrizComBombas[jogadaX][jogadaY+1]=="O ") {
				bombasPerto++;
			}
			if(matrizComBombas[jogadaX+1][jogadaY-1]=="O ") {
				bombasPerto++;
			}
			if(matrizComBombas[jogadaX+1][jogadaY]=="O ") {
				bombasPerto++;
			}
			if(matrizComBombas[jogadaX+1][jogadaY+1]=="O ") {
				bombasPerto++;
			}

			if(matrizJogada[jogadaX][jogadaY]=="- ") {
				jogadas++;
			}

		}

		std::string bombasPertoString = std::to_string(bombasPerto) + " ";

		matrizJogada[jogadaX][jogadaY]=bombasPertoString;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				std::cout << matrizJogada[i][j];
			}
			std::cout << std::endl;
		}

		system("clear");

		if(jogadas==(100-numBombas)) {
			break;
		}

	}

	if(jogadas==(100-numBombas)) {
		std::cout << "Voce ganhou o jogo!" << std::endl;
		
	} else {
		std::cout << "Voce perdeu porque escolheu uma bomba!" << std::endl;

		std::cout << "    " ;

		for(int k=0; k<10; k++) {
			std::cout << " " << k << "";
		}

		std::cout << "" << std::endl;

		for(int k=0; k<35; k++) {
			std::cout << "_";
		}

		std::cout << "" << std::endl;

		for (int i = 0; i < 10; i++) {
			std::cout << ""<< i << "|   ";
			for (int j = 0; j < 10; j++) {
				std::cout << matrizComBombas[i][j];
			}
			std::cout << "" << std::endl;
		}
		
		std::cout << "" << std::endl;
		
		std::cout << "Voce jogou Y: " << jogadaY << std::endl;
		std::cout << "Voce jogou X: " << jogadaX << std::endl;
	}






	return 0;
}
