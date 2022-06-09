import java.io.*;
import java.net.*;
import java.util.Scanner;


public class ClientEtudiant {
    public static void main(String[] args) throws IOException {
        String hostName = "localhost";
        //String NomEtudiant = "GL";
        Socket sock = null;
        
        PrintWriter sockOut = null;
        ObjectInputStream sockIn = null;
        try {
            sock = new Socket(hostName, 7777);
            sockOut = new PrintWriter(sock.getOutputStream(), true);
            sockIn = new ObjectInputStream(sock.getInputStream());
        } catch (UnknownHostException e) {
            System.err.println("host non atteignable :"+hostName); System.exit(1); 
        } catch (IOException e) {
            System.err.println("connection impossible avec : " + hostName);
            System.exit(1);
        }

        //CLient input
        System.out.println("/*-----------------------*/");
        System.out.println("Selectioner une options");
        System.out.println("-> taper 'trier' pour recevoir un tableau trie");
        System.out.println("-> taper un numeau entre 1 et 19 pour recevoir un tableau des moyenne superieur");
        System.out.println("-> taper un nom de specialite pour recevoir les etudiants de cette specialite");
        System.out.println("choisissez votre option");
        Scanner scan = new Scanner(System.in);
        String request = scan.next();
        scan.close();

        sockOut.println(request); // envoyer le nom au serveur
        try {
            Object recu = sockIn.readObject(); // récupérer l’objet Etudiant envoyé par le serveur
            if (recu == null) System.out.println("erreur de connection");
            else {
                Etudiant[] etudiant = (Etudiant[]) recu;
                for(int i = 0; i < etudiant.length; i++) {
                    System.out.println("serveur -> client : " + etudiant[i]);
                }
            }
        } catch (ClassNotFoundException e) {
            System.err.println("Classe inconnue : " + hostName);
            System.exit(1);
        }
        sockOut.close(); sockIn.close(); sock.close();
    }
}