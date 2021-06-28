package Game;

import EnemiesPackage.Enemie;
import Factory.AbstractFactory;
import Factory.FactoryProvider;
import Sockets.Server;

public class Main {

	public static void main(String[] args) {

				
		Game game = new Game("Fatima", "Carmen", 25, 50, 75, 100);
		game.flagGame = true;
		game.createEnemies();
		game.createPlayers();
		game.createShields();
		game.enemiesShoting();
		
        Server s = new Server();
        s.escuchar(7000);

	}
}
