import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

class Server {
    private final static int port = 8081;
    private ServerSocket serverSocket ;
    private Map<String,Socket> socketList ;
    public Server() throws Exception {
        //先连接端口号码
        serverSocket = new ServerSocket(this.port);
        socketList = new HashMap<>();
        while (true){
            //开始接受请求
            Socket socket = serverSocket.accept();
            //开启新线程获取请求动作
            new ServerThread(socket).start();
        }

    }
    private class ServerThread extends Thread{
        private BufferedReader in;
        private PrintWriter out;
        private Socket socket;
        private String clientName;
        //构造传参
        public ServerThread(Socket client)throws Exception{
            this.socket = client;
            in = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
            out = new PrintWriter(this.socket.getOutputStream(),true);
            out.println("你已经连接上服务器！请输入你的用户名：\n");

        }
        public void run(){
            try {
                int flag = 0;
                String fromClientData = null;
                String userName = null;
                while((fromClientData = in.readLine())!=null){
                    //该客户端请求关闭服务器
                    if("exit".equals(fromClientData)){
                        //关闭的函数；
                        exitLine(userName);
                        break;
                    }
                    if(flag++ == 0){
                        this.clientName = fromClientData;
                        socketList.put(this.clientName,this.socket);
                        sendToAllClient("欢迎"+this.clientName+"进入聊天室\n");
                        Server.this.showUserList();
                        continue;
                    }
                    if(fromClientData.startsWith("@")){
                        String receiverName = fromClientData.substring(1,fromClientData.indexOf(":"));
                        String mes = fromClientData.substring(fromClientData.indexOf(":")+1,fromClientData.length());
                        sendToUser(this.clientName,receiverName,mes);
                    }else {
                        sendToAllClient(this.clientName + "说："+ fromClientData);
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }

        }


    }

    private synchronized void showUserList(){
        System.out.println("\n—————用户列表—————\n");
        System.out.println("在线人数有"+socketList.size()+"位\n");
        for (Map.Entry<String,Socket> user:socketList.entrySet()){
            System.out.println("----"+user.getKey());
        }
    }
    private synchronized void sendToAllClient(String mes) throws IOException {
        for(Map.Entry<String,Socket> user:socketList.entrySet()){
            PrintWriter out = new PrintWriter(user.getValue().getOutputStream(),true);
            out.println(mes);
        }
    }
    //肯定要有发送者，接受者，发送信息的
    private synchronized void sendToUser(String sendSocket,String receiverSocket,String mes) throws IOException {
        PrintWriter out = new PrintWriter(socketList.get(receiverSocket).getOutputStream(),true);
        out.println(sendSocket+"对你说"+mes);
    }
    private synchronized void exitLine(String userName) throws IOException {
        socketList.remove(userName);
        if(userName == null){
            sendToAllClient(userName+"已经下线！");
            Server.this.showUserList();

        }
    }

    public static void main(String[] args) throws Exception {
        new Server();
    }
}
