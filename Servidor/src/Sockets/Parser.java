package Sockets;

import java.util.ArrayList;

import EnemiesPackage.Enemie;
import Game.Game;

public class Parser {
	
	Game game;
	
	public void doSomething(String message) {
		//System.out.println(message);
		String[] tokens = message.split(";");
		if(tokens[0] == "NuevoJuego") {
			newGame();
		}else if (tokens[0] == "eliminaEnemigo") {
			game.deleteEnemies();
		}else if (tokens[0] == "eliminaMuro") {
			game.deleteShield();
		}else if(tokens[0] == "jugadorPierdeVida") {
			game.playerLessLive();
		}
	}
	
	public void newGame() {
		game = new Game("Fatima", 25, 50, 75, 100);
		game.createEnemies();
		game.createPlayers();
		game.createShields();
	}
	

}
