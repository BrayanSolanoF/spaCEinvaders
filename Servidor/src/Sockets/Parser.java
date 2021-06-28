package Sockets;

import java.util.ArrayList;

import EnemiesPackage.Enemie;
import Game.Game;

public class Parser {
	
	Game game;

	/**
	 * Ejecuta una accion segun sea la peticion del cliente
	 * @param message
	 */
	public void doSomething(String message) {
		//System.out.println(message);

		String[] tokens = message.split(";");
		System.out.println(tokens[0]);
		String temp = tokens[0];
		int n = Integer.parseInt(temp);
		if(n == 1) {
			newGame();
			System.out.println("Se ha creado un nuevo juego");
		}else if (n == 2) {
			game.deleteEnemies();
			System.out.println("Se ha eliminado un enemigo");
		}else if (n == 3) {
			game.deleteShield();
			System.out.println("se ha eliminado un muro");
		}else if(n == 4) {
			game.playerLessLive();
			System.out.println("Jugador ha perdido una vida");

		}
	}

	/**
	 * Crea una nueva partida
	 */
	public void newGame() {
		game = new Game("Fatima", 25, 50, 75, 100);
		game.createEnemies();
		game.createPlayers();
		game.createShields();
	}
	

}
