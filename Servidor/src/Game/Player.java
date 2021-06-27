package Game;

public class Player {

	private int Lives;
	private String Name;
	private int id;
	
	
	public Player(int lives, String name, int id) {
		Lives = lives;
		Name = name;
		this.id = id;
	}
	
	public int getLives() {
		return Lives;
	}
	public void setLives(int lives) {
		Lives = lives;
	}
	public String getName() {
		return Name;
	}
	public void setName(String name) {
		Name = name;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	
	public void shooting() {
		System.out.println("Esto es un disparo del jugador");
	}
	
}
