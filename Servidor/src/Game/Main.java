package Game;

import EnemiesPackage.Enemie;
import Factory.AbstractFactory;
import Factory.FactoryProvider;
import Sockets.Conector;

public class Main {

	public static void main(String[] args) {
		/* AbstractFactory abstractFactory;
	        
	     abstractFactory = FactoryProvider.getFactory("Enemie");
	     Enemie enemie1 = (Enemie) abstractFactory.create("Crab", 0, 0);
	     Enemie enemie2 = (Enemie) abstractFactory.create("Octopus", 0, 0);
	     Enemie enemie3 = (Enemie) abstractFactory.create("Squid", 0, 0);
	     
	     enemie1.shoting();
	     enemie2.shoting();
	     enemie3.shoting();*/
		
		
		Game game = new Game("Fatima", "Carmen", 25, 50, 75, 100);
		game.createEnemies();
		game.createPlayers();
		game.createShields();
		game.enemiesShoting();
		
	
	}

}
