package Factory;

public class FactoryProvider {
	
    public static AbstractFactory getFactory(String choice){
        
        if("Enemie".equalsIgnoreCase(choice)){
            return new EnemieFactory();
        }
        return null;
    }

}
