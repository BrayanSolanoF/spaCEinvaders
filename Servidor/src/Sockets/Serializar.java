package Sockets;

import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.IOException;

public class Serializar {
	
	public static String serializeKremlin(Kremlin kremlin) throws IOException {
        ObjectMapper kremlinMapper = new ObjectMapper();
        return kremlinMapper.writeValueAsString(kremlin);

    }

    /**
     * Serializa un kremlin
     * @param fruit
     * @return
     * @throws IOException
     */
    public static String serializeFruit(Fruit fruit) throws IOException{
        ObjectMapper fruit_Mapper = new ObjectMapper();
        return fruit_Mapper.writeValueAsString(fruit);
    }

}
