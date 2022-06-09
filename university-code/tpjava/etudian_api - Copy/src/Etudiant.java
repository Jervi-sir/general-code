import java.io.Serializable;
//import java.util.Comparator;

public class Etudiant implements Serializable, Comparable<Etudiant> {
  String nom;
  String specialite;
  int moy;
  Etudiant() {
    
  }
  Etudiant(String nom, String specialite, int moy) {
    super();
    this.nom = nom;
    this.specialite = specialite;
    this.moy = moy;
  }
  String getNom() {
    return nom;
  }
  String getSpeciality() {
    return specialite;
  }
  int getMoy() {
    return moy;
  }

  public String toString() {
    return "Etudiant : " + nom + " " + specialite + " : " + moy;
  }

  public int compareTo(Etudiant e)
  {
      //return this.moy - e.getMoy(); //for Ascendant
      return e.getMoy() - this.moy; //for decendanat
  }

}