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
	Player p1;
	Player p2;
	String namePlayer1;
	String namePlayer2;
	int pointsCrabs;
	int pointsOctopus;
	int pointsSquids;
	int pointsShips;
	AbstractFactory abstractFactory = FactoryProvider.getFactory("Enemie");
     
    
	public Game(String player1, String player2, int pointsCrabs, int pointsOctopus, int pointsSquids, int pointsShips) {
		super();
		this.namePlayer1 = player1;
		this.namePlayer2 = player2;
		this.pointsCrabs = pointsCrabs;
		this.pointsOctopus = pointsOctopus;
		this.pointsSquids = pointsSquids;
		this.pointsShips = pointsShips;
	}

	public void createEnemies() {
		ArrayList<String> enemiesName = new ArrayList<String>();
		enemiesName.add("Crab");
		enemiesName.add("Squid");
		enemiesName.add("Octopus");
		int index = (int)(Math.random() * enemiesName.size());
		String e = enemiesName.get(index);
		if ( e == "Crab") {
			crabList.add((Enemie) abstractFactory.create("Crab", pointsCrabs, crabList.size()+1)); 			
		}else if (e == "Squid"){
			squidList.add((Enemie) abstractFactory.create("Squid", pointsSquids, squidList.size()+1));
		}else if ( e == "Octopus"){
			OctopusList.add((Enemie) abstractFactory.create("Octopus", pointsOctopus, OctopusList.size()+1));
		}else {
			return;
		}
	}
	
	public void createShields() {
		int id = shieldList.size()+1;
		Shield shield = new Shield(id);
		shieldList.add(shield);
	}
	 
	public void createPlayers() {
		if(p1 == null) {
			p1 = new Player(3, namePlayer1, 1);			
		}else {
			p2 = new Player(3, namePlayer2, 2);
		}
	}
	
	public void enemiesShoting() {
		System.out.println("Estos son disparos");
		crabList.forEach((e) -> e.shoting());
		squidList.forEach((e) -> e.shoting());
		OctopusList.forEach((e) -> e.shoting());

	}
	
}
