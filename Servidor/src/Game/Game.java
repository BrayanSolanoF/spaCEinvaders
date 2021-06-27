package Game;

import java.util.ArrayList;

import EnemiesPackage.Enemie;
import Factory.AbstractFactory;
import Factory.FactoryProvider;

public class Game {
	
	ArrayList<Enemie> crabList = new ArrayList<Enemie>();
	ArrayList<Enemie> OctopusList = new ArrayList<Enemie>();
	ArrayList<Enemie> squidList = new ArrayList<Enemie>();
	ArrayList<Enemie> shipList;
	ArrayList<Shield> shieldList = new ArrayList<Shield>();
	String player1;
	String player2;
	int pointsCrabs;
	int pointsOctopus;
	int pointsSquids;
	int pointsShips;
	AbstractFactory abstractFactory = FactoryProvider.getFactory("Enemie");
     
    
	public Game(String player1, String player2, int pointsCrabs, int pointsOctopus, int pointsSquids, int pointsShips) {
		super();
		this.player1 = player1;
		this.player2 = player2;
		this.pointsCrabs = pointsCrabs;
		this.pointsOctopus = pointsOctopus;
		this.pointsSquids = pointsSquids;
		this.pointsShips = pointsShips;
	}

	public void createEnemies() {
		for (int i = 0; i < 22; i++) {
			if ( i < 7) {
				crabList.add((Enemie) abstractFactory.create("Crab", pointsCrabs, i+1)); 			
			}else if ( i >= 7 & i < 15){
				squidList.add((Enemie) abstractFactory.create("Squid", pointsSquids, i-7));
			}else if ( i >= 15 & i < 22){
				OctopusList.add((Enemie) abstractFactory.create("Octopus", pointsOctopus, i-14));
			}
		}
		System.out.println("Done");
	}
	
	public void createShields() {
		for (int i = 0; i < 4; i++) {
			shieldList.add(new Shield(6));
		}
	}
	 
	public void createPlayers() {
		Player p1 = new Player(3, player1, 1);
		Player p2 = new Player(3, player2, 2);
	}
	
	public void enemiesShoting() {
		System.out.println("Estos son disparos");
		crabList.forEach((e) -> e.shoting());
		squidList.forEach((e) -> e.shoting());
		OctopusList.forEach((e) -> e.shoting());

	}
	
}
