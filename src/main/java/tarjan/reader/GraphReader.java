package tarjan.reader;


import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;
import java.net.URL;

public class GraphReader {

    public static GraphConfig readFile(String fileName) {
        URL filePath = ClassLoader.getSystemClassLoader().getResource(fileName);
        try {
            return new ObjectMapper().readValue(filePath, GraphConfig.class);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
