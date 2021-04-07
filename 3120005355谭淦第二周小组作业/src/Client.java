import com.sun.java.swing.plaf.windows.WindowsTabbedPaneUI;
import org.omg.CORBA.PRIVATE_MEMBER;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    private String IPAdress = "127.0.0.1";
    private int port = 8081;
    private PrintWriter out;
    private BufferedReader in;
    private Socket socket;
    public Client () throws  Exception {
        //连接服务器
        socket = new Socket(IPAdress,port);
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintWriter(socket.getOutputStream(),true);
        //开启新县城
        new ClientThread().start();

        while (true){
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String input = br.readLine();
            out.println(input);
            if(input.equals("exit")){
                out.close();
                in.close();
                socket.close();
                System.exit(0);
            }
        }
    }
    private class ClientThread extends Thread{
        public void run(){
            String fromServerData;
                try {
                    while (((fromServerData= in.readLine())!=null)) {
                        System.out.println(fromServerData);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
    }

    public static void main(String[] args) throws Exception {
        new Client();

    }
}
