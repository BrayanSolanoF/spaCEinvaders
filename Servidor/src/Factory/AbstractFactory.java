package Factory;

import EnemiesPackage.Enemie;

public interface AbstractFactory {
	

	Enemie create(String EnemieType, int points, int Id);

}
