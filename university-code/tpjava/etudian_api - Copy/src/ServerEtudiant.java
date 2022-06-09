import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class ServerEtudiant {
    public static void main(String args[]) {
        Etudiant[] tabEtudiant = {
            new Etudiant("A", "GL", 13),
            new Etudiant("B", "RID", 12),
            new Etudiant("C", "SI", 14),

            new Etudiant("D", "GL", 16),
            new Etudiant("E", "RID", 10),
            new Etudiant("F", "SI", 7),

            new Etudiant("G", "GL", 11),
            new Etudiant("H", "RID", 2),
            new Etudiant("I", "SI", 9),
        };
        ServerSocket server = null;
        try {
            server = new ServerSocket(7777);
            while (true) {
                Socket sock = server.accept();
                System.out.println("connecte");
                ObjectOutputStream sockOut = new ObjectOutputStream(sock.getOutputStream());
                BufferedReader sockIn = new BufferedReader(new InputStreamReader(sock.getInputStream()));
                String recu;
                
                while ((recu = sockIn.readLine()) != null) {
                    System.out.println("recu :" + recu);

                    //verify nature of ClientInput
                    if(recu.equals("trier")) {
                        sockOut.writeObject(sortEtudiants( tabEtudiant));
                    }
                    else if(isNumber(recu)) {
                        sockOut.writeObject(getSupMoyEtudiants(recu, tabEtudiant));
                    }
                    else { //means client is searching by Speciality
                        sockOut.writeObject(getBySpeciality(recu, tabEtudiant));
                    }
                     
                        
                }
            sockOut.close();
            sock.close();
        }
        } catch (IOException e) {
        try {
            server.close();
        } catch (IOException e2) {}
        }
    }
    


    public static Etudiant getByName(String nameKeyword, Etudiant[] tabEtudiants) {
        String name = nameKeyword.trim();
        for (int i = 0; i < tabEtudiants.length; i++) {
            if (tabEtudiants[i].getNom().equals(name)) {
                return tabEtudiants[i];
            }
        }
        return null;
    }

    public static Etudiant[] getBySpeciality(String specialityKeyword, Etudiant[] tabEtudiants ) {
        String speciality = specialityKeyword.trim();
        //Etudiant[] results = new Etudiant[tabEtudiants.length];
        //since java doesn't support dynamic array of Object, except for List
        //create list
        List<Etudiant> etudiants = new ArrayList<>();
        //save result into list
        for (int i = 0; i < tabEtudiants.length; i++) {
            if(tabEtudiants[i].getSpeciality().equals(speciality)) {
                etudiants.add(tabEtudiants[i]);
            }
        }
        //convert list to object
        Etudiant[] results = new Etudiant[etudiants.size()];
        for(int i = 0; i < etudiants.size(); i++) {
            results[i] = etudiants.get(i);
        }

        if(results.length != 0) {
            return results;
        }
        return null;
    }

    public static Etudiant[] getSupMoyEtudiants(String moy, Etudiant[] tabEtudiants) {
        int moyenne = Integer.parseInt(moy);
        List<Etudiant> etudiants = new ArrayList<>();
        for (int i = 0; i < tabEtudiants.length; i++) {
            if(tabEtudiants[i].getMoy() > moyenne) {
                etudiants.add(tabEtudiants[i]);
            }
        }

        //convert list to object
        Etudiant[] results = new Etudiant[etudiants.size()];
        for(int i = 0; i < etudiants.size(); i++) {
            results[i] = etudiants.get(i);
        }

        if(results.length != 0) {
            return results;
        }
        return null;
    }

    public static Etudiant[] sortEtudiants(Etudiant[] tabEtudiants) {
        Arrays.sort(tabEtudiants);
        return tabEtudiants;
    }

    public static boolean isNumber(String s){
        try{
            Integer.parseInt(s);
            return true;
        }catch (Exception e){
            return false;
        }
    }
} 