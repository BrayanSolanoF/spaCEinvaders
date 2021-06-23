package Factory;

import EnemiesPackage.Enemie;

public interface AbstractFactory {
	

	Enemie create(String EnemieType, int posX, int posY, String image, int points);

}
