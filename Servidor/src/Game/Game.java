package Game;

import java.util.ArrayList;

import EnemiesPackage.Crab;
import EnemiesPackage.Enemie;
import Factory.AbstractFactory;
import Factory.FactoryProvider;

public class Game {
	
	ArrayList<Enemie> enemiesList = new ArrayList<Enemie>();
	ArrayList<Shield> shieldList = new ArrayList<Shield>();
	Player p1;
	String namePlayer1;
	int pointsCrabs;
	int pointsOctopus;
	int pointsSquids;
	int squids = 4;
	int crabs = 4;
	int octopus = 4;
	Boolean flagGame = true;
	AbstractFactory abstractFactory = FactoryProvider.getFactory("Enemie");
     
	public Game(String player1, int pointsCrabs, int pointsOctopus, int pointsSquids, int pointsShips) {

		
		super();
		this.namePlayer1 = player1;
		this.pointsCrabs = pointsCrabs;
		this.pointsOctopus = pointsOctopus;
		this.pointsSquids = pointsSquids;
	}

	public void createEnemies() {
		enemiesList.add((Enemie) abstractFactory.create("Crab", pointsCrabs, 1));
		enemiesList.add((Enemie) abstractFactory.create("Crab", pointsCrabs, 2));
		enemiesList.add((Enemie) abstractFactory.create("Crab", pointsCrabs, 3));
		enemiesList.add((Enemie) abstractFactory.create("Squid", pointsSquids, 4));
		enemiesList.add((Enemie) abstractFactory.create("Squid", pointsSquids, 5));
		enemiesList.add((Enemie) abstractFactory.create("Squid", pointsSquids, 6));
		enemiesList.add((Enemie) abstractFactory.create("Squid", pointsSquids, 7));
		enemiesList.add((Enemie) abstractFactory.create("Octopus", pointsOctopus, 8));
		enemiesList.add((Enemie) abstractFactory.create("Octopus", pointsOctopus, 9));
		enemiesList.add((Enemie) abstractFactory.create("Octopus", pointsOctopus, 10));
	}
	
	public void createShields() {
		Shield shield1 = new Shield(1);
		Shield shield2 = new Shield(2);
		Shield shield3 = new Shield(3);
		shieldList.add(shield1);
		shieldList.add(shield2);
		shieldList.add(shield3);
		
	}
	 
	public void createPlayers() {
		p1 = new Player(3, namePlayer1, 1);			
	}
	
	
	public void deleteEnemies() {
		int index = (int)(Math.random() * enemiesList.size());
		int posi = crabs + squids + octopus;
		if (index < 4) {
			int p = p1.getPuntuation() + pointsCrabs;
			p1.setPuntuation(p);
			System.out.println("Puntuación del jugador: "+p1.getPuntuation());
		} else if (index >= 8) {
			int p = p1.getPuntuation() + pointsOctopus;
			p1.setPuntuation(p);
			System.out.println("Puntuación del jugador: "+p1.getPuntuation());
		}else if(index > 3 && index < 8){
			int p = p1.getPuntuation() + pointsSquids;
			p1.setPuntuation(p);
			System.out.println("Puntuación del jugador: "+p1.getPuntuation());
		}	
	}
	
	public void deleteShield() {
		if (shieldList.size() != 0) {
			shieldList.remove(0);
		}else {
			System.out.println("Se eliminaron todos los escudos");
		}
	}
	
	public void playerLessLive() {
		if (p1.getLives() == 0) {
			System.out.println("El jugador ha perdido el juego");
			flagGame = false;
		}else {
			p1.setLives(p1.getLives()-1);
		}
	}

}
